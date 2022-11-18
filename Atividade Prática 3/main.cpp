#include "biblioteca.h"
#include "funcoes.h"

int main()
{
    string nomeArquivo = "netflix_titles1.csv";
    Registro registro;

    // string show_id("s7");
    // string type("Teste");
    // string title("Teste");
    // string county("Brasil");
    // string release_year("11/11/2022");

    // Leitura do registro
    // registro.show_id[ = show_id;
    // registro.type[8] = 'Teste';
    // registro.title[104] = 'Teste';
    // registro.country[123] = 'Brasil';
    // registro.release_year[11] = '11/11/2022';

    Arquivo(nomeArquivo);
    Inserir(nomeArquivo);

    return 0;
}