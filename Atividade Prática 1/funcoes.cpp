#include "funcoes.h"

void leituraArquivo(string nomeArquivo)
{
    ifstream Arquivo(nomeArquivo);
    string line;
    string nome;
    string sobrenome;
    string telefone;
    string dtNascimento;
    int i = 0;

    while (!Arquivo.eof())
    {
        getline(Arquivo, line, '\0');

        // Leitura de Nome
        while (line[i] != '|')
        {
            nome += line[i];
            ++i;
        }
        ++i;

        // Leitura de Sobrenome
        while (line[i] != '|')
        {
            sobrenome += line[i];
            ++i;
        }
        ++i;

        // Leitura de Telefone
        while (line[i] != '|')
        {
            telefone += line[i];
            ++i;
        }
        ++i;

        // Leitura de Data de Nascimento
        while (line[i] != '\0')
        {
            dtNascimento += line[i];
            ++i;
        }
        ++i;

        cout << nome << "|" << sobrenome << "|" << telefone << "|" << dtNascimento << endl;
    }
}

void escritaArquivo(string nomeArquivo)
{
}
