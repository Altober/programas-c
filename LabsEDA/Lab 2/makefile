DIRO = ./build
DIRI = ./src
CC= gcc
CFLAGS = -g -msse3

all: borrar crear

crear: 
	mkdir -p $(DIRO)
	$(CC) $(CFLAGS)  $(DIRI)/Laberinto.c -o $(DIRO)/Laberinto

borrar:
	rm -rf $(DIRO)/*
