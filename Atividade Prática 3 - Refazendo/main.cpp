#include "funcoes.h"

int main()
{
    string nomeArquivo = "netflix_titles1.csv";
    int opcao;

    ConverterArquivo("netflix_titles1.csv");

    do
    {
        cout << "-> Deseja inserir novo registro (Digite 1)." << endl
             << "-> Deseja remover um registro (Digite 2)." << endl
             << "-> Realizar pesquisa de registro (Digite 3)." << endl
             << "-> Sair (Digite 0)." << endl;
        cout << "Opcao: ";
        cin >> opcao;
        cout << endl;

        if (opcao == 1)
        {
            Inserir(nomeArquivo);
        }
        else if (opcao == 2)
        {
        }
        else if (opcao == 3)
        {
        }

    } while (opcao != 0);

    return 0;
}