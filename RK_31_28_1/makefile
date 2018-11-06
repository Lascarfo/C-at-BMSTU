CC := gcc
PARAMS := -std=c99 -Wall -Werror -pedantic

app.exe: main.o io.o usage.o memory.o calculatings.o
	$(CC) $(PARAMS) $^ -o app.exe


test.exe: test.o calculatings.o
	$(CC) $(PARAMS) $^ -o $@

%.o: %.c *.h
	$(CC) $(PARAMS) -c $<

clean:
	rm -f *.exe *.o .DS_Store


