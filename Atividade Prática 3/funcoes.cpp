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

// void Inserir(string nomeArquivo)
// {
//     Registro registro;
//     int reg = 0, cabecalho = 0;
//     string newArquivo = nomeArquivo, id, line;

//     newArquivo.replace(newArquivo.find(".csv"), 4, ".dat");
//     ofstream output(newArquivo, ios::app);

//     // Leitura do Teclado
//     cin >> registro.type;
//     cin >> registro.title;
//     cin >> registro.country;
//     cin >> registro.release_year;

//     if (output.is_open())
//     {
//         ifstream input(nomeArquivo);

//         while (!input.eof())
//         {
//             getline(input, line);

//             if (cabecalho == 1)
//             {
//                 if (line != "")
//                 {
//                     reg++;
//                 }
//             }
//             else
//             {
//                 cabecalho = 1;
//             }
//         }

//         id = "s" + to_string(reg + 1);

//         strcpy(registro.show_id, id.c_str());

//         cout << registro.show_id;

//         output.write(reinterpret_cast<char *>(&registro), sizeof(struct Registro));

//         output.close();
//     }
// }

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

            cout << "---> REGISTRO ENCONTRADO: " << endl;
            cout << "---> Show_Id: " << showId << endl;
            cout << "---> Type: " << type << endl;
            cout << "---> Title: " << title << endl;
            cout << "---> Contry: " << country << endl;
            cout << "---> Release Year: " << releaseYear << endl;
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