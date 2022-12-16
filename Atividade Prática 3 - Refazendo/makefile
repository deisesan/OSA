MAIN = main
OBJECTS	= $(MAIN).o funcoes.o buffer.o registro.o
FLAGS = -Wall -Wextra -std=c++17 -pedantic-errors
MATH = -lm
DEBUG = -g
CC = g++

all: main.exe

main.exe: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(MAIN).exe $(FLAGS)

main.o: $(MAIN).cpp registro.h funcoes.h buffer.h
	$(CC) -c $(MAIN).cpp -o $(MAIN).o $(FLAGS)

registro.o: registro.cpp registro.h buffer.h
	$(CC) -c registro.cpp -o registro.o $(FLAGS)

funcoes.o: funcoes.cpp funcoes.h
	$(CC) -c funcoes.cpp -o funcoes.o $(FLAGS)

buffer.o: buffer.cpp buffer.h
	$(CC) -c buffer.cpp -o buffer.o $(FLAGS)

clean:
	del /q /f $(OBJECTS)
	del /q /f *.exe
	del /q /f *.dat

run: all
	./$(MAIN).exe

exe: 
	./$(MAIN).exe