CC := gcc
CFLAGS :=-std=c99 -Wall -Werror -pedantic

app.exe: main.o usage.o io.o calculatings.o
	$(CC) $(CFLAGS) -o $@ $^

test.exe: test.o filter.o sort.o io.o
	$(CC) $(CFLAGS) -g3 -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.exe