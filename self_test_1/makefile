main.exec: main.o read.o print.o usage.o findnum.o
	gcc -std=c99 -Wall -Werror -o main.exec main.o read.o print.o usage.o findnum.o

main.o: const.h read.h print.h usage.h main.c
	gcc -std=c99 -c main.c

read.o: read.c const.h
	gcc -std=c99 -c read.c

print.o: print.c
	gcc -std=c99 -c print.c

usage.o: usage.c
	gcc -std=c99 -c usage.c

findnum.o: findnum.c
	gcc -std=c99 -c findnum.c

clean:
	rm -f *.o *.exec
