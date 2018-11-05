CC :=gcc
CFLAGS :=-std=c99 -Wall -Werror -pedantic

app.exe: main.o usage.o my_getline.o str_replace.o
	$(CC) $(CFLAGS) $^ -o $@

test.exe: test.o my_getline.o str_replace.o
	$(CC) $(CFLAGS) -g3 -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.exe
