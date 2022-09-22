#include "pessoa.h"

ostream &operator<<(ostream &out, const Data &d)
{
    out << d.to_string();
    return out;
}

char *Data::to_string() const
{
    char *str = new char[11];
    sprintf(str, "%02d/%02d/%04d", dia, mes, ano);
    return str;
}

void Data::Set(char *str)
{
    dia = atoi(strtok(str, "/"));
    mes = atoi(strtok(NULL, "/"));
    ano = atoi(strtok(NULL, "\0"));
}

void Data::Set(short d, short m, short a)
{
    dia = d;
    mes = m;
    ano = a;
}

Pessoa::Pessoa()
// chama o método Clear
{
    Clear();
}

void Pessoa::Clear()
// inicializa todos os campos com valores vazios ou zeros
{
    nome[0] = '\0';
    sobrenome[0] = '\0';
    telefone[0] = '\0';
    data_nasc.Clear();
}

void Pessoa::InitBuffer(Buffer &buff) const
// inicializa um buffer para dados de pessoas (até 200 bytes) separadas por '|'
{
    buff.Init('|', 127);
}

void Pessoa::Print() const
// exibe na saida padrão os dados da Pessoa
{
    cout << "Pessoa:" << endl
         << "\t       Nome: '" << nome << "'\n"
         << "\t  Sobrenome: '" << sobrenome << "'\n"
         << "\t   Telefone: '" << telefone << "'\n"
         << "\t Nascimento: '" << data_nasc << "'" << endl;
}

bool Pessoa::Pack(Buffer &buff) const
// envia os dados da pessoa ao buffer
{
    buff.Clear();
    if (buff.Pack(nome) &&
        buff.Pack(sobrenome) &&
        buff.Pack(telefone) &&
        buff.Pack(data_nasc.to_string()))
        return true;
    else
        return false;
}

bool Pessoa::UnPack(Buffer &buff)
// recupera de um buffer os dados de uma pessoa
{
    char aux[11];
    if (buff.UnPack(nome) &&
        buff.UnPack(sobrenome) &&
        buff.UnPack(telefone) &&
        buff.UnPack(aux))
    {
        data_nasc.Set(aux);
        return true;
    }
    return false;
}