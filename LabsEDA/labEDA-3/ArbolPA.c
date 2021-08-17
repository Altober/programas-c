/*------------------------------------------------------------------- */
/* Lab Estructuras de datos 2 - Laboratorio de Grafos" - V. 1.0       */
/* Alumno Alberto San Martin C - Universidad de Santiago              */
/*------------------------------------------------------------------- */

/*---------------------Descripcion de Problema----------------------- */
/*
Se necesita realizar una demostracion del Algoritmo de DIJKSTRA
(DJIKSTRA ALGORITHM) para encontrar el camino mas optimo que debe realizar 
Pedro (Vendedor) y asi poder realizar mas ventas haciendo de esta forma mas eficiente
su traslado de un lugar a otro. 
También es necesario realizar una comparación entre la metodologia utilizada por Pedro
y la propuesta el hecha por autor de este trabajo. Es decir, mostrar la diferencia
en cuanto a tiempos utilizados por ambas formas de trabajo.
*/

/**************************************************************************************************
 Pruebas y Código fuente probado en :
 Mac Osx
 Windows SubsistemLinux (SO: Ubuntu)
***************************************************************************************************/

#include <stdio.h>

#define MAX 1024


int main(){

    char *filename = "testEntrada.txt";
    FILE *fp = fopen(filename, "r");
    int count=0;
    if (fp == NULL){

        printf("Error: No se pudo abrir archivo %s", filename);
        return 1;

    }else{
        // Leer un caracter a la vez y
        // mostrar hacia la salida
        char ch;
        
        while ((ch = fgetc(fp)) != EOF){
            putchar(ch);
            count++;
        }
                    
        printf("\n");
        // close the file
        printf("%d\n",count);
    
    }
    fclose(fp);    
    return 0;
}