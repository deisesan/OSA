#include "biblioteca.h"
#include "funcoes.h"

int main()
{
    string nomeArquivo = "netflix_titles1.csv";
    string nomeArquivoDat = "netflix_titles1.dat";

    Arquivo(nomeArquivo);
    IndiceDireto(nomeArquivoDat);

    return 0;
}