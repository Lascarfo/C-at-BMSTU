GCC := gcc -std=c99
PARAMS := -Wall -Werror -pedantic

app.exe: main.o usage.o io.o list.o
	$(GCC) $(PARAMS) $^ -o app.exe

%.o: %.c *.h
	$(GCC) $(PARAMS) -c $<

clean:
	rm -f *.exe *.o