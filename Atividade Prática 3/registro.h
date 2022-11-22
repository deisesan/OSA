#ifndef REGISTRO_H
#define REGISTRO_H

#include "biblioteca.h"

struct Registro
{
  char show_id[5];
  char type[10];
  char title[105];
  char country[125];
  char release_year[4];
};

#endif // REGISTRO_H