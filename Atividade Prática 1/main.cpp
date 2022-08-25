#include "funcoes.h"
#include <iostream>
using namespace std;

int main()
{
    string nomeArquivo = "Dados.txt";

    leituraArquivo(nomeArquivo);
    escritaArquivo(nomeArquivo);

    cout << "Tudo OK ate aqui";
}