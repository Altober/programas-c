char nombre[20];
char ficha;
int config = 0;
char opcion;

struct ficha
{
	int numerojugador;
	char nombrejugador[20];
	char caracterficha;	
};

struct ficha jugador1;
struct ficha jugador2;
char fichajugador;

/*--- Crear primer jugador ---*/
void crearjugador1(char opcion){	
	switch(opcion){
		case 'u':
			jugador1.numerojugador = 1;
			printf("\n Nombre jugador 1: ");
			scanf("%s",nombre);
			strcpy(jugador1.nombrejugador,nombre);
			printf("\n ----------------------------------------- \n");
			break;
		case 'k':
			printf("\n Ficha jugador 1: ");
			scanf(" %c",&ficha);
			jugador1.caracterficha = ficha;
			printf("\n ----------------------------------------- \n");
			break;
	}	
}

/*--- Crear segundo jugador ---*/
void crearjugador2(char opcion){	
	
	switch(opcion){
		case 't':
			jugador2.numerojugador = 2;
			printf("\n Nombre jugador 2: ");
			scanf("%s",nombre);
			strcpy(jugador2.nombrejugador,nombre);
			printf("\n ----------------------------------------- \n");
			break;
		case 'j':
			printf("\n Ficha jugador 2: ");
			scanf(" %c",&ficha);
			jugador2.caracterficha = ficha;
			printf("\n ----------------------------------------- \n");
			break;
	}
}

/*--- Configuración de los jugadores, se deben seleccionar todas las opciones al menoz una vez para ir al juego ---*/
void ConfigurarJugadores(){

	while(config == 0){
		printf("\n ----------------------------------------- \n");
		printf("\n--Configuración de jugadores.--\n");
		printf("Debe ingresar todos los datos para ir al juego. \n");
		printf("Seleccione una opción (ingrese letra):\n");
		printf("u --> Nombre jugador 1.\n");
		printf("t --> Nombre jugador 2.\n");
		printf("k --> Ficha jugador 1.\n");
		printf("j --> Ficha jugador 2.\n");
		printf("Ingrese su opción:\n");
		scanf(" %c",&opcion);
		switch(opcion){
			case 'u':
				crearjugador1(opcion);
				break;
			case 't':
				crearjugador2(opcion);
				break;
			case 'k':
				crearjugador1(opcion);
				break;
			case 'j':
				crearjugador2(opcion);
				break;
			default:
				break;
		}
		/*--- Verifica si se llenaron todos los campos de jugador ---*/
		if(jugador1.numerojugador == 0 || jugador1.caracterficha == '\0' || jugador2.numerojugador == 0 || jugador2.caracterficha == '\0')
		{
			config = 0;
		}else{
			config = 1;
		}	
		
	}

}


