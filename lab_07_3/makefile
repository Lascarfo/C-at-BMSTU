CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic

app.exe: main.o usage.o io.o filter.o sort.o
	$(CC) $(CFLAGS) -o app.exe $^

test.exe: test.o filter.o sort.o io.o
	$(CC) $(CFLAGS) -g3 -o test.exe $^
	
%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean: 
	rm -f *.o *.exe