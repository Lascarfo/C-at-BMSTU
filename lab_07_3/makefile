CC := gcc
CFLAGS :=-std=c99 -Wall -Werror -pedantic

main.exec: main.o usage.o io.o filter.o sort.o
	$(CC) $(CFLAGS) -o $@ $^

test.exec: test.o filter.o sort.o io.o
	$(CC) $(CFLAGS) -g3 -o $@ $^

time.exec: time.o sort.o io.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.exec
