CC := gcc
CFLAGS :=-std=c99 -Wall -Werror -pedantic

app.exe: main.o usage.o io.o filter.o sort.o
	$(CC) $(CFLAGS) -o $@ $^

test.exe: test.o filter.o sort.o io.o
	$(CC) $(CFLAGS) -g3 -o $@ $^

time.exe: time.o sort.o io.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.exe
