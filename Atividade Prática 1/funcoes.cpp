#include "funcoes.h"

void Arquivo(string nomeArquivo)
{

    Dados dados;
    string line;
    string nome;
    string sobrenome;
    string telefone;
    string dtNascimento;
    int i = 0;

    ifstream Input(nomeArquivo);
    nomeArquivo.replace(nomeArquivo.find(".txt"), 4, "Saida.txt");
    ofstream Output(nomeArquivo);

    while (!Input.eof())
    {
        getline(Input, line, '\0');

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

        Output
            << dados.getNome() << "|"
            << dados.getSobrenome() << "|"
            << dados.getTelefone() << "|"
            << dados.getDtNascimento() << endl;

        i = 0;
        nome.clear();
        sobrenome.clear();
        telefone.clear();
        dtNascimento.clear();
        line.clear();
    }
}
