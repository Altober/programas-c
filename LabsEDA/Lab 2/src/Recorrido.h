int llave,cofre,subida;
int bajada = 0;
int existe = 0;

/*--- Recorrer Piso ---*/
int BuscarFin(char** piso,int filax,int columnax,int pisoactx,int cont){
	if(cont == 1){
		existe = 0;
		subida = 0;
		cofre = 0;
	}
	/*--- Encontrar inicio en arreglo ---*/
	int numk;
	for(i=0;i<50;i++){
		if(salida[i] == 'S' || salida[i] == 'C'){
			existe = 1;
			numk = i;
			break;	
		}
	}
	/*--- Salida Piso 1 y 2 ---*/
	if((pisoactx == 1 || pisoactx == 2) && subida == 1){ 
		for(i=numk+1;i<50;i++){
			salida[i] = '\0';
		}		
		return 1;
	}
	/*--- Salida Piso 3 ---*/	
	 if(pisoactx == 3 && cofre == 1){
		for(i=numk+1;i<50;i++){
			salida[i] = '\0';
		}	
		return 1;
	}
	piso[filax][columnax] = 'V';
	/*--- Bajar ---*/
	if(filax + 1 < filas && piso[filax+1][columnax] != 'M' && piso[filax+1][columnax] != 'V'){
		if(salida[cont] == '\0' || existe != 1){
			salida[cont] = 'D';
		}
		if(piso[filax+1][columnax] == 'S'){
			subida = 1;
			salida[cont+1] = 'S';
		}
		if(piso[filax+1][columnax] == 'T'){	
			cofre = 1;
			salida[cont+1] = 'C';
		}
		BuscarFin(piso,filax+1,columnax,pisoactx,cont+1);	
	}
	/*--- Subir ---*/
	if(filax - 1 >= 0 && piso[filax-1][columnax] != 'M' && piso[filax-1][columnax] != 'V'){
		if(salida[cont] == '\0' || existe != 1){
			salida[cont] = 'U';
		}
		if(piso[filax-1][columnax] == 'S'){
			subida = 1;
			salida[cont+1] = 'S';
		}
		if(piso[filax-1][columnax] == 'T'){
			cofre = 1;
			salida[cont+1] = 'C';
		}	
		BuscarFin(piso,filax-1,columnax,pisoactx,cont+1);		
	}
	/*--- Derecha ---*/
	if(columnax + 1 < columnas && piso[filax][columnax+1] != 'M' && piso[filax][columnax+1] != 'V'){
		if(salida[cont] == '\0' || existe != 1){
			salida[cont] = 'R';
		}
		if(piso[filax][columnax+1] == 'S'){
			subida = 1;
			salida[cont+1] = 'S';
		}
		if(piso[filax][columnax+1] == 'T'){
			cofre = 1;
			salida[cont+1] = 'C';
		}
		BuscarFin(piso,filax,columnax+1,pisoactx,cont+1);		
	}
	/*--- Izquierda ---*/
	if(columnax - 1 >= 0 && piso[filax][columnax-1] != 'M' && piso[filax][columnax-1] != 'V'){
		if(salida[cont] == '\0' || existe != 1){
			salida[cont] = 'L';
		}
		if(piso[filax][columnax-1] == 'S'){
			subida = 1;
			salida[cont+1] = 'S';
		}
		if(piso[filax][columnax-1] == 'T'){
			cofre = 1;
			salida[cont+1] = 'C';
		}
		BuscarFin(piso,filax,columnax-1,pisoactx,cont+1);
	}
	return 0;

}

/*--- Buscar Llave ---*/
int BuscarLlAvE(char** pisocopia,int filax,int columnax,int cont){
	if(cont == 1){
		existe = 0;
		llave = 0;
	}
	/*--- Encontrar Llave en arreglo ---*/
	int numk;
	for(i=0;i<50;i++){
		if(salida[i] == 'K'){
			existe = 1;
			numk = i;
			break;	
		}
	}
	/*--- Borrar datos arreglo después de la llave ---*/
	if(llave == 1){ 
		for(i=numk+1;i<50;i++){
			salida[i] = '\0';
		}		
		return 1;
	}
	pisocopia[filax][columnax] = 'V';
	/*--- Bajar ---*/
	if(filax + 1 < filas && pisocopia[filax+1][columnax] != 'M' && pisocopia[filax+1][columnax] != 'V'){
		if(salida[cont] == '\0' || existe != 1){
			salida[cont] = 'D';
		}
		if(pisocopia[filax+1][columnax] == 'L'){
			llave = 1;
			salida[cont+1] = 'K';
		}
		BuscarLlAvE(pisocopia,filax+1,columnax,cont+1);	
	}
	/*--- Subir ---*/
	if(filax - 1 >= 0 && pisocopia[filax-1][columnax] != 'M' && pisocopia[filax-1][columnax] != 'V'){
		if(salida[cont] == '\0' || existe != 1){
			salida[cont] = 'U';
		}
		if(pisocopia[filax-1][columnax] == 'L'){
			llave = 1;
			salida[cont+1] = 'K';
		}	
		BuscarLlAvE(pisocopia,filax-1,columnax,cont+1);		
	}
	/*--- Derecha ---*/
	if(columnax + 1 < columnas && pisocopia[filax][columnax+1] != 'M' && pisocopia[filax][columnax+1] != 'V'){
		if(salida[cont] == '\0' || existe != 1){
			salida[cont] = 'R';
		}
		if(pisocopia[filax][columnax+1] == 'L'){
			llave = 1;
			salida[cont+1] = 'K';
		}
		BuscarLlAvE(pisocopia,filax,columnax+1,cont+1);		
	}
	/*--- Izquierda ---*/
	if(columnax - 1 >= 0 && pisocopia[filax][columnax-1] != 'M' && pisocopia[filax][columnax-1] != 'V'){
		if(salida[cont] == '\0' || existe != 1){
			salida[cont] = 'L';
		}
		if(pisocopia[filax][columnax-1] == 'L'){
			llave = 1;
			salida[cont+1] = 'K';
		}
		BuscarLlAvE(pisocopia,filax,columnax-1,cont+1);
	}
	return 0;

}

/*--- Regresar al inicio ---*/
int BuscarInicio(char** piso,int filax,int columnax,int pisoactx,int cont){
	if(cont == 1){
		existe = 0;
		bajada = 0;
	}
	/*--- Encontrar inicio en arreglo ---*/
	int numk;
	for(i=0;i<50;i++){
		if(salida[i] == 'B' || salida[i] == 'I'){
			existe = 1;
			numk = i;
			break;	
		}
	}
	/*--- Salida Piso 1, 2 y 3 ---*/
	if(bajada == 1){ 
		for(i=numk+1;i<50;i++){
			salida[i] = '\0';
		}			
		return 1;
	}
	piso[filax][columnax] = 'V';
	/*--- Bajar ---*/
	if(filax + 1 < filas && piso[filax+1][columnax] != 'M' && piso[filax+1][columnax] != 'V'){
		if(salida[cont] == '\0' || existe != 1){
			salida[cont] = 'D';
		}
		if(piso[filax+1][columnax] == 'B'){
			bajada = 1;
			salida[cont+1] = 'B';
		}
		if(piso[filax+1][columnax] == 'I'){
			bajada = 1;
			salida[cont+1] = 'I';
		}
		BuscarInicio(piso,filax+1,columnax,pisoactx,cont+1);	
	}
	/*--- Subir ---*/
	if(filax - 1 >= 0 && piso[filax-1][columnax] != 'M' && piso[filax-1][columnax] != 'V'){
		if(salida[cont] == '\0' || existe != 1){
			salida[cont] = 'U';
		}
		if(piso[filax-1][columnax] == 'B'){
			bajada = 1;
			salida[cont+1] = 'B';
		}	
		if(piso[filax-1][columnax] == 'I'){
			bajada = 1;
			salida[cont+1] = 'I';
		}	
		BuscarInicio(piso,filax-1,columnax,pisoactx,cont+1);		
	}
	/*--- Derecha ---*/
	if(columnax + 1 < columnas && piso[filax][columnax+1] != 'M' && piso[filax][columnax+1] != 'V'){
		if(salida[cont] == '\0' || existe != 1){
			salida[cont] = 'R';
		}
		if(piso[filax][columnax+1] == 'B'){
			bajada = 1;
			salida[cont+1] = 'B';
		}
		if(piso[filax][columnax+1] == 'I'){
			bajada = 1;
			salida[cont+1] = 'I';
		}
		BuscarInicio(piso,filax,columnax+1,pisoactx,cont+1);		
	}
	/*--- Izquierda ---*/
	if(columnax - 1 >= 0 && piso[filax][columnax-1] != 'M' && piso[filax][columnax-1] != 'V'){
		if(salida[cont] == '\0' || existe != 1){
			salida[cont] = 'L';
		}
		if(piso[filax][columnax-1] == 'B'){
			bajada = 1;
			salida[cont+1] = 'B';
		}
		if(piso[filax][columnax-1] == 'I'){
			bajada = 1;
			salida[cont+1] = 'I';
		}
		BuscarInicio(piso,filax,columnax-1,pisoactx,cont+1);
	}
	return 0;

}

void Recorrer(char** pisox,int pisoactx,int camino,int llavex){
	/*--- Búsqueda tesoro ---*/
	if(camino == 1){
		if(llavex == 1 && pisoactx == 2){
			InicioPiso(pisoactx,3);
			BuscarLlAvE(pisox,fila,columna,1);
		}else{
			InicioPiso(pisoactx,camino);
			BuscarFin(pisox,fila,columna,pisoactx,1);
		}
	}
	/*--- Regreso al inicio---*/
	else{
		InicioPiso(pisoactx,camino);
		BuscarInicio(pisox,fila,columna,pisoactx,1);
	}
	
	EscribirPiso(pisoactx,camino,llavex);

}






