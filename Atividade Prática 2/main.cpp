#include "biblioteca.h"
#include "funcoes.h"

int main()
{
    string nomeArquivo = "netflix_titles.csv";
    string nomeArquivoDat = "netflix_titles.dat";

    Arquivo(nomeArquivo);
    IndiceDireto(nomeArquivoDat);

    pesquisa(nomeArquivo);

    return 0;
}