#include "funcoes.h"

void Arquivo(string nomeArquivo)
{
    Registro registro;
    int cabecalho = 0, i = 0, j = 0;
    string newArquivo = nomeArquivo, line, maxCountry = "";
    ofstream output;

    newArquivo.replace(newArquivo.find(".csv"), 4, ".dat");
    output.open(newArquivo, ios::out | ios::binary);

    if (output.is_open())
    {
        ifstream input(nomeArquivo);

        while (!input.eof())
        {
            getline(input, line);

            if (cabecalho == 1)
            {
                if (line != "")
                {
                    while (line[i] != ';')
                    {
                        registro.show_id[j] = line[i];
                        ++i;
                        ++j;
                    }

                    ++i;

                    j = 0;

                    while (line[i] != ';')
                    {
                        registro.type[j] = line[i];
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        registro.title[j] = line[i];
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        registro.country[j] = line[i];
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    while (line[i] != ';')
                    {
                        registro.release_year[j] = line[i];
                        ++i;
                        ++j;
                    }
                    ++i;
                    j = 0;

                    output.write((char*)&registro, sizeof(Registro));
                }
            }
            else
            {
                cabecalho = 1;
            }

            registro.show_id[0] = '\0';
            registro.type[0] = '\0';
            registro.title[0] = '\0';
            registro.release_year[0] = '\0';
            registro.release_year[0] = '\0';
            i = 0;
            line.clear();
        }
    }

    output.close();
}

// void Inserir(string nomeArquivo)
// {
//     Registro registro;
//     int reg = 0, cabecalho = 0;
//     string newArquivo = nomeArquivo, id, line;

//     newArquivo.replace(newArquivo.find(".csv"), 4, ".dat");
//     ofstream output(newArquivo, ios::app);

//     // Leitura do Teclado
//     cin >> registro.type;
//     cin >> registro.title;
//     cin >> registro.country;
//     cin >> registro.release_year;

//     if (output.is_open())
//     {
//         ifstream input(nomeArquivo);

//         while (!input.eof())
//         {
//             getline(input, line);

//             if (cabecalho == 1)
//             {
//                 if (line != "")
//                 {
//                     reg++;
//                 }
//             }
//             else
//             {
//                 cabecalho = 1;
//             }
//         }

//         id = "s" + to_string(reg + 1);

//         strcpy(registro.show_id, id.c_str());

//         cout << registro.show_id;

//         output.write(reinterpret_cast<char *>(&registro), sizeof(struct Registro));

//         output.close();
//     }
// }

void buscaBinaria(string arquivoBinario)
{
    long int inicio, meio, fim;
    ifstream input;
    ofstream output("teste.dat", ios::out);
    Registro registro;
   
    inicio = 0;

    input.open(arquivoBinario, ios::in | ios::binary);

    input.seekg(0, ios::end);
    long int tamanhoArquivo = input.tellg();
    //int resultado;

    fim = (tamanhoArquivo / sizeof(Registro)) - 1;
    
    
    // while (inicio <= fim)
    // {
    //     meio = (fim + inicio) / 2;
    //     input.seekg(meio * sizeof(Registro), ios::beg);
    //     input.read((char *)&registro, sizeof(registro));

    
    //     resultado = strcmp("s5", registro.show_id);
    //     cout<<"Resultado: "<<resultado<<endl;

    //     if (resultado ==1)
    //     {

    //         inicio = meio + 1;
    //         cout<<"entrou 1"<<endl;
    //     }
    //     else if (resultado ==-1)
    //     {

    //         fim = meio - 1;
    //         cout<<"entrou 2"<<endl;
    //     }
    //     else 
    //     if(resultado == 0)
    //     {
    //         cout<<"entrou 3";
    //         output.write((char *)&registro, sizeof(Registro));
             
    //     }
    // }

    meio = (fim + inicio) / 2;
    input.seekg(meio * sizeof(Registro), ios::beg);
    input.read((char *)&registro, sizeof(registro));
     output.write((char *)&registro, sizeof(Registro));
      cout<<"->"<<registro.show_id<<endl;
  
}