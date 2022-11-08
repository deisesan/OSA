#ifndef INDEX_H
#define INDEX_H

#include "biblioteca.h"

struct Index
{
  char show_id[6];
  char type[8];
  char title[104];
  char country[123];
  char release_year[11];
  int deleted;
};

#endif // INDEX_H