#include "funcoes.h"

void Arquivo(string nomeArquivo, Buffer &buff)
{
    Registro registro;
    int cabecalho = 0, i = 0, j = 0;
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
                    while (line[i] != ';')
                    {
                        registro.show_id[j] = line[i];
                        ++i;
                        ++j;
                    }
                    output.write((char *)&j, sizeof(int));
                    ++i;

                    j = 0;

                    while (line[i] != ';')
                    {
                        registro.type[j] = line[i];
                        ++i;
                        ++j;
                    }
                    output.write((char *)&j, sizeof(int));
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        registro.title[j] = line[i];
                        ++i;
                        ++j;
                    }
                    output.write((char *)&j, sizeof(int));
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
                    output.write((char *)&j, sizeof(int));
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
                    output.write((char *)&j, sizeof(int));
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
    Registro registro;
    int newShowId, size;
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

    size = show_id.size();
    arquivo.write((char *)&size, sizeof(int));

    size = type.size();
    arquivo.write((char *)&size, sizeof(int));

    size = title.size();
    arquivo.write((char *)&size, sizeof(int));

    size = country.size();
    arquivo.write((char *)&size, sizeof(int));

    size = release_year.size();
    arquivo.write((char *)&size, sizeof(int));

    registro.Pack(buff);
    buff.Write(arquivo);

    arquivo.close();
}

void BuscaBinaria(string arquivoBinario, string chave)
{
    bool find = false;
    long int inicio = 0, meio, fim;
    ifstream input;
    Registro registro;
    int tamShowId, tamType, tamTitle, tamCountry, tamReleaseYear, intId, intchave;
    string id, str, showId, type, title, country, releaseYear;

    input.open(arquivoBinario, ios::in | ios::binary);

    input.seekg(0, ios::end);
    long int tamanhoArquivo = input.tellg();

    int aux = (sizeof(int) * 5) + (sizeof(Registro));
    fim = (tamanhoArquivo / aux) - 1;

    str.append(chave, 1, chave.size());
    intchave = stoi(str);

    while (inicio <= fim)
    {
        tamShowId = 0;
        tamType = 0;
        tamTitle = 0;
        tamCountry = 0;
        tamReleaseYear = 0;

        meio = (fim + inicio) / 2;
        input.seekg((meio * aux), ios::beg);
        input.read((char *)&tamShowId, sizeof(int));
        input.read((char *)&tamType, sizeof(int));
        input.read((char *)&tamTitle, sizeof(int));
        input.read((char *)&tamCountry, sizeof(int));
        input.read((char *)&tamReleaseYear, sizeof(int));

        input.read((char *)&registro, sizeof(Registro));

        id.append(registro.show_id, 1, tamShowId);

        intId = stoi(id);

        if (intchave > intId)
        {

            inicio = meio + 1;
        }
        else if (intchave < intId)
        {

            fim = meio - 1;
        }
        else if (intchave == intId)
        {
            find = true;

            showId.append(registro.show_id, 0, tamShowId);
            type.append(registro.type, 0, tamType);
            title.append(registro.title, 0, tamTitle);
            country.append(registro.country, 0, tamCountry);
            releaseYear.append(registro.release_year, 0, tamReleaseYear);

            cout << endl;
            cout << "---> REGISTRO ENCONTRADO: " << endl;
            cout << "---> Show_Id: " << showId << endl;
            cout << "---> Type: " << type << endl;
            cout << "---> Title: " << title << endl;
            cout << "---> Contry: " << country << endl;
            cout << "---> Release Year: " << releaseYear << endl;
            cout << endl;
            break;
        }

        chave.clear();
        id.clear();
    }

    if (find == false)
    {
        cout << "---> REGISTRO NAO ENCONTRADO: " << endl;
    }
}