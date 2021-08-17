/*-------------------------------------------------------------------  */
/* "Lab Estructuras de datos 1 - Listas Enlazadas" - V. 1.0            */
/* Alumno Alberto San Martin C - Universidad de Santiago               */
/*-------------------------------------------------------------------  */

#include <stdio.h>
#include <stdlib.h>

// Nodo
typedef struct Nodo{
  int dato;
  struct Nodo * sgte;
} nodo;

/********************************
 * Funcionaes prototipadas
 * ******************************/
nodo * crear_nodo(int dato);
nodo * agregar(nodo * q, int dato);
nodo * elimLista(nodo * cab , int elem);
nodo * eliminarDeFila(nodo * q);
nodo * borrar(nodo * cab , int elem);
void compararFilasCine(nodo * fila1, nodo * fila2);
void mostrarFilaCine(nodo * q);
void mostrarFilasCine(nodo * q, nodo * q1);
void mostrarLista(nodo * cabeza);
void leerArchivo();
/********************************
 * Funcionaes prototipadas  
 * ******************************/


nodo * crear_nodo(int dato){
  nodo * nuevo_nodo = (nodo *)malloc(sizeof(nodo));
  nuevo_nodo->dato = dato;
  nuevo_nodo->sgte = NULL;
  return nuevo_nodo;
}


nodo * agregar(nodo * q, int dato){
  nodo * nuevo_nodo = crear_nodo(dato);
  nodo * indice = q;
  if(q == NULL){
    q = nuevo_nodo;    
    return q;
  }
  while(indice->sgte != NULL){
    indice = indice->sgte;    
  }
  indice->sgte = nuevo_nodo;
  return q;
}

nodo * borrar(nodo * cabeza , int elem){

  nodo * temp = NULL;
  temp = cabeza;
  /*Se consulta a la cabeza, si existe el elemento*/
  if(temp->dato == elem){
     cabeza = cabeza->sgte;
     free(temp);
  }else{
    /*Si no se encuentra en la cabeza, comienza a buscar hacia adelante*/
    while((temp->sgte)->dato != elem){
      temp = temp -> sgte;
    }
    nodo * temp2 = temp->sgte;
    free(temp->sgte);
    temp->sgte = (temp->sgte)->sgte;

  }  
  return cabeza;

}

nodo * elimLista(nodo * cab , int elem){

     nodo * p;
     printf("Dato a eliminar: %d\n", elem);
     if (cab==NULL || cab->dato>elem)          /* Salidas 1 y 3 */
        return cab;                
      else if(cab->dato == elem)               /* Salida 2 */
      { 
            p = cab->sgte;
            free(cab);
            return p;
      }   
      else 
      { 
          cab->sgte=elimLista(cab->sgte, elem);  /* Avance */
          return cab;
      }
}

void mostrarFilaCine(nodo * q){

  nodo * indice = q;

  while(indice!=NULL){
    printf("%d \n",indice->dato);    
    indice = indice->sgte;
  }

}

void mostrarFilasCine(nodo * q, nodo * q1){

  nodo * indice  = q;

  nodo * indice1 = q1;

  while(indice!=NULL && indice1!=NULL){
    printf("%d %d \n",indice->dato, indice1->dato);    
    indice = indice->sgte;
    indice1 = indice1->sgte;
  }

}

/*Funcion va eliminando por nodo*/
nodo * eliminarDeFila(nodo * q){
  if(q!=NULL){
    nodo * aux = q;
    q = q->sgte;
    aux->sgte = NULL;
    return q;
  }
  return q;
}

void mostrarLista(nodo * cabeza){

    nodo * indice = cabeza;    
    nodo * p;
        
    if (cabeza==NULL)/* Si la cabeza esta vacia, la lista es vacia */
       printf("Lista sin elementos");
     else
     {        
       for (p=cabeza; p!=NULL; p=p->sgte){
            printf("%d \n",p->dato);            
       }                   
     }
}

void compararFilasCine(nodo * fila1, nodo * fila2){

  nodo * indiceFila1 = fila1;
  
  nodo * indiceFila2 = fila2;

  nodo * filaEntradaCine=NULL;

  nodo * filaEliminada=NULL;

  while(indiceFila1!=NULL && indiceFila2!=NULL){
    

    if(indiceFila1->dato > indiceFila2->dato){
      //printf("%d es mayor que %d \n", indiceFila1->dato, indiceFila2->dato );
        
    }else if(indiceFila1->dato < indiceFila2->dato){
      //printf("%d es menor que %d\n", indiceFila1->dato, indiceFila2->dato );
      filaEntradaCine = agregar(filaEntradaCine, indiceFila1->dato);
      filaEliminada   = borrar(indiceFila1, indiceFila1->dato);
      //indiceFila1   = elimLista(indiceFila1, indiceFila1->dato);

    }else{

      printf("%d es igual que %d \n", indiceFila1->dato, indiceFila2->dato );

    }

    indiceFila1 = indiceFila1->sgte;
    indiceFila2 = indiceFila2->sgte;

  }
  printf("\n");
  printf("Personas que van entrando al cine:\n");
  mostrarFilaCine(filaEntradaCine);

  printf("\n");
  printf("Personas que va quedando:\n");
  mostrarFilaCine(filaEliminada);
  
  
}


void leerArchivo(){

   FILE *archivo;
   char caracter;
   archivo = fopen("filascine.txt","r");	
   if (archivo == NULL){
        printf("\nError de apertura del archivo. \n\n");
   }else{
        printf("\nEl contenido del archivo filaprueba es \n\n");
        while((caracter = fgetc(archivo)) != EOF){
		        printf("%c",caracter);
	    }
   }
   fclose(archivo);
    return ;
}


int main(){

    //Fila 1 de personas interesadas en entrar al cine
    nodo * filaCine=NULL;    
    filaCine = agregar(filaCine, 24);
    filaCine = agregar(filaCine, 17);
    filaCine = agregar(filaCine, 25);
    filaCine = agregar(filaCine, 37);
    filaCine = agregar(filaCine, 11);
            
    //Fila 2 de personas interesadas en entrar al cine
    nodo * filaCine2=NULL;
    filaCine2 = agregar(filaCine2, 30);
    filaCine2 = agregar(filaCine2, 19);
    filaCine2 = agregar(filaCine2, 21);
    filaCine2 = agregar(filaCine2, 36);
    filaCine2 = agregar(filaCine2, 8);

    printf("Filas de personas interesadas en entrar a cine:\n");
    mostrarFilasCine(filaCine, filaCine2);

    printf("\n");

    nodo * filaQueEntra=NULL;
    compararFilasCine(filaCine, filaCine2);

    printf("\n");

    printf("Fila restante\n");
    mostrarFilaCine(filaCine);
    
    printf("\n");
    

    return 0;
}