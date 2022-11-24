#include "biblioteca.h"
#include "funcoes.h"

int main()
{
    string chave;
    string nomeArquivo = "netflix_titles.csv";
    string arquivoBinario = "netflix_titles.dat";
    // Registro registro;
    Arquivo(nomeArquivo);
    int opcao;

    do
    {

        cout << "->Deseja inserir novo registro (Digite 1)."<< endl
             << "->Realizar pesquisa de registro (Digite 2)."<< endl
             << "-> Sair (Digite 0)."<< endl;
        cout<<"Opcao: ";     
        cin >> opcao;
        cout<<endl;

        if (opcao == 1)
        {
            Inserir(arquivoBinario);
        }
        else if (opcao == 2)
        {

            cout << "Digite show_id que deseja procurar (Ex: s2345): " << endl;
            cin >> chave;
            buscaBinaria(arquivoBinario, chave);
        }

    } while (opcao != 0);

    return 0;
}