#ifndef PESSOA_H_
#define PESSOA_H_

#define TAM_NOME 50
#define TAM_FONE 15

#include "Buffer.h"
#include "biblioteca.h"

class Data
{
public:
    short dia, mes, ano;

    void Clear()
    {
        dia = 1;
        mes = 1;
        ano = 1;
    }
    char *to_string() const;
    void Set(char *str);
    void Set(short d, short m, short a);
    friend ostream &operator<<(ostream &out, const Data &d);
};

class Pessoa
{
public:
    char nome[TAM_NOME + 1];
    char sobrenome[TAM_NOME + 1];
    char telefone[TAM_FONE + 1];
    Data data_nasc;

    Pessoa();           // chama o método Clear
    void Clear();       // inicializa todos os campos com valores vazios ou zeros
    void Print() const; // exibe na saida padrão os dados da Pessoa

    void InitBuffer(Buffer &buff) const; // inicializa um buffer de dados
    bool Pack(Buffer &buff) const;       // envia os dados da pessoa ao buffer
    bool UnPack(Buffer &buff);           // recupera de um buffer os dados de uma pessoa
};

#endif