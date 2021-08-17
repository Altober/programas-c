#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tablero.h"
#include "fichas.h"
#include "ganador.h"
#include "jugada.h"

/*** Var Jugadas ***/
int fin = 0;

int main(int argc, char const *argv[])
{
	/*** Jugada ***/
	int nturno = 1;
	
	/*** Inicio del juego ***/
	iniciartablero();
        ConfigurarJugadores();
	mostrartablero();

	/*** Secuencia de turnos, el juego en sí ***/
	while(fin == 0){
		if(tablerolleno() == 1){
			printf("\n ¡Empate! Gracias por jugar, vuelvan a intentarlo.\n");
			fin = 1;		
		}else{
			/*** Muetra a que jugador corresponde el turno ***/
			if(nturno%2 == 1){
				printf("\n --Turno de %s.--",jugador1.nombrejugador);
				printf("\n");
				fichajugador = jugador1.caracterficha;
			}else{
				printf("\n --Turno de %s.--",jugador2.nombrejugador);
				printf("\n");
				fichajugador = jugador2.caracterficha;
			}	
	
			/*** Verificar si se cambia de turno ***/
			int turnoexitoso  = turnojugador(fichajugador,nturno,fin);
			if(turnoexitoso == 2){
				fin = 1;
			}

			/*** Finalizar el juego ***/
			if(fin == 1){
				if(nturno%2 == 1){
					printf("\n ¡Ha ganado %s! Felicitaciones y gracias por jugar. \n",jugador1.nombrejugador);
				}else{
					printf("\n ¡Ha ganado %s! Felicitaciones y gracias por jugar. \n",jugador2.nombrejugador);
				}
				
			}

			/*** Pasar al otro turno ***/
			nturno = nturno + turnoexitoso;	
			
		}
	}

	
	return 0;
}
