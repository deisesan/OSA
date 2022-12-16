#include "netflix.h"

Netflix::Netflix()
// chama o método Clear
{
  Clear();
}

void Netflix::Clear()
// inicializa todos os campos com valores vazios ou zeros
{
  show_id[0] = '\0';
  type[0] = '\0';
  title[0] = '\0';
  country[0] = '\0';
  release_year[0] = '\0';
}

void Netflix::InitBuffer(Buffer &buff) const
// inicializa um buffer para dados de filmes (até 200 bytes) separadas por ';'
{
  buff.Init(';', 127);
}

void Netflix::Print() const
// exibe na saida padrão os dados do filme
{
  cout << "Filme:" << endl
       << "\t       ShowID: '" << show_id << "'\n"
       << "\t         Type: '" << type << "'\n"
       << "\t        Title: '" << title << "'\n"
       << "\t      Country: '" << country << "'\n"
       << "\t  ReleaseYear: '" << release_year << "'\n";
}

bool Netflix::Pack(Buffer &buff) const
// envia os dados do filme ao buffer
{
  buff.Clear();
  if (buff.Pack(show_id) &&
      buff.Pack(type) &&
      buff.Pack(title) &&
      buff.Pack(country) &&
      buff.Pack(release_year))
    return true;
  else
    return false;
}

bool Netflix::UnPack(Buffer &buff)
// recupera de um buffer os dados de um filme
{
  if (buff.UnPack(show_id) &&
      buff.UnPack(type) &&
      buff.UnPack(title) &&
      buff.UnPack(country) &&
      buff.UnPack(release_year))
    return true;
  else
    return false;
}