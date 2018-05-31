GCC := gcc

PARAM := -std=c99 -Wall -Werror -pedantic

main.exec: main.o usage.o minimum.o field.o
	$(GCC) $(PARAM) -o main.exec main.o usage.o minimum.o field.o

test.exec: test.o minimum.o field.o
	$(GCC) $(PARAM) -o test.exec test.o minimum.o field.o

test.o: test.c field.h minimum.h const.h
	$(GCC) $(PARAM) -c test.c
	

clean:
	rm -f *.o *.exec

main.o: main.c usage.h field.h const.h
	$(GCC) $(PARAM) -c main.c

usage.o: usage.c
	$(GCC) $(PARAM) -c usage.c

minimum.o: minimum.c
	$(GCC) $(PARAM) -c minimum.c

field.o: field.c minimum.h const.h
	$(GCC) $(PARAM) -c field.c

