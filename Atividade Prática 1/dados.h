#ifndef DADOS_H
#define DADOS_H

#include "biblioteca.h"

class Dados
{
private:
    string nome;
    string sobrenome;
    string telefone;
    string dtNascimento;

public:
    Dados();

    // Gets
    string getNome();
    string getSobrenome();
    string getTelefone();
    string getDtNascimento();

    // Sets
    void setNome(string nome);
    void setSobrenome(string sobrenome);
    void setTelefone(string telefone);
    void setDtNascimento(string dtNascimento);

    ~Dados();
};

#endif