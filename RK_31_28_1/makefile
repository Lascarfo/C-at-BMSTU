CC := gcc
PARAMS := -std=c99 -Wall -Werror -pedantic

app.exe: main.o io.o usage.o memory.o calculatings.o
	$(CC) $(PARAMS) $^ -o app.exe


test.exe: main.o io.o usage.o
	$(CC) $(PARAMS) $^ -o app.exe

%.o: %.c *.h
	$(CC) $(PARAMS) -c $<


