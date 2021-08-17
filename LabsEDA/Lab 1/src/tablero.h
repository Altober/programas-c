int i,j;
int filas = 6 ;
int columnas = 7;
int columna = 0;
int fila = 0;
int retorno = 0;
char **tablero;

/*--- Crear Tablero ---*/
void iniciartablero()
{	
	tablero = (char **) malloc(sizeof(char *)*filas);

	for(i=0;i<filas;i++){	
		tablero[i] = (char *) malloc(sizeof(char)*columnas);
	}

	for(i=0;i<filas;i++){
		for(j=0;j<columnas;j++){
			tablero[i][j] = '.';	
		}	
	}	
}

/*--- Mostrar Tablero ---*/
void mostrartablero()
{	
	printf("\n ----------------------------------------- \n");
	printf(" Tablero");
	printf("\n");
	for(i=0;i<filas;i++){
		printf("%i ",i + 1);
		for(j=0;j<columnas;j++){
			printf("%c",tablero[i][j]);	
		}	
		printf("\n");
	}
	printf("  1234567 \n");
	printf(" ----------------------------------------- \n");
}

/*--- Verificar si la columna está llena ---*/
int columnallena(int columna){
	int filacorr = 0;
	for(i=0;i<6;i++){
		if(tablero[i][columna-1] != '.'){
			filacorr++;
		}
	}

	if(filacorr == 6){
		filacorr = -1;
	}else{
		filacorr = 0;
	}

	return filacorr;
}

/*--- Ver en que fila se debe poner la ficha---*/
int filacorrespondiente(int columna){
	int filacorr = 0;
	filacorr = columnallena(columna);
	if(filacorr > -1){
		for(i=0;i<6;i++){
			if(tablero[i][columna-1] == '.'){
				filacorr++;
			}
		}
	}
	return filacorr;
}

/*--- Verificar tablero lleno ---*/
int tablerolleno(){
	int nlleno = 1;
	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
			if(tablero[i][j] != '.'){
				nlleno++;
			}
		}
	}	
	
	if(nlleno > 42){	
		return 1;
	}else{
		return 0;
	}
}
