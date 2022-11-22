#include "biblioteca.h"
#include "funcoes.h"

int main()
{
    string nomeArquivo = "netflix_titles1.csv";
    string arquivoBinario = "netflix_titles1.dat";
    //Registro registro;

    Arquivo(nomeArquivo);
    //Inserir(nomeArquivo);
    buscaBinaria(arquivoBinario);

    return 0;
}