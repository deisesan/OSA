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
             << "-> Realizar pesquisa de registro (Digite 2)." << endl
             << "-> Deseja remover um registro (Digite 3)." << endl
             << "-> Sair (Digite 0)." << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1)
        {
            Inserir(arquivoBinario, buff);
        }
        else if (opcao == 2)
        {
            cout << "Digite show_id que deseja procurar (Ex: s2345): " << endl;
            cin >> chave;
            BuscaBinaria(arquivoBinario, chave);
        }
        else if (opcao == 3)
        {
        }

    } while (opcao != 0);

    return 0;
}