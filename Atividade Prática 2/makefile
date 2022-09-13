MAIN = main
OBJECTS	= $(MAIN).o funcoes.o registro.o
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

registro.o: registro.cpp registro.h
	$(CC) -c registro.cpp -o registro.o $(FLAGS)

clean:
	del /q /f $(OBJECTS)
	del /q /f *.exe

run: all
	./$(MAIN).exe

exe: 
	./$(MAIN).exe