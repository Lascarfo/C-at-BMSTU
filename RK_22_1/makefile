GCC := gcc

PARAM := -std=c99

app.exe: main.o read_f.o pick_f.o
	$(GCC) $(PARAM) -o main.exe main.o read_f.o pick_f.o

clean:
	rm -f *.o *.exe

main.o: main.c err_lib.h read_f.h pick_f.h
	$(GCC) $(PARAM) -c main.c

pick_f.o: pick_f.c pick_f.h
	$(GCC) $(PARAM) -c pick_f.c

read_f.o: read_f.c read_f.h
	$(GCC) $(PARAM) -c read_f.c
