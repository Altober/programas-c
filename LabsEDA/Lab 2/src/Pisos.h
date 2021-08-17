int i,j,fila,columna,filas,columnas;
char caracter;
char* cadena;
FILE *pisotxt,*salidatxt;
char buff[255];	
char salida[50];
char **piso;
char **pisocopia;

/*--- Crear Piso ---*/
void CrearPiso(){	
	piso = (char **) malloc(sizeof(char *)*filas);

	for(i=0;i<filas;i++){	
		piso[i] = (char *) malloc(sizeof(char)*columnas);
	}
	
	pisocopia = (char **) malloc(sizeof(char *)*filas);

	for(i=0;i<filas;i++){	
		pisocopia[i] = (char *) malloc(sizeof(char)*columnas);
	}	
}

/*--- Borrar Piso ---*/
void BorrarPiso(){	
	free(piso);	
	free(pisocopia);
}

/*--- Llenar Piso ---*/
void LlenarPiso(){
	for(i=0;i<filas;i++){
		fgets(buff,255,(FILE*)pisotxt);
		for(j=0;j<columnas;j++){	
			piso[i][j] = buff[j];	
			pisocopia[i][j] = buff[j];
		}
	}
}

/*--- Mostrar Piso ---*/
void MostrarPiso()
{	   
	for(i=0;i<filas;i++){
		for(j=0;j<columnas;j++){
			printf("%c",piso[i][j]);	
		}	
		printf("\n");	
	}
	printf("\n");
}

void MostrarPisoCopia()
{	   
	for(i=0;i<filas;i++){
		for(j=0;j<columnas;j++){
			printf("%c",pisocopia[i][j]);	
		}	
		printf("\n");	
	}
	printf("\n");
}

/*--- Identificar inicio ---*/
void InicioPiso(int pisoact,int camino){
    	/*  -- Búsqueda -- */
	if(camino == 1){
		if(pisoact == 1){
			salida[0] = 'I';
			for(i=0;i<filas;i++){
				for(j=0;j<columnas;j++){
					if(piso[i][j] == 'I'){
						fila = i;
						columna = j;		
					}	
				}
			}
		}else if(pisoact == 2){
			salida[0] = 'K';
			for(i=0;i<filas;i++){
				for(j=0;j<columnas;j++){
					if(piso[i][j] == 'L'){
						fila = i;
						columna = j;		
					}	
				}
			}
		}else{
			salida[0] = 'B';
			for(i=0;i<filas;i++){
				for(j=0;j<columnas;j++){
					if(piso[i][j] == 'B'){
						fila = i;
						columna = j;		
					}	
				}
			}
		}
	}else if(camino == 2){
	/*  -- Regreso -- */
		if(pisoact == 3){
			salida[0] = 'C';
			for(i=0;i<filas;i++){
				for(j=0;j<columnas;j++){
					if(piso[i][j] == 'T'){
						fila = i;
						columna = j;		
					}	
				}
			}
		}else{
			salida[0] = 'S';
			for(i=0;i<filas;i++){
				for(j=0;j<columnas;j++){
					if(piso[i][j] == 'S'){
						fila = i;
						columna = j;		
					}	
				}
			}
		}
	}else{
	/*  -- Búsqueda Llave --*/
		salida[0] = 'B';
		for(i=0;i<filas;i++){
			for(j=0;j<columnas;j++){
				if(piso[i][j] == 'B'){
					fila = i;
					columna = j;		
				}	
			}
		}
	}
}


/*--- Leer Txt ---*/
void LeerPiso(char* archivo){
	
	pisotxt = fopen(archivo,"r");

	if(pisotxt){
		
		/*--- Obtener tamaño matriz ---*/
		char* texto[2];
		int linea = 0;
		while((cadena = fgets(buff,255,(FILE*)pisotxt)) != NULL){
			texto[linea] = strdup(cadena);
			linea ++;

			if(linea > 1){
				break;			
			}		
		}

		filas = atoi(texto[0]);
		columnas = atoi(texto[1]);

		/*--- Métodos laberinto ---*/
		BorrarPiso();
		CrearPiso();
		LlenarPiso();
		fclose(pisotxt);
	}
}

/*--- Limpiar Arreglo ---*/
void EliminarArreglo(){
	for(i=0;i<50;i++){
		salida[i] = '\0';
	}
}

/*--- Escribir salida en Txt ---*/
void EscribirPiso(int piso,int camino,int llave){
	
	if(piso == 1 && camino == 1){
		salidatxt = fopen("./build/camino.txt","w");
	}else{
		salidatxt = fopen("./build/camino.txt","a");
	}

	if(pisotxt){
		if(camino == 1){
			if(llave == 1){
				fprintf(salidatxt,"\n--Búsqueda llave Piso %i--\n",piso);			
			}else if(piso == 3){
				fprintf(salidatxt,"\n--Búsqueda tesoro Piso %i--\n",piso);
			}else{
				fprintf(salidatxt,"\n--Búsqueda subida Piso %i--\n",piso);
			}
		}else {
			if(piso == 1){
				fprintf(salidatxt,"\n--Búsqueda inicio Piso %i--\n",piso);
			}else{
				fprintf(salidatxt,"\n--Búsqueda bajada Piso %i--\n",piso);
			}
		}
		switch(salida[0]){
			case 'I':
				switch(salida[i+1]){
					case 'S':
						fprintf(salidatxt,"-Inicio ¡Escalera Subida!\n");			
						break;
					case 'B':
						fprintf(salidatxt,"-Inicio ¡Escalera Bajada!\n");			
						break;
					case 'K':
						fprintf(salidatxt,"-Inicio ¡LLave!\n");
						break;
					case 'C':
						fprintf(salidatxt,"-Inicio ¡Tesoro!\n");
						break;
					default:
						fprintf(salidatxt,"-Inicio\n");
						break;
				}
				break;
			case 'S':
				switch(salida[i+1]){
					case 'I':
						fprintf(salidatxt,"-Escalera Subida ¡Inicio!\n");		
						break;
					case 'B':
						fprintf(salidatxt,"-Escalera Subida ¡Escalera Bajada!\n");			
						break;
					case 'K':
						fprintf(salidatxt,"-Escalera Subida ¡LLave!\n");
						break;
					case 'C':
						fprintf(salidatxt,"-Escalera Subida ¡Tesoro!\n");
						break;
					default:
						fprintf(salidatxt,"-Escalera Subida\n");
						break;
				}
				break;
			case 'B':
				switch(salida[i+1]){
					case 'S':
						fprintf(salidatxt,"-Escalera Bajada ¡Escalera Subida!\n");			
						break;
					case 'I':
						fprintf(salidatxt,"-Escalera Bajada ¡Inicio!\n");			
						break;
					case 'K':
						fprintf(salidatxt,"-Escalera Bajada ¡LLave!\n");
						break;
					case 'C':
						fprintf(salidatxt,"-Escalera Bajada ¡Tesoro!\n");
						break;
					default:
						fprintf(salidatxt,"-Escalera Bajada\n");
						break;
				}
				break;
			case 'K':
				switch(salida[i+1]){
					case 'S':
						fprintf(salidatxt,"-LLave ¡Escalera Subida!\n");			
						break;
					case 'B':
						fprintf(salidatxt,"-LLave ¡Escalera Bajada!\n");			
						break;
					case 'I':
						fprintf(salidatxt,"-LLave ¡Inicio!\n");
						break;
					case 'C':
						fprintf(salidatxt,"-LLave ¡Tesoro!\n");
						break;
					default:
						fprintf(salidatxt,"-LLave\n");
						break;
				}
				break;
			case 'C':
				switch(salida[i+1]){
					case 'S':
						fprintf(salidatxt,"-Tesoro ¡Escalera Subida!\n");			
						break;
					case 'B':
						fprintf(salidatxt,"-Tesoro ¡Escalera Bajada!\n");			
						break;
					case 'K':
						fprintf(salidatxt,"-Tesoro ¡LLave!\n");
						break;
					case 'I':
						fprintf(salidatxt,"-Tesoro ¡Inicio!\n");
						break;
					default:
						fprintf(salidatxt,"-Tesoro\n");
						break;
				}
				break;
		}

		for(i=1;i<50;i++){
			if(salida[i] != '\0'){
				switch(salida[i]){
					case 'U':
						switch(salida[i+1]){
							case 'S':
								fprintf(salidatxt,"-Arriba ¡Escalera Subida!\n");			
								break;
							case 'B':
								fprintf(salidatxt,"-Arriba ¡Escalera Bajada!\n");			
								break;
							case 'K':
								fprintf(salidatxt,"-Arriba ¡LLave!\n");
								break;
							case 'C':
								fprintf(salidatxt,"-Arriba ¡Tesoro!\n");
								break;
							case 'I':
								fprintf(salidatxt,"-Arriba ¡Inicio!\n");
								break;
							default:
								fprintf(salidatxt,"-Arriba\n");
								break;
						}			
						break;
					case 'D':
						switch(salida[i+1]){
							case 'S':
								fprintf(salidatxt,"-Abajo ¡Escalera Subida!\n");			
								break;
							case 'B':
								fprintf(salidatxt,"-Abajo ¡Escalera Bajada!\n");			
								break;
							case 'K':
								fprintf(salidatxt,"-Abajo ¡LLave!\n");
								break;
							case 'C':
								fprintf(salidatxt,"-Abajo ¡Tesoro!\n");
								break;
							case 'I':
								fprintf(salidatxt,"-Abajo ¡Inicio!\n");
								break;
							default:
								fprintf(salidatxt,"-Abajo\n");
								break;
						}		
						break;
					case 'R':
						switch(salida[i+1]){
							case 'S':
								fprintf(salidatxt,"-Derecha ¡Escalera Subida!\n");			
								break;
							case 'B':
								fprintf(salidatxt,"-Derecha ¡Escalera Bajada!\n");			
								break;
							case 'K':
								fprintf(salidatxt,"-Derecha ¡LLave!\n");
								break;
							case 'C':
								fprintf(salidatxt,"-Derecha ¡Tesoro!\n");
								break;
							case 'I':
								fprintf(salidatxt,"-Derecha ¡Inicio!\n");
								break;
							default:
								fprintf(salidatxt,"-Derecha\n");
								break;
						}			
						break;
					case 'L':
						switch(salida[i+1]){
							case 'S':
								fprintf(salidatxt,"-Izquierda ¡Escalera Subida!\n");			
								break;
							case 'B':
								fprintf(salidatxt,"-Izquierda ¡Escalera Bajada!\n");			
								break;
							case 'K':
								fprintf(salidatxt,"-Izquierda ¡LLave!\n");
								break;
							case 'C':
								fprintf(salidatxt,"-Izquierda ¡Tesoro!\n");
								break;
							case 'I':
								fprintf(salidatxt,"-Izquierda ¡Inicio!\n");
								break;
							default:
								fprintf(salidatxt,"-Izquierda\n");
								break;
						}			
						break;
					default:
						break;
				}
			}
		}

		fclose(salidatxt);
		EliminarArreglo();
	}
}







