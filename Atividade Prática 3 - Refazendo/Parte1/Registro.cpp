#include "registro.h"

Registro::Registro()
// chama o método Clear
{
    Clear();
}

void Registro::Clear()
// inicializa todos os campos com valores vazios ou zeros
{
    show_id[0] = '\0';
    type[0] = '\0';
    title[0] = '\0';
    country[0] = '\0';
    release_year[0] = '\0';
}

void Registro::InitBuffer(Buffer &buff) const
// inicializa um buffer para dados de filmes (até 200 bytes) separadas por ';'
{
    buff.Init(';', 127);
}

void Registro::Print() const
// exibe na saida padrão os dados do filme
{
    cout << "Registro:" << endl
         << "\t       ShowID: '" << show_id << "'\n"
         << "\t         Type: '" << type << "'\n"
         << "\t        Title: '" << title << "'\n"
         << "\t      Country: '" << country << "'\n"
         << "\t  ReleaseYear: '" << release_year << "'" << endl;
}

bool Registro::Pack(Buffer &buff) const
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

bool Registro::UnPack(Buffer &buff)
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