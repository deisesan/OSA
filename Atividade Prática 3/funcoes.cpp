#include "funcoes.h"

void Arquivo(string nomeArquivo)
{
    Registro registro;
    int cabecalho = 0, i = 0, j = 0;
    string newArquivo = nomeArquivo, line, maxCountry = "";
    ofstream output;

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
                    // output.write((char*)&registro.show_id,sizeof(registro.show_id));
                    ++i;

                    j = 0;

                    while (line[i] != ';')
                    {
                        registro.type[j] = line[i];
                        ++i;
                        ++j;
                    }
                    output.write((char *)&j, sizeof(int));
                    // output.write((char*)&registro.type,sizeof(registro.type));
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        registro.title[j] = line[i];
                        ++i;
                        ++j;
                    }
                    output.write((char *)&j, sizeof(int));
                    // output.write((char*)&registro.title,sizeof(registro.title));
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
                    // output.write((char*)&registro.country,sizeof(registro.country));
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
                    // output.write((char*)&registro.release_year,sizeof(registro.release_year));
                    ++i;
                    j = 0;

                    output.write((char *)&registro, sizeof(Registro));
                    registro.show_id[0] = '\0';
                    registro.type[0] = '\0';
                    registro.title[0] = '\0';
                    registro.release_year[0] = '\0';
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

void Inserir(string nomeArquivo)
{
    long int fim;
    fstream arquivo;
    Registro registro;
    string type, title, country, release_year;
    int size = 0;
    int intId;
    int tamShowId, tamType, tamTitle, tamCountry, tamReleaseYear;
    tamShowId = 0;
    tamType = 0;
    tamTitle = 0;
    tamCountry = 0;
    tamReleaseYear = 0;
    string id;
    arquivo.open(nomeArquivo, ios::out | ios::in | ios::binary);
    arquivo.seekg(0, ios::end);
    long int tamanhoArquivo = arquivo.tellg();

    int aux = (sizeof(int) * 5) + (sizeof(Registro));
    fim = (tamanhoArquivo / aux) - 1;

    arquivo.seekg(fim * aux, ios::beg);
    arquivo.read((char *)&tamShowId, sizeof(int));
    arquivo.read((char *)&tamType, sizeof(int));
    arquivo.read((char *)&tamTitle, sizeof(int));
    arquivo.read((char *)&tamCountry, sizeof(int));
    arquivo.read((char *)&tamReleaseYear, sizeof(int));
    arquivo.read((char *)&registro, sizeof(Registro));

    id.append(registro.show_id, 1, tamShowId);

    stringstream ss;
    ss << id;
    ss >> intId;

    // intId = atoi(id);
    id.clear();
    id = "s" + to_string(intId + 1);

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

    cout << "Show_Id: " << id << endl;
    cout << endl;

    strcpy(registro.show_id, id.c_str());
    strcpy(registro.type, type.c_str());
    strcpy(registro.title, title.c_str());
    strcpy(registro.country, country.c_str());
    strcpy(registro.release_year, release_year.c_str());

    size = id.size();
    arquivo.write((char *)&size, sizeof(int));

    size = type.size();
    arquivo.write((char *)&size, sizeof(int));

    size = title.size();
    arquivo.write((char *)&size, sizeof(int));

    size = country.size();
    arquivo.write((char *)&size, sizeof(int));

    size = release_year.size();
    arquivo.write((char *)&size, sizeof(int));

    arquivo.write((char *)&registro, sizeof(Registro));

    arquivo.close();
}

void buscaBinaria(string arquivoBinario, string chave)
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