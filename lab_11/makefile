CC := gcc
CFLAGS :=-std=c99 -Wall -Werror -pedantic

test.exe: test.o usage.o my_snprintf.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.exe