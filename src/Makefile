CC = gcc
CFLAGS = -g -Wall -lm
BIN = tp5
XFLAGSA = < ./entrada/p
XFLAGSB = < ./entrada/m
XFLAGSC = < ./entrada/g
XFLAGSD = < ./entrada/pp
SAIDAS = p m g
RM = *.o *.h.gch $(BIN) $(SAIDAS)

io: io.c io.h
	$(CC) -c io.c io.h $(CFLAGS)

main: io tp5.c
	$(CC) -o $(BIN) tp5.c io.o $(CFLAGS)

m: clean main
	./$(BIN) $(XFLAGSB)

p: clean main
	./$(BIN) $(XFLAGSA)
	
pp: clean main
	./$(BIN) $(XFLAGSD)

g: clean main
	./$(BIN) $(XFLAGSC)

valgrind: clean main
	valgrind ./$(BIN) $(XFLAGSA)
all: main

clean:
	rm -rf $(RM)

run: clean main
	./$(BIN) $(XFLAGSA)
