#include "dados.h"

Dados::Dados()
{
}

string Dados::getNome()
{
    return nome;
}

string Dados::getSobrenome()
{
    return sobrenome;
}

string Dados::getTelefone()
{
    return telefone;
}

string Dados::getDtNascimento()
{
    return dtNascimento;
}

void Dados::setNome(string nome)
{
    this->nome = nome;
}

void Dados::setSobrenome(string sobrenome)
{
    this->sobrenome = sobrenome;
}

void Dados::setTelefone(string telefone)
{
    this->telefone = telefone;
}

void Dados::setDtNascimento(string dtNascimento)
{
    this->dtNascimento = dtNascimento;
}

Dados::~Dados()
{
}