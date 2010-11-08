CC = gcc
CFLAGS = -g -Wall -lm
BIN = tp5
XFLAGSA = < ./entrada/p
XFLAGSB = < ./entrada/m
XFLAGSC = < ./entrada/g
XFLAGSD = < ./entrada/pp
SAIDAS = p m g
RM = *.o *.h.gch $(BIN) $(SAIDAS)

camadas: camadas.c camadas.h
	$(CC) -c camadas.c camadas.h $(CFLAGS)
	
simulacao: simulacao.c simulacao.h
	$(CC) -c simulacao.c simulacao.h $(CFLAGS)

main: camadas simulacao
	$(CC) -o $(BIN) tp5.c camadas.o simulacao.o $(CFLAGS)

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
