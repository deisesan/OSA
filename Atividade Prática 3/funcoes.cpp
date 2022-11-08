#include "funcoes.h"

void Arquivo(string nomeArquivo)
{
    Netflix registro;
    string newArquivo = nomeArquivo;
    ofstream output;
    string line, maxCountry = "";
    int tamReg = 0, tamType = 0, tamTitle = 0, tamCountry = 0, aux = 0;

    newArquivo.replace(newArquivo.find(".csv"), 4, ".dat");
    output.open(newArquivo, ios::out | ios::binary);

    if (output.is_open())
    {
        ifstream input(nomeArquivo);

        while (!input.eof())
        {
            if (input.eof())
                break;

            getline(input, line);

            registro.split(line);

            tamReg = registro.size();
            output.write(reinterpret_cast<char *>(&tamReg), sizeof(int));

            aux = registro.getType().size();
            if (aux > tamType)
                tamType = registro.getShowId().size();

            aux = registro.getTitle().size();
            if (aux > tamTitle)
                tamTitle = registro.getTitle().size();

            aux = registro.getCountry().size();
            if (aux > tamCountry)
            {
                maxCountry = registro.getCountry();
                tamCountry = registro.getCountry().size();
            }

            output << registro.getShowId() << ";"
                   << registro.getType() << ";"
                   << registro.getTitle() << ";"
                   << registro.getCountry() << ";"
                   << registro.getReleaseYear();

            registro.clear();
            line.clear();
        }

        cout << tamType << " " << tamTitle << " " << maxCountry.size();
    }

    output.close();
}
