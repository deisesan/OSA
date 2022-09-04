#include "biblioteca.h"
#include "funcoes.h"

int main()
{
    string nomeArquivo = "Dados.txt";

    /* Campo */
    ArquivoCampo(nomeArquivo);
    ArquivoCampoFixo(nomeArquivo);

    /* Registro */
    ArquivoRegistroFixo(nomeArquivo);
    ArquivoRegistroVariavel(nomeArquivo);

    return 0;
}