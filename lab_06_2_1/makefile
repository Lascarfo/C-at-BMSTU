GCC := gcc

PARAM := -std=c99 -Wall -Werror -pedantic

main.exec: main.o
	$(GCC) $(PARAM) -o main.exec main.o

clean:
	rm -f *.o *.exec

main.o: main.c 
	$(GCC) $(PARAM) -c main.c

usage.o: usage.c
	$(GCC) $(PARAM) -c usage.c

minimum.o: minimum.c
	$(GCC) $(PARAM) -c minimum.c

field.o: field.c
	$(GCC) $(PARAM) -c field.c

