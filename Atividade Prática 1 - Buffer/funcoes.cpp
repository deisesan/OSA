#include "Pessoa.h"

void ArquivoCampo(string nomeArquivo)
{
    Pessoa p;
    string line;
    char nome[18];
    char sobrenome[10];
    char telefone[15];
    char dia[2];
    char mes[2];
    char ano[4];
    int i = 0, j;
    ofstream output;

    output.open("dados.dat", ios::out | ios::binary);

    if (output.good())
    {
        ifstream Input(nomeArquivo);

        while (!Input.eof())
        {

            Buffer buff;
            p.InitBuffer(buff);

            cout << "\nSituacao atual do Buffer:\n";
            buff.Print();

            getline(Input, line);

            if (line != "")
            {
                // Leitura de Nome
                j = 0;
                while (line[i] != '|')
                {
                    nome[j] = line[i];
                }
                strcpy(p.nome, nome);
                i++;

                // Leitura de Sobrenome
                j = 0;
                while (line[i] != '|')
                {
                    sobrenome[j] = line[i];
                    i++;
                }
                strcpy(p.sobrenome, sobrenome);
                i++;

                // Leitura de Telefone
                j = 0;
                while (line[i] != '|')
                {
                    telefone[j] = line[i];
                    i++;
                }
                strcpy(p.telefone, telefone);
                i++;

                // Leitura de Data de Nascimento
                j = 0;
                while (line[i] != '/')
                {
                    dia[j] = line[i];
                    i++;
                }
                i++;

                j = 0;
                while (line[i] != '/')
                {
                    mes[j] = line[i];
                    i++;
                }
                i++;
                j = 0;
                while (line[i] != '\0')
                {
                    ano[0] = line[i];
                    i++;
                }
                p.data_nasc.Set(stoi(dia), stoi(mes), stoi(ano));
                i++;

                p.Print();

                cout << "\nPacking Pessoa...\n";
                p.Pack(buff);
                cout << "\nSituacao atual do Buffer:\n";
                buff.Print();

                /// gerando um arquivo no formato determinado pelo buffer...
                ofstream saida("arquivo.dat", ios::binary);
                buff.Write(saida);

                saida.close();

                /// testando a leitura do arquivo gerado
                ifstream entrada("arquivo.dat");
                buff.Clear();
                while (buff.Read(entrada))
                {
                    if (p.UnPack(buff))
                    {
                        cout << "Pessoa Lida: \n";
                        p.Print();
                    }
                    else
                        cout << "Erro ao ler Dados Pessoa!\n";
                }
            }

            i = 0;
            // nome.clear();
            // sobrenome.clear();
            // telefone.clear();
            // dia.clear();
            // mes.clear();
            // ano.clear();
            // line.clear();
            nome[0] = '\0';
            sobrenome[0] = '\0';
            telefone[0] = '\0';
            dia[0] = '\0';
            ano[0] = '\0';
            mes[0] = '\0';
        }
    }

    output.close();
}
