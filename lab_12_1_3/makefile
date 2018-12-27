CC := gcc
CFLAGS :=-std=c99 -Wall -Werror -pedantic

stat: lib.a main_include.c
	$(CC) $(CFLAGS) main_include.c -o app.exe lib.a

dyn_c: lib.so main_include.c
	$(CC) $(CFLAGS) -c main_include.c 
	gcc main.o -L. lib.so -o app.exe 


dyn_l: lib.so main_no_include.c
	$(CC) $(CFLAGS) -ldl main_no_include.c -o app.exe 

lib.so: usage.o io.o filter.o sort.o
	gcc -shared -o $@ $^

lib.a: usage.o io.o filter.o sort.o
	ar rc $@ $^ 
	ranlib lib.a

%.o: %.c lib.h
	$(CC) $(CFLAGS) -fPIC -c $<

clean:
	rm -f *.o *.exe *.a *.so