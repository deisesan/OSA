#include "funcoes.h"

void ArquivoCampo(string nomeArquivo)
{
    Dados dados;
    string line;
    string nome;
    string sobrenome;
    string telefone;
    string dtNascimento;
    int i = 0, cont = 0, tam = 0;
    ofstream Output1, Output2, Output3;

    Output1.open("IndicacaoDeTamanhoCampo.txt");
    Output2.open("SeparadosPorTags.txt");
    Output3.open("IndicacaoDeTamanhoCampo.dat", ios::out | ios::binary);

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

                Output1 << dados.getNome().size()
                        << dados.getNome()
                        << dados.getSobrenome().size()
                        << dados.getSobrenome()
                        << dados.getTelefone().size()
                        << dados.getTelefone()
                        << dados.getDtNascimento().size()
                        << dados.getDtNascimento() << endl;

                if (cont != 0)
                {
                    Output2
                        << "Nome=" << dados.getNome() << "|"
                        << "Sobrenome=" << dados.getSobrenome() << "|"
                        << "Telefone=" << dados.getTelefone() << "|"
                        << "Nascimento=" << dados.getDtNascimento() << endl;
                }

                tam = nome.size();
                Output3.write(reinterpret_cast<char *>(&tam), sizeof(int));
                Output3.write(reinterpret_cast<char *>(&nome[0]), tam * sizeof(char));

                tam = sobrenome.size();
                Output3.write(reinterpret_cast<char *>(&tam), sizeof(int));
                Output3.write(reinterpret_cast<char *>(&sobrenome[0]), tam * sizeof(char));

                tam = telefone.size();
                Output3.write(reinterpret_cast<char *>(&tam), sizeof(int));
                Output3.write(reinterpret_cast<char *>(&telefone[0]), tam * sizeof(char));

                tam = dtNascimento.size();
                Output3.write(reinterpret_cast<char *>(&tam), sizeof(int));
                Output3.write(reinterpret_cast<char *>(&dtNascimento[0]), tam * sizeof(char));

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

void ArquivoCampoFixo(string nomeArquivo)
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

void ArquivoRegistroVariavel(string nomeArquivo)
{
    Dados dados;
    string line;
    string nome;
    string sobrenome;
    string telefone;
    string dtNascimento;
    int i = 0;
    ofstream Output5;

    Output5.open("ArquivoRegistroVariavel.txt");

    if (Output5.good())
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

                Output5
                    << line.size()
                    << dados.getNome() << "|"
                    << dados.getSobrenome() << "|"
                    << dados.getTelefone() << "|"
                    << dados.getDtNascimento();
            }

            i = 0;
            nome.clear();
            sobrenome.clear();
            telefone.clear();
            dtNascimento.clear();
            line.clear();
        }
    }

    Output5.close();
}

void ArquivoRegistroFixo(string nomeArquivo)
{
    DadosFixos dadosfixos;
    string line;
    int i = 0, j = 0, tam = 58;
    ofstream Output6;

    Output6.open("ArquivoRegistroFixo.dat", ios::out | ios::binary);

    if (Output6.good())
    {
        ifstream Input(nomeArquivo);
        Output6.write(reinterpret_cast<char *>(&tam), sizeof(int));

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

                Output6.write(reinterpret_cast<char *>(&dadosfixos), sizeof(struct DadosFixos));
            }

            i = 0;
            line.clear();
        }
    }

    Output6.close();
}