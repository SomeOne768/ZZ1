OPTIONS=-Wall -Wextra -g

prog:mon_code.o teZZt.o main.o
	gcc -o prog mon_code.o teZZt.o main.o
mon_code.o:mon_code.c mon_code.h
	gcc ${OPTIONS} mon_code.c -c
main.o:mon_code.h teZZt.h main.c
	gcc ${OPTIONS} main.c -c
teZZt.o:teZZt.h teZZt.c
	gcc -c teZZt.c
clean:
	rm -f mon_code. teZZt.o main.o *.gch