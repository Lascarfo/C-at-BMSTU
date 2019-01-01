CC := gcc
CFLAGS :=-std=c99 -Wall -Werror -pedantic

lib.so: lib.o
	gcc -shared -o $@ $^

%.o: %.c lib.h
	$(CC) $(CFLAGS) -fPIC -c $<

clean:
	rm -f *.o *.exe *.a *.so