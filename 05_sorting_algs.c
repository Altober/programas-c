#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MAX;

/* Funcion utilitaria para mostrar array */
void mostrar_array(int * A){
  for(int i = 0; i < MAX; ++i){
    printf("%d ",A[i]);
  }
  printf("\n");
}

/* Funcion de swap entre arreglo */
int * intercambiar(int * A, int i, int j){
  int aux;
  if(i!=j){
    aux = A[i];
    A[i] = A[j];
    A[j] = aux;
  }
  return A;
}

/* Bubblesort */
int * burbuja(int * A){
  for(int i = MAX-1; i>=0; i--){
    for(int j = 0; j<=i-1; j++){
      if(A[j]>A[j+1]){
        A = intercambiar(A, j, j+1);
      }
    }
  }
  return A;
}

/* Selectionsort */
int * seleccion(int * A){
  int idx_mejor, valor_mejor;
  for(int i = 0 ; i <= MAX-2; i++){
    idx_mejor = i;
    valor_mejor = A[i];
    for(int j = i + 1; j <= MAX-1; j++){
      if(A[j] < valor_mejor){
        idx_mejor = j;
        valor_mejor = A[j];
      }
      //printf("i: %d, j:%d, idx_mejor:%d, valor_mejor:%d\n", i, j, idx_mejor, valor_mejor);
    }
    if (idx_mejor != i){
      A = intercambiar(A, i, idx_mejor);
    }
  }
  return A;
}

/* Insertionsort */
int * insercion(int * A){
  int j;
  for(int i = 1; i<=MAX-1; i++){
    j = i;
    while(A[j] < A[j-1] & j >= 1){
      //printf("i: %d j: %d\n",i,j);
      A = intercambiar(A, j, j-1);
      j = j - 1;
    }
  }
  return A;
}

int buscar_pivote(int * A, int inicio, int fin){
  for(int i=inicio+1; i<=fin; i++){
    if(A[i] > A[inicio]){
      return i;
    }
    else if(A[i] < A[inicio]){
      return inicio;
    }
    else{
      return fin;
    }
  }
  return fin;
}

int particionar(int * A, int inicio, int fin, int indice_pivote){
  int pivote, derecha, izquierda;
  pivote = A[indice_pivote];
  A = intercambiar(A, indice_pivote, fin);
  indice_pivote = fin;
  izquierda = inicio;
  derecha = fin - 1;
  do{
    A = intercambiar(A, izquierda, derecha);
    while (A[izquierda] < pivote){
      izquierda = izquierda + 1;
    }
    while (A[derecha] >= pivote){
      derecha = derecha - 1;
    }
  }while(izquierda<derecha);

  A = intercambiar(A, izquierda, indice_pivote);
  return izquierda;
}

int * quicksort(int * A, int inicio, int fin){
  int indice_pivote, corte;
  if(inicio<fin){
    indice_pivote = buscar_pivote(A, inicio, fin);
    corte = particionar(A, inicio, fin, indice_pivote);
    A = quicksort(A, inicio, corte-1);
    A = quicksort(A, corte+1, fin);
  }
  return A;
}

int main(int argc, char *argv[]) {
  // cota inferior de numeros a generar
  int inicio = atoi(argv[1]);
  // cota superior de numeros a generar
  int fin = atoi(argv[2]);
  // cuantos numeros voy a generar
  MAX = atoi(argv[3]);

  clock_t t_ini, t_fin;
  double secs;
  int * arregloInicial = (int *)malloc(sizeof(int)*MAX);

  srand(time(0));
  for(int i = 0; i < MAX; i++){
      arregloInicial[i] = (rand() % (fin - inicio + 1)) + inicio;
  }

  int * arregloBurbuja =   (int *)malloc(sizeof(int)*MAX);
  int * arregloSeleccion = (int *)malloc(sizeof(int)*MAX);
  int * arregloInsercion = (int *)malloc(sizeof(int)*MAX);
  int * arregloQuickSort = (int *)malloc(sizeof(int)*MAX);

  mostrar_array(arregloInicial);

  printf("Ordenando...\n\n");
  t_ini = clock();
  arregloBurbuja = burbuja(arregloInicial);
  t_fin = clock();
  secs = (double)(t_fin-t_ini) / CLOCKS_PER_SEC;
  printf("BURBUJA\n%.16g milisegundos\n", secs * 1000.0);
  //mostrar_array(arregloBurbuja);

  t_ini = clock();
  arregloSeleccion = seleccion(arregloInicial);
  t_fin = clock();
  secs = (double)(t_fin-t_ini) / CLOCKS_PER_SEC;
  printf("SELECCION\n%.16g milisegundos\n", secs * 1000.0);
  //mostrar_array(arregloSeleccion);

  t_ini = clock();
  arregloInsercion = insercion(arregloInicial);
  t_fin = clock();
  secs = (double)(t_fin-t_ini) / CLOCKS_PER_SEC;
  printf("INSERCION\n%.16g milisegundos\n", secs * 1000.0);
  //mostrar_array(arregloInsercion);

  t_ini = clock();
  arregloQuickSort = quicksort(arregloInicial,0,MAX-1);
  t_fin = clock();
  secs = (double)(t_fin-t_ini) / CLOCKS_PER_SEC;
  printf("QUICKSORT\n%.16g milisegundos\n", secs * 1000.0);
  //mostrar_array(arregloQuickSort);

  return 0;
}
