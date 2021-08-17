DIRO = ./build
DIRI = ./src
CC= gcc
CFLAGS = -g -msse3

all: borrar crear

crear: 
	mkdir -p $(DIRO)
	$(CC) $(CFLAGS)  $(DIRI)/Connect4.c -o $(DIRO)/Connect4

borrar:
	rm -rf $(DIRO)/*
