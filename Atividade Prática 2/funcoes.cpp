#include "funcoes.h"

void Arquivo(string nomeArquivo)
{
    Netflix registro;
    string newArquivo = nomeArquivo;
    ofstream output;
    string line;
    string aux;
    int i = 0, tam = 0;

    newArquivo.replace(newArquivo.find(".csv"), 4, ".dat");
    output.open(newArquivo, ios::out | ios::binary);

    if (output.is_open())
    {
        ifstream input(nomeArquivo);

        while (!input.eof())
        {
            getline(input, line);

            if (line != "")
            {
                while (line[i] != ';')
                {
                    aux += line[i];
                    i++;
                }
                registro.setShowId(aux);
                i++;
                aux.clear();

                while (line[i] != ';')
                {
                    aux += line[i];
                    i++;
                }
                registro.setType(aux);
                i++;
                aux.clear();

                while (line[i] != ';')
                {
                    aux += line[i];
                    i++;
                }
                registro.setTitle(aux);
                i++;
                aux.clear();

                while (line[i] != ';')
                {
                    aux += line[i];
                    i++;
                }
                registro.setDirector(aux);
                i++;
                aux.clear();

                while (line[i] != ';')
                {
                    aux += line[i];
                    i++;
                }
                registro.setCast(aux);
                i++;
                aux.clear();

                while (line[i] != ';')
                {
                    aux += line[i];
                    i++;
                }
                registro.setCountry(aux);
                i++;
                aux.clear();

                while (line[i] != ';')
                {
                    aux += line[i];
                    i++;
                }
                registro.setDateAdded(aux);
                i++;
                aux.clear();

                while (line[i] != ';')
                {
                    aux += line[i];
                    i++;
                }
                registro.setReleaseYear(aux);
                i++;
                aux.clear();

                while (line[i] != ';')
                {
                    aux += line[i];
                    i++;
                }
                registro.setRating(aux);
                i++;
                aux.clear();

                while (line[i] != ';')
                {
                    aux += line[i];
                    i++;
                }
                registro.setDuration(aux);
                i++;
                aux.clear();

                while (line[i] != ';')
                {
                    aux += line[i];
                    i++;
                }
                registro.setListedIn(aux);
                i++;
                aux.clear();

                while (line[i] != '\0')
                {
                    aux += line[i];
                    i++;
                }
                registro.setDescription(aux);
                aux.clear();

                tam = registro.size();
                output.write(reinterpret_cast<char *>(&tam), sizeof(int));

                output << registro.getShowId() << "|"
                       << registro.getType() << "|"
                       << registro.getTitle() << "|"
                       << registro.getDirector() << "|"
                       << registro.getCast() << "|"
                       << registro.getCountry() << "|"
                       << registro.getDateAdded() << "|"
                       << registro.getReleaseYear() << "|"
                       << registro.getRating() << "|"
                       << registro.getDuration() << "|"
                       << registro.getListedIn() << "|"
                       << registro.getDescription();

                i = 0;
                tam = 0;
                registro.clear();
                line.clear();
            }
        }
    }

    output.close();
}

void IndiceDireto(string nomeArquivo)
{
    Netflix registro;
    ofstream output;
    int tam;

    output.open("netflix_indices.dat", ios::out | ios::binary);

    if (output.is_open())
    {
        ifstream input(nomeArquivo, ios::binary);

        while (!input.eof())
        {
            char buffer[1000];
            input.read((char *)&tam, sizeof(int));
            input.read(buffer, tam);
            cout << tam << endl;
            cout << buffer << endl;
            getchar();
        }
    }

    output.close();
}