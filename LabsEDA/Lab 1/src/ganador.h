int filad;
int columnad;

/*--- Verificar Diagonal Noroeste-Sureste ganadora ---*/
int verificardiagonalNoroeste(char fichajugador,int fila,int columna){
	int juntos = 0;
	filad = fila - 1; /* Disminuir para que sea fila de arreglo */
	columnad = columna - 1; /* Disminuir para que sea columna de arreglo */
	while(filad > -1 && columnad > -1)
	{
		if(tablero[filad][columnad] == fichajugador){
			juntos++;
		}else{
			if(juntos > 0 && tablero[filad][columnad] != '.'){
				juntos = 0;
			}
		}
		filad--;
		columnad--;
	}
	return juntos;
}

int verificardiagonalSureste(char fichajugador,int fila,int columna){
	int juntos = 0;
	filad = fila - 1; /* Disminuir para que sea fila de arreglo */
	columnad = columna - 1; /* Disminuir para que sea columna de arreglo */
	while(filad < 6 && columnad < 7)
	{
		if(tablero[filad][columnad] == fichajugador){
			juntos++;
		}else{
			if(juntos > 0 && tablero[filad][columnad] != '.'){
				juntos = 0;
			}
		}
		filad++;
		columnad++;
	}
	/*Resto 1 para descontar la fila-columna donde se está*/
	return juntos-1;
}

/*--- Verificar Diagonal Noreste-Suroeste ganadora ---*/
int verificardiagonalNoreste(char fichajugador,int fila,int columna){
	int juntos = 0;
	filad = fila - 1; /* Disminuir para que sea fila de arreglo */
	columnad = columna - 1; /* Disminuir para que sea columna de arreglo */
	while(filad > -1 && columnad < 7)
	{
		if(tablero[filad][columnad] == fichajugador){
			juntos++;
		}else{
			if(juntos > 0 && tablero[filad][columnad] != '.'){
				juntos = 0;
			}
		}
		filad--;
		columnad++;
	}
	return juntos;
}

int verificardiagonalSuroeste(char fichajugador,int fila,int columna){
	int juntos = 0;
	filad = fila - 1; /* Disminuir para que sea fila de arreglo */
	columnad = columna - 1; /* Disminuir para que sea columna de arreglo */
	while(filad < 6 && columnad > -1)
	{
		if(tablero[filad][columnad] == fichajugador){
			juntos++;
		}else{
			if(juntos > 0 && tablero[filad][columnad] != '.'){
				juntos = 0;
			}
		}
		filad++;
		columnad--;
	}
	/*Resto 1 para descontar la fila-columna donde se está*/
 	return juntos-1;
}

/*--- Verificar Fila ganadora ---*/
int verificarhorizontal(char fichajugador,int fila){
	int juntos = 0;
	for(j=0;j<7;j++){
		if(tablero[fila-1][j] == fichajugador){
			juntos++;
		}else{
			if(juntos > 0 && tablero[fila-1][j] != '.'){
				juntos = 0;
			}
		}
	}	
	/*--Ganó--*/
	if(juntos == 4){
		return 1;
	}

	return 0;
}

/*--- Verificar Columna ganadora ---*/
int verificarvertical(char fichajugador,int columna){
	int juntos = 0;
	for(i=0;i<6;i++){
		if(tablero[i][columna-1] == fichajugador){
			juntos++;
		}else{
			if(juntos > 0 && tablero[i][columna-1] != '.'){
				juntos = 0;
			}
		}
	}

	/*--Ganó--*/
	if(juntos == 4){
		return 1;
	}

	return 0;
}

/*--- Verificar si alguna diagona tiene las 4 fichas ---*/
int verificardiagonales(char fichajugador,int fila,int columna)
{
	int suma = 0;
	/*--Suma diagonal Noroeste-Sureste--*/
		suma = verificardiagonalNoroeste(fichajugador,fila,columna);
		suma = suma + verificardiagonalSureste(fichajugador,fila,columna);
	if(suma < 4){
	/*--Suma diagonal Noreste-Suroeste--*/
		suma = verificardiagonalNoreste(fichajugador,fila,columna);
		suma = suma + verificardiagonalSuroeste(fichajugador,fila,columna);
	}

	/*--Ganó--*/
	if(suma == 4)
	{
		return 1;
	}
	return 0;
}

/*--- Verificar Ganador ---*/
int verificarganador(char fichajugador,int fila,int columna,int gano){
	if(gano != -1){
		return gano;
	}
	else{
		gano = verificarhorizontal(fichajugador,fila);

		if(gano == 0){
			gano = verificarvertical(fichajugador,columna);
		}

		if(gano == 0){
			gano = verificardiagonales(fichajugador,fila,columna);
		}
		
		return verificarganador(fichajugador,fila,columna,gano + 1);
		
	}
}


