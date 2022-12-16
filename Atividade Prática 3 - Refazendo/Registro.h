#ifndef REGISTRO_H
#define REGISTRO_H

#define TAM_SHOWID 6
#define TAM_TYPE 10
#define TAM_TITLE 105
#define TAM_COUNTRY 125
#define TAM_RELEASEYEAR 5

#include "Buffer.h"

class Registro
{
public:
  char show_id[TAM_SHOWID];
  char type[TAM_TYPE];
  char title[TAM_TITLE];
  char country[TAM_COUNTRY];
  char release_year[TAM_RELEASEYEAR];

  Registro();         // chama o método Clear
  void Clear();       // inicializa todos os campos com valores vazios ou zeros
  void Print() const; // exibe na saida padrão os dados do filme

  void InitBuffer(Buffer &buff) const; // inicializa um buffer de dados
  bool Pack(Buffer &buff) const;       // envia os dados do filme ao buffer
  bool UnPack(Buffer &buff);           // recupera de um buffer os dados de um filme
};

#endif // REGISTRO_H