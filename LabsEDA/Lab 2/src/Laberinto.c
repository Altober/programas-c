#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pisos.h"
#include "Recorrido.h"


int main(int argc, char const *argv[])
{
	int pisocargado = 1;

	while(pisocargado < 4){
		switch(pisocargado){
			case 1:
				LeerPiso("./src/Pisos/piso1.txt");
				printf("--Piso 1--\n");
				MostrarPiso();
				Recorrer(piso,1,1,0);
				break;
			case 2:
				LeerPiso("./src/Pisos/piso2.txt");
				printf("--Piso 2--\n");
				MostrarPiso();
				Recorrer(pisocopia,2,1,1);
				Recorrer(piso,2,1,0);
				break;
			case 3:
				LeerPiso("./src/Pisos/piso3.txt");
				printf("--Piso 3--\n");
				MostrarPiso();
				Recorrer(piso,3,1,0);
				break;
		}
		pisocargado++;
	}
		
	pisocargado = 3;
	while(pisocargado > 0){
		switch(pisocargado){
			case 1:
				LeerPiso("./src/Pisos/piso1.txt");
				Recorrer(piso,1,2,0);
				break;
			case 2:
				LeerPiso("./src/Pisos/piso2.txt");
				Recorrer(piso,2,2,0);
				break;
			case 3:
				LeerPiso("./src/Pisos/piso3.txt");
				Recorrer(piso,3,2,0);
				break;
		}
		pisocargado--;
	}
	
/*---
	switch(pisocargado){
			case 1:
				LeerPiso("./src/Pisos/piso1.txt");
				Recorrer(piso,1,2,0);
				break;
			case 2:
				LeerPiso("./src/Pisos/piso2.txt");
				Recorrer(piso,2,2,0);
				break;
			case 3:
				LeerPiso("./src/Pisos/piso3.txt");
				Recorrer(piso,3,2,0);
				break;
	}
		---*/

	printf("¡Tesoro encontrado y recuperado! Revise el texto de salida para ver el camino.\n");
	return 0;
}
