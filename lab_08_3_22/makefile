CC := gcc
CFLAGS :=-std=c99 -Wall -Werror -pedantic

app.exec: main.o usage.o io.o calculatings.o
	$(CC) $(CFLAGS) -o $@ $^

test.exeс: test.o filter.o sort.o io.o
	$(CC) $(CFLAGS) -g3 -o $@ $^

time.exeс: time.o sort.o io.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.exeс