#include "biblioteca.h"
#include "funcoes.h"

int main()
{
    string nomeArquivo = "Dados.txt";

    Arquivo(nomeArquivo);
    ArquivoFixo(nomeArquivo);

    cout << "Tudo OK ate aqui";

    return 0;
}