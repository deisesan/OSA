#include "funcoes.h"

void Arquivo(string nomeArquivo, Buffer &buff)
{
    Registro registro;
    int cabecalho = 0, i = 0, j = 0, deleted = 1;
    string newArquivo = nomeArquivo, line, maxCountry = "";
    ofstream output;

    registro.InitBuffer(buff);

    newArquivo.replace(newArquivo.find(".csv"), 4, ".dat");
    output.open(newArquivo, ios::out | ios::binary);

    if (output.is_open())
    {
        ifstream input(nomeArquivo);

        while (!input.eof())
        {
            getline(input, line);

            if (cabecalho == 1)
            {
                if (line != "")
                {
                    output.write((char *)&deleted, sizeof(int));

                    while (line[i] != ';')
                    {
                        registro.show_id[j] = line[i];
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        registro.type[j] = line[i];
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        registro.title[j] = line[i];
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        registro.country[j] = line[i];
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        registro.release_year[j] = line[i];
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    registro.Pack(buff);
                    buff.Write(output);

                    registro.show_id[0] = '\0';
                    registro.type[0] = '\0';
                    registro.title[0] = '\0';
                    registro.country[0] = '\0';
                    registro.release_year[0] = '\0';
                }
            }
            else
            {
                cabecalho = 1;
            }

            i = 0;
            line.clear();
        }
    }

    output.close();
}

void Inserir(string nomeArquivo, Buffer &buff)
{
    fstream arquivo;
    ifstream input;
    ofstream input_excluidos;
    Registro registro;
    int newShowId, size, tam, pos = 0, deleted = 0, found = 0;
    string id, show_id, type, title, country, release_year;
    stringstream ss;

    arquivo.open(nomeArquivo, ios::out | ios::in | ios::binary);
    arquivo.seekg(0, ios::end);

    registro.UnPack(buff);

    id.append(registro.show_id, 1, (int)strlen(registro.show_id));
    ss << id;
    ss >> newShowId;

    show_id.clear();
    show_id = "s" + to_string(newShowId + 1);

    // Leitura do Teclado
    getchar();
    cout << endl;
    cout << "Type: ";
    getline(cin, type);
    cout << "Title: ";
    getline(cin, title);
    cout << "Country: ";
    getline(cin, country);
    cout << "Release year: ";
    getline(cin, release_year);

    strcpy(registro.show_id, show_id.c_str());
    strcpy(registro.type, type.c_str());
    strcpy(registro.title, title.c_str());
    strcpy(registro.country, country.c_str());
    strcpy(registro.release_year, release_year.c_str());

    input.open("netflix_excluidos.dat", ios::binary);
    input_excluidos.open("netflix_excluidos_temp.dat", ios::out | ios::binary);

    input.seekg(0, ios::end);
    size = input.tellg();

    arquivo.write((char *)&deleted, sizeof(int));
    registro.Pack(buff);

    if (size == 0)
    {
        buff.Write(arquivo);
    }
    else
    {
        input.seekg(0, ios::beg);

        while (!input.eof())
        {
            // Tamanho - Posição
            input.read((char *)&tam, sizeof(int));
            input.read((char *)&pos, sizeof(int));

            int tamBuff = buff.Size();

            if (tamBuff == tam)
            {
                arquivo.seekg(pos, ios::beg);

                buff.Write(arquivo);

                found = 1;
            }
            else
            {
                // Tamanho - Posição
                input_excluidos.write((char *)&tam, sizeof(int));
                input_excluidos.write((char *)&pos, sizeof(int));
            }
        }

        if (found == 0)
        {
            buff.Write(arquivo);
        }
    }

    arquivo.close();
    input.close();
    input_excluidos.close();

    remove("netflix_excluidos.dat");
    rename("netflix_excluidos_temp.dat", "netflix_excluidos.dat");
}

void IndexarExcluidos(string nomeArquivo)
{

    Buffer buffaux;
    Registro registro;
    ifstream input(nomeArquivo);
    ofstream output;
    int deleted, pos = 0;

    output.open("netflix_excluidos.dat", ios::out | ios::binary);

    if (output.is_open())
    {
        buffaux.Clear();

        while (!input.eof())
        {
            input.read((char *)&deleted, sizeof(int));

            buffaux.Read(input);

            if (registro.UnPack(buffaux))
            {
                if (deleted == 1)
                {
                    int tam = buffaux.Size();

                    // Tamanho - Posição
                    output.write((char *)&tam, sizeof(int));
                    output.write((char *)&pos, sizeof(int));
                }

                pos += buffaux.Size();
                pos += (sizeof(int) * 2);
                buffaux.Clear();
            }
        }
    }

    output.close();
    input.close();
}
