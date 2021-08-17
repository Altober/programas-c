
/*--- Turno del jugador ---*/
int turnojugador(char fichajugador, int nturno,int fin){
	int turno = 0;
	int finturno = 0;
	while(turno == 0){
		/*** Ingresar Columna ***/
		printf("\n Eliga un número del 1 al 7 para colocar su ficha: ");
		scanf("%i",&columna);
		printf("\n");
		/*** Verificar si el dato está bien ingresado ***/
		if(columna < 1 || columna > 7){
			printf("¡Columna no existe!, seleccione otra. \n");
			break;	
		}
		/*** Colocar ficha ***/
		else{	
			fila = filacorrespondiente(columna);

			if(fila > -1){
				tablero[fila-1][columna-1] = fichajugador;
				/*** Verificar si se gana el juego ***/
				finturno = verificarganador(fichajugador,fila,columna,-1);		
				turno = 1;
				break;			
			}else{	
				printf("¡Columna llena!, seleccione otra porfavor.\n");	
			}		
		}	
	}
	mostrartablero();
	return finturno;
	
}



