# definindo as variáveis do projeto (MAIN é o nome do arquivo principal, que contem a função main, sem a extensao)
MAIN 	:= main
# objetos a serem gerados na compilação
OBJECTS := main.o Pessoa.o Buffer.o funcoes.o
# (para C, pode-se usar o padrão ISO 2011 (c11) ou 2018 (c18), dependendo do seu compilador...
# usar -std=c98 no lugar do c++11, c++17, c++20, etc.. 

FLAGS 	:= -Wall -Wextra -std=c++17 -pedantic-errors

# habilitar a depuração
DEBUG :=  -g

# necessário apenas quando se incluir  a biblioteca <math.h> em algum arquivo fonte no projeto
MATH 	:= -lm

# definição do compilador: para C usar o gcc, por exemplo
CC		:= g++

# ajustando alguns parâmetros/comandos ao sistema operacional
ifeq ($(OS), Windows_NT)
OUTPUTMAIN := $(MAIN).exe
RM	:= del /q /f
else
OUTPUTMAIN := $(MAIN).out
RM	:= rm -f
endif

# ponto de compilação principal
all: main.exe
	@echo Compiling 'all' complete!

# gerando o arquivo executavel
main.exe: $(OBJECTS)  
	$(CC) $(FLAGS) $(OBJECTS) -o $(OUTPUTMAIN) $(MATH)


# gerando o arquivo objeto da função principal... adicionar as dependencias (se houverem)
main.o: $(MAIN).cpp Pessoa.h Buffer.h
	$(CC) $(FLAGS) -c $(MAIN).cpp

# gerando o arquivo executavel
Pessoa.o: Pessoa.cpp Pessoa.h Buffer.h
	$(CC) $(FLAGS) -c Pessoa.cpp

# gerando o arquivo executavel
funcoes.o: funcoes.cpp funcoes.h
	$(CC) $(FLAGS) -c funcoes.cpp
	
# gerando o arquivo objeto da minha biblioteca 1 (myFunc1.o) que depende dos arquivos myFunc1.c, myFunc1.h
Buffer.o: Buffer.cpp Buffer.h
	$(CC) $(FLAGS) -c Buffer.cpp

clean:
	$(RM) $(OBJECTS)
	$(RM) $(OUTPUTMAIN)
	$(RM) *.dat
	$(RM) *.exe
	@echo Cleanup complete!!!

run: all
	./$(OUTPUTMAIN)
	@echo Executing 'all' complete!!!