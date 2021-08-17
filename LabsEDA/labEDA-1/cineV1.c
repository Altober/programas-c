/*-------------------------------------------------------------------  */
/* "Lab Estructuras de datos 1 - Listas Enlazadas" - V. 1.0            */
/*  Alumno Alberto San Martin C - Universidad de Santiago              */
/*-------------------------------------------------------------------  */

/**************************************************************************************************/
/*OBSERVACION IMPORTANTE: Codigo Fuente no cuenta con la implementación de la escritura en archivo*/
/**************************************************************************************************/

/**************************************************************************************************
Pruebas realizadas en :
    Código fuente probado en :
    Mac Osx
    Windows SubsistemLinux (SO: Ubuntu)
***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    /* data */
    int edad;
    struct Nodo *sgte;

} Node;

/**************Prototipado de Funciones*****************/
/*******************************************************/
Node * InitList(Node *Lista);
Node * Add(Node *Lista, int edadPersona);
Node * DelElem(Node *Lista, int edadPersona);
void   PersonasQueEntran(Node *Lista, Node *Lista2,  int cantidadEntradas);
Node * PersonasQueQuedan(Node *Lista, Node *Lista2,  int cantidadEntradas);
void Print(Node *Lista);
/******************************************************/


/*
Descripcion:Funcion que devolvera un puntero de tipo nodo.
            Para el caso de nuestro negocio, devolvera una Lista Cine inicializada en NIL.
 */
Node * InitList(Node *Lista){

    return Lista = NULL;

}

/*
    Descripcion:Funcion encargada de ir agregando nodos mas la informacion al nodo respectivo.
    Retorno: Retorna nodo con elemento.
*/
Node * Add(Node *Lista, int edadPersona){

    Node * nuevo_nodo, *temp;
    nuevo_nodo = (Node * ) malloc(sizeof(Node));
    if(nuevo_nodo!=NULL){
        nuevo_nodo->edad = edadPersona;
        nuevo_nodo->sgte = NULL;
        if(Lista == NULL){
            /*Primer elemento de la lista*/
            Lista = nuevo_nodo;
        } else{
            /*Del primer en adelante, es decir, segundo..*/
            /*La forma mas sencilla, agregar siempre el nodo de ultimo*/
            /*Si vamos a agregar de ultimo crearemos una var auxiliar*/
            /*En este while se va sobrescribiendo la cabeza, hasta que llegue a null*/
            /*Es decir, temp va a ser igual al primer nodo*/
            temp = Lista;
            /*Nos vamos a parar antes de llegar al null, es decir en el ultimo elemento*/
            while(temp->sgte!=NULL){
                //Vamos a ir apuntando al siguiente del siguiente
                temp = temp->sgte;
            }
            temp->sgte = nuevo_nodo;
        }
    }else{
        puts("No se pudo crear, memoria llena");
    }

    return Lista;

}

/*
    Descripcion:Funcion encargada de imprimir una lista, independiente del estado que se encuentre la lista.     
*/
void Print(Node *Lista){
    
    int i=1;
    /*Nos detenemos en el ultimo elemento*/
    while (Lista!=NULL)
    {
        /* code */        
        printf("P%d: %d\n",i, Lista->edad);
        Lista = Lista->sgte;
        i++;

    }
    
}

/*
    Descripcion:Funcion encargada de imprimir las dos filas del cine inicial.     
*/
void Print2Filas(Node *Lista, Node *Lista2){

    /*Nos detenemos en el ultimo elemento*/
    int i=1;
    while (Lista!=NULL && Lista2!=NULL)
    {
        /* code */        
        printf("P%d: %d  P%d: %d\n",i, Lista->edad, i, Lista2->edad);
        Lista  = Lista->sgte;
        Lista2 = Lista2->sgte;
        i++;

    }
    
}

/*
    Descripcion:Funcion encargada de filtrar las personas que entran al cine, como las que quedan fuera.
    Retorno: Muestra las personas que entraran al cine, como las personas que quedan fuera de el
*/
void PersonasQueEntran(Node *Lista, Node *Lista2, int cantidadEntradas){

  Node * tempFila1 = Lista;
  Node * tempFila2 = Lista2;
  Node * ListaSalida=NULL;
  Node * fila2Restante = NULL;
  Node * fila1Restante = NULL;  
  while(tempFila1!=NULL && tempFila2!=NULL && cantidadEntradas!=0){      
      //Entra al cine (en la ListaSalida ) el elemento de la fila 1 y se van guardando en una lista.
      //Las personas que no lograron entrar al cine, van quedando en la lista fila2Restante.
      if(tempFila1->edad < tempFila2->edad){
          ListaSalida = Add(ListaSalida, tempFila1->edad);
          fila2Restante = DelElem(tempFila2, tempFila2->edad);
      //Entra al cine (en la ListaSalida ) el elemento de la fila 2 y se van guardando en una lista.
      //Las personas que no lograron entrar al cine, van quedando en la lista fila1Restante.
      }else if(tempFila1->edad > tempFila2->edad){
          ListaSalida = Add(ListaSalida, tempFila2->edad);
          fila1Restante = DelElem(tempFila1, tempFila1->edad);
      //EN caso de ser personas de iguales edades, ambas entran al cine.
      }else{          
          ListaSalida = Add(ListaSalida, tempFila1->edad);
          ListaSalida = Add(ListaSalida, tempFila2->edad);
      }
      tempFila1 = tempFila1->sgte;
      tempFila2 = tempFila2->sgte;
      cantidadEntradas--;
  }  
  /*Se muestran las personas que logran entrar al cine*/
  printf("Personas que entran:\n");    
  Print(ListaSalida);
  /*Se muestran la fila 2 restante, es decir, quienes no lograron entrar dada la 
  cantidad de entradas*/  
  printf("\n");      
  printf("Fila 2:\n");
  Print(fila2Restante);

  /*Se muestran la fila 1 restante, es decir, quienes no lograron entrar dada la 
  cantidad de entradas*/
  printf("\n");      
  printf("Fila 1:\n");
  Print(fila1Restante);

}

/*
    Descripcion:Funcion que elimina un nodo de una lista en cualquier ubicacion
    Retorno: La fila de cine sin el nodo pasado por parametro.
*/
Node * DelElem(Node *Lista, int edadPersona){

    Node * temp;
    temp = Lista;
    if(temp->edad == edadPersona){

        Lista = Lista->sgte;
        free(temp);

    }else{

        while((temp->sgte)->edad != edadPersona){
            temp = temp->sgte;
        }
        Node * temp2 = temp->sgte;
        temp->sgte = (temp->sgte)->sgte;
        free(temp2);
        

    }

    return Lista;
    
}

/*Funcion principal*/
int main(){

    /*Se inicializan ambas listas de cines en NULL*/
    int numeroEntradas=0;
    printf("Ingrese cantidad de entradas: ");
    scanf("%d",&numeroEntradas);

    Node *Fila1Cine = InitList(Fila1Cine);
    Node *Fila2Cine = InitList(Fila2Cine);

    Fila1Cine = Add(Fila1Cine, 24);
    Fila1Cine = Add(Fila1Cine, 17);
    Fila1Cine = Add(Fila1Cine, 25);
    Fila1Cine = Add(Fila1Cine, 37);
    Fila1Cine = Add(Fila1Cine, 11);

    Fila2Cine = Add(Fila2Cine, 30);
    Fila2Cine = Add(Fila2Cine, 19);
    Fila2Cine = Add(Fila2Cine, 21);
    Fila2Cine = Add(Fila2Cine, 36);
    Fila2Cine = Add(Fila2Cine, 8);
    
    Print2Filas(Fila1Cine, Fila2Cine);
    printf("\n");    

    PersonasQueEntran(Fila1Cine, Fila2Cine, numeroEntradas);
    
    return 0;
}
