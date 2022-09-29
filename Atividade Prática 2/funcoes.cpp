#include "funcoes.h"

void Arquivo(string nomeArquivo)
{
    Netflix registro;
    string newArquivo = nomeArquivo;
    ofstream output;
    string line;
    int tam = 0;

    newArquivo.replace(newArquivo.find(".csv"), 4, ".dat");
    output.open(newArquivo, ios::out | ios::binary);

    if (output.is_open())
    {
        ifstream input(nomeArquivo);

        while (!input.eof())
        {
            getline(input, line);

            registro.split(line);

            tam = registro.size();
            output.write(reinterpret_cast<char *>(&tam), sizeof(int));

            output << registro.getShowId() << ";"
                   << registro.getType() << ";"
                   << registro.getTitle() << ";"
                   << registro.getDirector() << ";"
                   << registro.getCast() << ";"
                   << registro.getCountry() << ";"
                   << registro.getDateAdded() << ";"
                   << registro.getReleaseYear() << ";"
                   << registro.getRating() << ";"
                   << registro.getDuration() << ";"
                   << registro.getListedIn() << ";"
                   << registro.getDescription();

            registro.clear();
            line.clear();
        }
    }

    output.close();
}

void IndiceDireto(string nomeArquivo)
{
    Netflix registro;
    ofstream output;
    char buffer[1000];
    int tam, cabecalho = 0;
    long endereco;

    output.open("netflix_indices.dat", ios::out | ios::binary);

    if (output.is_open())
    {
        ifstream input(nomeArquivo, ios::binary);

        while (!input.eof())
        {
            input.read((char *)&tam, sizeof(int));
            endereco = input.tellg();
            cout << endereco << endl;
            input.read(buffer, tam);

            if (cabecalho == 0)
            {
                cabecalho = 1;
            }
            else
            {
                registro.split(buffer);
                output << registro.getShowId() << "|" << endereco << endl;
            }

            buffer[0] = '\0';
            registro.clear();
        }
    }

    output.close();
}