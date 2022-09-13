MAIN = main
OBJECTS	= $(MAIN).o 
FLAGS = -Wall -Wextra -std=c++17 -pedantic-errors
MATH = -lm
DEBUG = -g
CC = g++

all: main.exe

main.exe: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(MAIN).exe $(FLAGS)

clean:
	del /q /f $(OBJECTS)
	del /q /f *.exe

run: all
	./$(MAIN).exe

exe: 
	./$(MAIN).exe