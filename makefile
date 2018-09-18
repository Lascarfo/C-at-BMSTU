CC := gcc
CFLAGS := -m32 -std=c99 -Wall -Werror -pedantic

main.exeс: main.o usage.o io.o filter.o sort.o
	$(CC) $(CFLAGS) -o main.exec $^

test.exec: test.o filter.o sort.o io.o
	$(CC) $(CFLAGS) -g3 -o test.exec $^
	
%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean: 
	rm -f *.o *.exec