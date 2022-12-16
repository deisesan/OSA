#include "netflix.h"

#define TAM_SHOWID 6
#define TAM_TYPE 10
#define TAM_TITLE 105
#define TAM_COUNTRY 125
#define TAM_RELEASEYEAR 5

void ConverterArquivo(string nomeArquivo)
{
  Netflix filme;
  string line, newArquivo = nomeArquivo;
  ofstream output;
  char show_id[TAM_SHOWID];
  char type[TAM_TYPE];
  char title[TAM_TITLE];
  char country[TAM_COUNTRY];
  char release_year[TAM_RELEASEYEAR];
  int i = 0, j = 0, cabecalho = 0;

  Buffer buff;
  filme.InitBuffer(buff);

  newArquivo.replace(newArquivo.find(".csv"), 4, ".dat");
  output.open(newArquivo, ios::out | ios::binary);

  if (output.good())
  {
    ifstream input(nomeArquivo);

    while (!input.eof())
    {
      getline(input, line);

      if (cabecalho == 1)
      {
        if (line != "")
        {
          // Leitura de show_id
          while (line[i] != ';')
          {
            show_id[j] = line[i];
            i++;
            j++;
          }
          strcpy(filme.show_id, show_id);
          i++;
          j = 0;

          // Leitura de type
          while (line[i] != ';')
          {
            type[j] = line[i];
            i++;
            j++;
          }
          strcpy(filme.type, type);
          i++;
          j = 0;

          // Leitura de title
          while (line[i] != ';')
          {
            title[j] = line[i];
            i++;
            j++;
          }
          strcpy(filme.title, title);
          i++;
          j = 0;

          // Leitura de director
          while (line[i] != ';')
          {
            i++;
            j++;
          }
          i++;
          j = 0;

          // Leitura de cast
          while (line[i] != ';')
          {
            i++;
            j++;
          }
          i++;
          j = 0;

          // Leitura de country
          while (line[i] != ';')
          {
            country[j] = line[i];
            i++;
            j++;
          }
          strcpy(filme.country, country);
          i++;
          j = 0;

          // Leitura de date_added
          while (line[i] != ';')
          {
            i++;
            j++;
          }
          i++;
          j = 0;

          // Leitura de release_year
          while (line[i] != ';')
          {
            release_year[j] = line[i];
            i++;
            j++;
          }
          strcpy(filme.release_year, release_year);
          i++;
          j = 0;

          // Leitura de rating
          while (line[i] != ';')
          {
            i++;
            j++;
          }
          i++;
          j = 0;

          // Leitura de duration
          while (line[i] != ';')
          {
            i++;
            j++;
          }
          i++;
          j = 0;

          // Leitura de listed_in
          while (line[i] != ';')
          {
            i++;
            j++;
          }
          i++;
          j = 0;

          // Leitura de description
          while (line[i] != '\0')
          {
            i++;
            j++;
          }
          i++;
          j = 0;

          filme.Print();

          cout << "\nPacking Filme...\n";
          filme.Pack(buff);
          cout << "\nSituacao atual do Buffer:\n";
          buff.Print();

          buff.Write(output);

          buff.Clear();
        }
      }
      else
      {
        cabecalho = 1;
      }

      i = 0;
      j = 0;
      show_id[0] = '\0';
      type[0] = '\0';
      title[0] = '\0';
      country[0] = '\0';
      release_year[0] = '\0';
    }
  }

  output.close();
}

void Inserir(string nomeArquivo)
{
  string newArquivo = nomeArquivo;

  newArquivo.replace(newArquivo.find(".csv"), 4, ".dat");
}