#include "biblioteca.h"
#include "funcoes.h"

int main()
{    
    string chave;
    string nomeArquivo = "netflix_titles.csv";
    string arquivoBinario = "netflix_titles.dat";
    //Registro registro;
    
    Arquivo(nomeArquivo);
    //Inserir(nomeArquivo);



    cout<<"Digite show_id que deseja procurar (Ex: s2345): "<<endl;
    cin>>chave;
    buscaBinaria(arquivoBinario, chave);

    return 0;
}