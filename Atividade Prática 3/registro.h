#ifndef REGISTRO_H
#define REGISTRO_H

#include "biblioteca.h"

struct Registro
{
  int deleted = 0;
  char show_id[6];
  char type[8];
  char title[104];
  char country[123];
  char release_year[11];
};

#endif // REGISTRO_H