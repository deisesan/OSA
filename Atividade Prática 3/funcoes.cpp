#include "funcoes.h"

void Arquivo(string nomeArquivo)
{
    Netflix registro;
    string newArquivo = nomeArquivo;
    ofstream output;
    string line, maxCountry = "";
    int deleted = 0, cabecalho = 0;

    newArquivo.replace(newArquivo.find(".csv"), 4, ".dat");
    output.open(newArquivo, ios::out | ios::binary);

    if (output.is_open())
    {
        ifstream input(nomeArquivo);

        while (!input.eof())
        {
            getline(input, line);

            registro.split(line);

            if (cabecalho == 1)
            {
                output.write((char *)&deleted, sizeof(int));

                output << registro.getShowId() << ";"
                       << registro.getType() << ";"
                       << registro.getTitle() << ";"
                       << registro.getCountry() << ";"
                       << registro.getReleaseYear() << endl;
            }
            else
            {
                cabecalho = 1;
            }

            registro.clear();
            line.clear();
        }
    }

    output.close();
}

void Indexacao(string nomeArquivo)
{
    // Index index;
    // string showId;
    int deleted;

    ifstream input(nomeArquivo, ios::binary);

    while (!input.eof())
    {
        // input.read((char *)&index, sizeof(Index));
        input.read((char *)&deleted, sizeof(int));

        cout << deleted << endl;
    }
}