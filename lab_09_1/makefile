CC :=gcc
CFLAGS :=-std=c99 -Wall -Werror -pedantic


test.exe: test.o my_string.o
	$(CC) $(CFLAGS) -g3 -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.exe