#include "funcoes.h"

void Arquivo(string nomeArquivo)
{
    Registro registro;
    string line;

    ifstream Input(nomeArquivo);

    while (!Input.eof())
    {
        getline(Input, line, '\n');

        cout << line << endl;

        line.clear();
    }
}
