#include "funcoes.h"

void Arquivo(string nomeArquivo)
{
    Netflix registro, maiorRegistro, menorRegistro;
    string newArquivo = nomeArquivo;
    ofstream output;
    string line;
    int i = 0, tam = 0, qtd_registros = 0;

    newArquivo.replace(newArquivo.find(".csv"), 4, ".dat");
    output.open(newArquivo, ios::out | ios::binary);

    if (output.is_open())
    {
        ifstream input(nomeArquivo);

        while (!input.eof())
        {
            getline(input, line);

            registro.split(line);

            if (registro.getShowId() != "")
            {

                if (i == 1)
                {
                    maiorRegistro = registro;
                    menorRegistro = registro;
                }

                if (i != 0)
                    qtd_registros++;

                tam = registro.size();
                output.write(reinterpret_cast<char *>(&tam), sizeof(int));

                if (tam > maiorRegistro.size())
                {
                    maiorRegistro = registro;
                }
                else if (tam < menorRegistro.size())
                {
                    menorRegistro = registro;
                }

                output << registro.getShowId() << ";"
                       << registro.getType() << ";"
                       << registro.getTitle() << ";"
                       << registro.getDirector() << ";"
                       << registro.getCast() << ";"
                       << registro.getCountry() << ";"
                       << registro.getDateAdded() << ";"
                       << registro.getReleaseYear() << ";"
                       << registro.getRating() << ";"
                       << registro.getDuration() << ";"
                       << registro.getListedIn() << ";"
                       << registro.getDescription();
            }
            registro.clear();
            line.clear();
            i++;
        }
        cout << endl<< string(5, '-') << "> QUANTIDADE DE REGISTROS: " << qtd_registros << endl;
        cout << endl<< string(5, '-') << "> MAIOR REGISTRO: ";
        maiorRegistro.print();
        cout << endl<< string(5, '-') << ">TAMANHO DE MAIOR REGISTRO: " << maiorRegistro.size() << endl;
        cout << endl<< string(5, '-') << "> MENOR REGISTRO: ";
        menorRegistro.print();
        cout << endl<< string(5, '-') << ">TAMANHO DE MENOR REGISTRO: " << menorRegistro.size() << endl;
    }

    output.close();
}

void IndiceDireto(string nomeArquivo)
{
    Netflix registro;
    ofstream output;
    char buffer[1500];
    int tam, cabecalho = 0;
    long endereco;

    output.open("netflix_indices.dat", ios::out | ios::binary);

    if (output.is_open())
    {
        ifstream input(nomeArquivo, ios::binary);

        while (!input.eof())
        {
            input.read((char *)&tam, sizeof(int));
            endereco = input.tellg();
            // cout << endereco << endl;
            input.read(buffer, tam);

            if (cabecalho == 0)
            {
                cabecalho = 1;
            }
            else
            {
                registro.split(buffer);
                if (registro.getShowId() != "")
                {
                    output << registro.getShowId() << "|" << endereco << endl;
                }
            }

            buffer[0] = '\0';
            registro.clear();
        }
    }

    output.close();
}

void pesquisa(string nomeArquivo)
{
    Netflix registro;
    bool found = false;
    string line;
    string str_pesquisa, aux;
    string opcao, one = "1", two = "2";

    ifstream input(nomeArquivo);
    do
    {
        cout << endl
             << string(5, '-') << "> Deseja fazer pesquisa por Show_id(digite 1) ou Titulo(digite 2): " << endl;
        cin >> opcao;

    } while (one.compare(opcao) != 0 && two.compare(opcao) != 0);

    if (opcao == "1")
    {

        cout << endl
             << string(5, '-') << "> Digite Show_id que deseja pesquisar: ";
        cin >> str_pesquisa;
    }
    else
    {
        cout << endl
             << string(5, '-') << "> Digite titulo que deseja procurar: ";
        cin.ignore();
        getline(cin, str_pesquisa);
    }

    while (!input.eof())
    {
        getline(input, line);

        registro.split(line);

        if (opcao == "1")
        {

            aux = registro.getShowId();

            for_each(aux.begin(), aux.end(), [](char &c)
                     { c = ::toupper(c); });

            for_each(str_pesquisa.begin(), str_pesquisa.end(), [](char &c)
                     { c = ::toupper(c); });

            if (aux.compare(str_pesquisa) == 0)
            {
                found = true;
                cout << endl
                     << string(5, '-') << "> RESULTADO ENCONTRADO: ";
                registro.print();
            }
        }
        else
        {
            aux = registro.getTitle();

            for_each(aux.begin(), aux.end(), [](char &c)
                     { c = ::toupper(c); });

            for_each(str_pesquisa.begin(), str_pesquisa.end(), [](char &c)
                     { c = ::toupper(c); });

            if (aux.find(str_pesquisa) != std::string::npos)
            {
                found = true;
                cout << endl
                     << string(5, '-') << "> RESULTADO ENCONTRADO: ";
                registro.print();
            }
        }

        aux.clear();
        line.clear();
        registro.clear();
    }
    if (!found)
    {
        cout << endl
             << string(5, '-') << "> NENHUM RESULTADO ENCONTRADO." << endl;
    }
}