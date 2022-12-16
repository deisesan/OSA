#ifndef BUFFER_H_
#define BUFFER_H_

#include "biblioteca.h"

class Buffer
{
private:           // atributos do buffer
    char delim;    // delimitador usado no arquivo de dados
    char *dados;   // vetor de dados do buffer
    int tam_dados; // tamanho do buffer ( incluindo os delimitadores)
    int TAM_MAX;
    int prox; // endereco do próximo campo a ser lido ou incluído no buffer
public:
    Buffer(char d = ';', int tam_max = 1024);
    void Init(char d, int tam_max = 1024); // inicializa o buffer definindo o delimitador e o tamanho maximo

    void Clear(); // limpa o buffer

    bool Pack(const char *str); // modifica o próximo campo do buffer
    bool UnPack(char *str);     // lê o próximo campo do buffer de forma circular

    void Print() const;             // exibe na saida padrão os dados do buffer (tam_max e tamanho atual)
    int Size() const;               // retorna o tamanho atual do buffer
    bool Read(istream &in);         // lê os dados de um arquivo binário no formato correto ("tamanho do registro"+"registros separados por delimitador")
    bool Write(ostream &out) const; // escreve os dados em uma arquivo binário
};

#endif