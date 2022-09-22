#include "Buffer.h"

Buffer::Buffer(char d, int tam_max)
// construtor do Buffer... inicializa o buffer
{
    Init(d, tam_max);
}

void Buffer::Init(char d, int tam_max)
// inicializa o buffer definindo o delimitador e o tamanho maximo
{
    assert(tam_max > 0); // o tamanho deve ser maior que 0
    TAM_MAX = tam_max;

    assert(d != 0); // o delimitador não pode ser vazio
    delim = d;

    // alocar o vetor de dados e inicializar os demais atributos
    dados = new char[TAM_MAX];
    dados[0] = 0;
    tam_dados = 0;
    prox = 0;
}

int Buffer::Size() const
// retorna o tamanho atual do buffer
{
    return tam_dados;
}

void Buffer::Clear()
// limpa o buffer
{
    prox = 0;
    tam_dados = 0;
}

void Buffer::Print() const
// exibe na saída padrão os dados do buffer (tam_max e tamanho atual)
{
    if (tam_dados > 0)
    {
        char *aux = new char[tam_dados + 1];
        strncpy(aux, dados, tam_dados);
        aux[tam_dados] = '\0';
        cout << "DADOS: '" << aux << "'\n";
        delete[] aux;
    }
    else
        cout << "DADOS: <VAZIO>\n";

    cout << " TAMANHO ATUAL DO BUFFER: " << tam_dados
         << "\nTAMANHO MAXIMO DO BUFFER: " << TAM_MAX << endl;
}

bool Buffer::Read(istream &in)
// lê os dados de um arquivo binário "in" já aberto e no formato correto ("tamanho do registro"+"registros separados por delimitador")
{
    Clear();                                        // limpa o buffer
    in.read((char *)&tam_dados, sizeof(tam_dados)); // ler o tamanho do registro atual (que será o tamanho do buffer de dados)
    if (in.fail())
        return false; // falha na leitura do arquivo
    if (tam_dados > TAM_MAX)
        return false; // buffer overflow

    in.read(dados, tam_dados); // ler o registro inteiro do arquivo de dados.
    return in.good();
}

bool Buffer::Write(ostream &out) const
// escreve os dados em uma arquivo binário
{
    out.write((char *)&tam_dados, sizeof(tam_dados));
    out.write(dados, tam_dados);
    return out.good();
}

bool Buffer::Pack(const char *str)
// modifica o próximo campo do buffer
{
    int tam_str = strlen(str); // recupera o tamanho da string a ser adicionada ao buffer

    int inicio = prox;
    prox += tam_str + 1; // deve-se somar 1 devido ao delimitador
    if (prox > TAM_MAX)
        return false; // a adição do novo campo ultrapassa o tamanho maximo do buffer

    memcpy(&dados[inicio], str, tam_str);

    dados[inicio + tam_str] = delim;
    tam_dados = prox;
    return true;
}

bool Buffer::UnPack(char *str)
// lê o próximo campo do buffer de forma circular
{
    int inicio = prox;
    int pos_campo = -1;
    for (int i = inicio; i < tam_dados; i++)
        if (dados[i] == delim)
        {
            pos_campo = i - inicio;
            break;
        }
    if (pos_campo == -1)
        return false; // delimitador não encontrado (buffer vazio ou mal formado)

    prox += pos_campo + 1;
    if (prox > TAM_MAX)
        return false;

    strncpy(str, &dados[inicio], pos_campo);
    str[pos_campo] = 0; // adicionar o \0 ao final da string
    return true;
}
