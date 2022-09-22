#include "pessoa.h"

#define TAM_NOME 50
#define TAM_FONE 15
#define TAM_NASC 10

void Arquivo(string nomeArquivo)
{
    Pessoa p;
    string line;
    char nome[TAM_NOME + 1];
    char sobrenome[TAM_NOME + 1];
    char telefone[TAM_FONE + 1];
    char nascimento[TAM_NASC + 1];
    int i = 0, j = 0;

    Buffer buff;
    p.InitBuffer(buff);

    ofstream output("dados.dat", ios::binary);

    if (output.good())
    {
        ifstream Input(nomeArquivo);

        while (!Input.eof())
        {
            cout << "\nSituacao atual do Buffer:\n";
            buff.Print();

            getline(Input, line, '\n');

            if (line != "")
            {
                // Leitura de Nome
                while (line[i] != '|')
                {
                    nome[j] = line[i];
                    i++;
                    j++;
                }
                strcpy(p.nome, nome);
                i++;
                j = 0;

                // Leitura de Sobrenome
                while (line[i] != '|')
                {
                    sobrenome[j] = line[i];
                    i++;
                    j++;
                }
                strcpy(p.sobrenome, sobrenome);
                i++;
                j = 0;

                // Leitura de Telefone
                while (line[i] != '|')
                {
                    telefone[j] = line[i];
                    i++;
                    j++;
                }
                strcpy(p.telefone, telefone);
                i++;
                j = 0;

                // Leitura de Data de Nascimento
                while (line[i] != '\0')
                {
                    nascimento[j] = line[i];
                    i++;
                    j++;
                }
                p.data_nasc.Set(nascimento);

                p.Print();

                cout << "\nPacking Pessoa...\n";
                p.Pack(buff);
                cout << "\nSituacao atual do Buffer:\n";
                buff.Print();

                buff.Write(output);

                buff.Clear();
            }

            i = 0;
            j = 0;
            nome[0] = '\0';
            sobrenome[0] = '\0';
            telefone[0] = '\0';
            nascimento[0] = '\0';
        }
    }

    output.close();
}
