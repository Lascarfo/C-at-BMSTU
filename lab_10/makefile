CC := gcc
CFLAGS :=-std=c99 -Wall -Werror -pedantic

app.exe: main.o io.o list.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.exe