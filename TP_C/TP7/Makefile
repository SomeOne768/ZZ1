#Création d'un makefile. Utiliser la commande make dans le terminal pour tout compiler

#On peut définir des "variables"
CC = gcc -Wall -Wextra


#Executable

prog : main.o liste.o
	gcc -Wall -Wextra -o prog main.o liste.o

main.o : main.c 
	$(CC) -o main.o -c main.c 


liste.o : liste.c
	$(CC) -o liste.o -c liste.c 