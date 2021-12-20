
CC = gcc

COMP = -Wall -Wextra

OBJ = main.o prog

all: prog progEnum #Permet de generer les deux avec la commande make

prog: main.o
	$(CC) -o prog main.o $(COMP) -lm

main.o: main.c 
	$(CC)  -o main.o -c main.c $(COMP) -lm

progEnum: mainEnum.o 
	$(CC) -o progEnum mainEnum.o $(COMP) -lm

mainEnum.o: mainEnum.c
	$(CC) -o mainEnum.o -c mainEnum.c $(COMP) -lm


clear: #Permet de tout effacer avec la commande make clear
	rm $(OBJ)
