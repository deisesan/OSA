#include "biblioteca.h"
#include "funcoes.h"

int main()
{
    string chave;
    string nomeArquivo = "netflix_titles1.csv";
    string arquivoBinario = "netflix_titles1.dat";
    Buffer buff;

    Arquivo(nomeArquivo, buff);
    int opcao;

    do
    {
        cout << endl;
        cout << "-> Deseja inserir novo registro (Digite 1)." << endl
             << "-> Sair (Digite 0)." << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1)
        {
            Inserir(arquivoBinario, buff);
        }

    } while (opcao != 0);

    return 0;
}