MAIN = main
OBJECTS	= $(MAIN).o funcoes.o dados.o
FLAGS = -Wall -Wextra -std=c++17 -pedantic-errors
MATH = -lm
DEBUG = -g
CC = g++

all: main.exe

main.exe: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(MAIN).exe $(FLAGS)

main.o: $(MAIN).cpp funcoes.cpp funcoes.h
	$(CC) -c $(MAIN).cpp -o $(MAIN).o $(FLAGS)

funcoes.o: funcoes.cpp funcoes.h
	$(CC) -c funcoes.cpp -o funcoes.o $(FLAGS)

dados.o: dados.cpp dados.h
	$(CC) -c dados.cpp -o dados.o $(FLAGS)

clean:
	del /q /f $(OBJECTS)
	del /q /f *.exe
	del /q /f *.dat
	del /q /f IndicacaoDeTamanhoCampo.txt
	del /q /f SeparadosPorTags.txt
	del /q /f ArquivoRegistroVariavel.txt


run: all
	./$(MAIN).exe

exe: 
	./$(MAIN).exe