##############################################################################
# Exemplo de makefile para um projeto bem simples em linguagem C++
# Para simplificar, todos os arquivos estão em um mesmo diretório
##############################################################################
# Arquivo principal: main.cpp
##############################################################################
#                       Arquivo auxiliar do projeto
##############################################################################
# funcoes.cpp: depende de funcoes.h
##############################################################################

# definição de variáveis auxiliares do makefile
MAIN = main
OBJECTS	= $(MAIN).o funcoes.o
FLAGS = -Wall -Wextra -std=c++17 -pedantic-errors
MATH = -lm
DEBUG = -g
CC = g++

# regra de compilação do projeto completo
all: main.exe

# regra para geração do arquivo executavel
main.exe: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(MAIN).exe $(FLAGS)

# regra de compilação do objeto main.o
main.o: $(MAIN).cpp funcoes.cpp funcoes.h
	$(CC) -c $(MAIN).cpp -o $(MAIN).o $(FLAGS)

# regra de compilação do objeto funcoes.o
funcoes.o: funcoes.cpp funcoes.h
	$(CC) -c funcoes.cpp -o funcoes.o $(FLAGS)

# regra para limpeza do projeto (excluir arquivos .o e .exe). 
# (OBS.: SO windows)
clean:
	del /q /f $(OBJECTS)
	del /q /f *.exe

# regra para compilar todo o projeto (se necessário) e, posteriormente, executar
# (OBS.: SO windows)
run: all
	./$(MAIN).exe

exe: 
	./$(MAIN).exe