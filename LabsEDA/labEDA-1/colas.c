#include <stdio.h>
#include <stdlib.h>

// Nodo
typedef struct Nodo{
  int dato;
  struct Nodo * sgte;
} nodo;

nodo * crear_nodo(int dato){
  nodo * nuevo_nodo = (nodo *)malloc(sizeof(nodo));
  nuevo_nodo->dato = dato;
  nuevo_nodo->sgte = NULL;
  return nuevo_nodo;
}

nodo * enqueue(nodo * q, int dato){
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

int inicio(nodo * q){
  if(q!=NULL){      
    return q->dato;
  }
  return -1;
}

//Es solo un nodo el que va eliminando.
nodo * dequeue(nodo * q){
  if(q!=NULL){
    nodo * aux = q;
    q = q->sgte;
    aux->sgte = NULL;
    return q;
  }
  return q;
}

nodo * anular(nodo * q){
  while(q != NULL){
    q = dequeue(q);
  }
  return q;
}

int vacia(nodo * q){
  if(q==NULL){
    return 1; // esta vacia
  }
  return 0; // no esta vacia
}

void mostrarLista(nodo * q){

  nodo * indice = q;

  while(indice!=NULL){
    printf("%d \n",indice->dato);    
    indice = indice->sgte;
  }

}


int main(int argc, char const *argv[]) {

  // creamos nuestra cola
  nodo * q;

  q = enqueue(q, 24);
  q = enqueue(q, 16);
  q = enqueue(q, 15);
  q = enqueue(q, 12);
  q = enqueue(q, 11);  
  printf("\nlista Inicial\n");
  mostrarLista(q);    
  printf("\n");

  

  int ini = inicio(q);
  printf("1) El primer elemento de la cola es : %d\n",ini);

  printf("2) Se desencola el valor: %d\n",q->dato);
  q = dequeue(q);
  ini = inicio(q);

  printf("3) El valor inicial de la lista ahora es: %d\n",ini);  
  printf("Mostrar lista\n");
  mostrarLista(q);      


/*
  

  q = enqueue(q, 40);
  ini = inicio(q);
  printf("El inicio de la cola es %d\n",ini);

  q = anular(q);
  ini = inicio(q);
  printf("El inicio de la cola es %d\n",ini);

  int es_vacia = vacia(q);
  if (es_vacia == 1) printf("La cola esta vacia\n");
  else printf("La cola no esta vacia\n");

  q = enqueue(q, 50);
  ini = inicio(q);
  printf("El inicio de la cola es %d\n",ini);
*/

  return 0;
}
