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

                    output.write(reinterpret_cast<char *>(&registro), sizeof(struct Registro));
                    output << endl;
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
    Registro registro;
    int reg = 0, cabecalho = 0;
    string newArquivo = nomeArquivo, id, line;

    newArquivo.replace(newArquivo.find(".csv"), 4, ".dat");
    ofstream output(newArquivo, ios::app);

    // Leitura do Teclado
    cin >> registro.type;
    cin >> registro.title;
    cin >> registro.country;
    cin >> registro.release_year;

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
                    reg++;
                }
            }
            else
            {
                cabecalho = 1;
            }
        }

        id = "s" + to_string(reg + 1);

        strcpy(registro.show_id, id.c_str());

        cout << registro.show_id;

        output.write(reinterpret_cast<char *>(&registro), sizeof(struct Registro));

        output.close();
    }
}
