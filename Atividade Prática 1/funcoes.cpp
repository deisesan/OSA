#include "funcoes.h"

void Arquivo(string nomeArquivo)
{

    Dados dados;
    string line;
    string nome;
    string sobrenome;
    string telefone;
    string dtNascimento;
    int i = 0, cont = 0;
    ofstream Output1, Output2, Output3;

    Output1.open("IndicacaoDeTamanhoRegistro.txt");
    Output2.open("IndicacaoDeTamanhoCampo.txt");
    Output3.open("SeparadosPorTags.txt");

    if (Output1.good() && Output2.good() && Output3.good())
    {
        ifstream Input(nomeArquivo);

        while (!Input.eof())
        {
            getline(Input, line);

            if (line != "")
            {
                // Leitura de Nome
                while (line[i] != '|')
                {
                    nome += line[i];
                    ++i;
                }
                dados.setNome(nome);
                ++i;

                // Leitura de Sobrenome
                while (line[i] != '|')
                {
                    sobrenome += line[i];
                    ++i;
                }
                dados.setSobrenome(sobrenome);
                ++i;

                // Leitura de Telefone
                while (line[i] != '|')
                {
                    telefone += line[i];
                    ++i;
                }
                dados.setTelefone(telefone);
                ++i;

                // Leitura de Data de Nascimento
                while (line[i] != '\0')
                {
                    dtNascimento += line[i];
                    ++i;
                }
                dados.setDtNascimento(dtNascimento);
                ++i;

                if (cont == 0)
                {
                    Output1 << "Tamanho de Registro|"
                            << dados.getNome() << "|"
                            << dados.getSobrenome() << "|"
                            << dados.getTelefone() << "|"
                            << dados.getDtNascimento() << endl;
                    Output2 << dados.getNome().size()
                            << dados.getNome()
                            << dados.getSobrenome().size()
                            << dados.getSobrenome()
                            << dados.getTelefone().size()
                            << dados.getTelefone()
                            << dados.getDtNascimento().size()
                            << dados.getDtNascimento() << endl;
                }
                else
                {
                    Output1
                        << line.size() << "|"
                        << dados.getNome() << "|"
                        << dados.getSobrenome() << "|"
                        << dados.getTelefone() << "|"
                        << dados.getDtNascimento() << endl;
                    Output2
                        << dados.getNome().size()
                        << dados.getNome()
                        << dados.getSobrenome().size()
                        << dados.getSobrenome()
                        << dados.getTelefone().size()
                        << dados.getTelefone()
                        << dados.getDtNascimento().size()
                        << dados.getDtNascimento() << endl;
                }

                if (cont != 0)
                {
                    Output3
                        << "Nome=" << dados.getNome() << "|"
                        << "Sobrenome=" << dados.getSobrenome() << "|"
                        << "Telefone=" << dados.getTelefone() << "|"
                        << "Nascimento=" << dados.getDtNascimento() << endl;
                }

                cont++;
            }

            i = 0;
            nome.clear();
            sobrenome.clear();
            telefone.clear();
            dtNascimento.clear();
            line.clear();
        }
    }

    Output1.close();
    Output2.close();
    Output3.close();
}

void ArquivoFixo(string nomeArquivo)
{
    DadosFixos dadosfixos;
    string line;
    int i = 0, j = 0;
    ofstream Output4;

    Output4.open("TamanhoFixo.dat", ios::out | ios::binary);

    if (Output4.good())
    {
        ifstream Input(nomeArquivo);

        while (!Input.eof())
        {
            getline(Input, line);

            if (line != "")
            {
                // Leitura de Nome
                while (line[i] != '|')
                {
                    dadosfixos.nome[j] = line[i];
                    ++i;
                    ++j;
                }
                ++i;
                j = 0;

                // Leitura de Sobrenome
                while (line[i] != '|')
                {
                    dadosfixos.sobrenome[j] = line[i];
                    ++i;
                    ++j;
                }
                ++i;
                j = 0;

                // Leitura de Telefone
                while (line[i] != '|')
                {
                    dadosfixos.telefone[j] = line[i];
                    ++i;
                    ++j;
                }
                ++i;
                j = 0;

                // Leitura de Data de Nascimento
                while (line[i] != '\0')
                {
                    dadosfixos.dtNascimento[j] = line[i];
                    ++i;
                    ++j;
                }
                ++i;
                j = 0;

                Output4.write(reinterpret_cast<char *>(&dadosfixos), sizeof(struct DadosFixos));
            }

            i = 0;
            line.clear();
        }
    }

    Output4.close();
}