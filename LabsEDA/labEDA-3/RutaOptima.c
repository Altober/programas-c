
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
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define LONGITUD_MAXIMA_CADENA 1000
#define MAX 1024
#define INFINITY 9999


// Numero de vertices en el grafo
#define V 6

struct AdjMatrix{
    int ** adjacencies;
    int nodes;
}; typedef struct AdjMatrix AdjMatrix;


void   crearMatrizAdyacencia(AdjMatrix* m ,int n);
void   escribirEnArchivo();
void   dijkstra2(AdjMatrix* m, int n,int startnode);
void   prim(AdjMatrix* m, int nodos);
void   imprimirMatrizAdyacencia(AdjMatrix* m);
int    leerNumeroNodosFile();
int    distanciaMinima(int dist[], bool sptSet[]);
size_t obtenerValoresDeArchivo(FILE *fp, int *a, int *b, int *c );
int    minimum_key(int k[], int mst[], int nodos);
void   printSolution(int dist[]);


/*
    Entradas: fp: Hace referencia al puntero del archivo File
               a: Hace referencia un puntero al arreglo de valores nodo desde
               b: Hace referencia un puntero al arreglo de valores nodo hasta
               c: Hace referencia un puntero al arreglo de valores arista
*/      
size_t obtenerValoresDeArchivo(FILE *fp, int *a, int *b, int *c )
{
    /* Buffer para leer cada linea */ 
    char buf[MAX];          
    /* numero de valores leidos */
    size_t ncoeff = 0;      

    /* read each line */
    while (ncoeff < MAX && fgets (buf, MAX, fp))
        /* Si contiene 3 valores enteros */
        if (sscanf (buf, "%d %d %d", &a[ncoeff], &b[ncoeff], &c[ncoeff]) == 3)
            ncoeff++;       /* Se incrementa el contador */

    /* Retorna el total de valores leidos */
    return ncoeff;          
}


int leerNumeroNodosFile(){
    
   //El fichero es un tipo de dato FILE *.
   FILE *fp;
   
   char buff[LONGITUD_MAXIMA_CADENA];    
   int cantidadNodos = 0;   
      
   //Se abre el fichero en modo de lectura
   fp = fopen("testEntrada.txt", "r");

   if( fp == NULL ){
        
        printf("Error: No se puede abrir el archivo \n");
        return -1;

   } else {

        printf("Archivo abierto de forma satisfactoria.\n");

        //Para obtener los números sin hacer transformaciones
        fgets(buff, LONGITUD_MAXIMA_CADENA, (FILE*)fp);
        fscanf(fp, "%d",&cantidadNodos);

        //Si el archivo no se encuentra cerrado,
        //entonces se cierra.
        if (fp != stdin){            
            fclose(fp);
        }
              
        
    }
              
   return cantidadNodos;
}


/*
* Funcion encargada de crear matriz de adyacencia
*/
void crearMatrizAdyacencia(AdjMatrix* m ,int n){
    m->adjacencies = (int**)malloc(sizeof(int*)*n);
    m->nodes = n;
    for(int i = 0; i<n; i++){
        m->adjacencies[i] = (int*)malloc(sizeof(int)*n);
        for(int j = 0; j<n; j++){
            m->adjacencies[i][j] = 0;
        }
    }    
}

/*
* Funcion encargada de imprimir matriz de adyacencia
*/
void imprimirMatrizAdyacencia(AdjMatrix* m){
    for(int i = 0; i < m->nodes; i++){
        for(int j = 0; j < m->nodes; j++ ){
            printf("%d ", m->adjacencies[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


/*
* Funcion encargada de imprimir grafo de acuerdo a matriz de adyacencia
*/
void createGraph(AdjMatrix* m, int a[], int b[], int c[], int numberOfEdges){
    int x=0;
    int y=0;
    int z=0;
    for (int i = 0; i < numberOfEdges; i++){
        x = a[i];
        y = b[i];
        z = c[i];        
        m->adjacencies[x-1][y-1] = z;
        m->adjacencies[y-1][x-1] = z;
    }
    printf("\n");
}

/*Funcion principal*/
int main(){    
    
    // Puntero del tipo File
    FILE *fp;
    //Se abre el fichero en modo de lectura
    fp = fopen("testEntrada.txt", "r");

    int nodos=0;

    int a[MAX] = {0}, b[MAX] = {0}, c[MAX] = {0}; 
    size_t n = 0;  

    nodos = leerNumeroNodosFile(); 

    if(nodos < 0){

        printf("No se puede seguir con al ejecucion del programa\n");
        return 0;

    }else{

        printf("Nodos: %d \n",nodos);
    
        AdjMatrix* adjMatrix = (AdjMatrix*)malloc(sizeof(AdjMatrix));
        
        /* Se valida la entrada */
        if (!(n = obtenerValoresDeArchivo(fp, a, b, c))) {
            fputs ("Error: No son enteros los leidos desde el archivo.\n", stderr);
            return -1;
        }

        /* for loop y salida valores */
        for (int i = 0; i < n; i++)  
            printf ("%d %d %d \n", a[i], b[i], c[i]);

        printf("\n");
        printf("Matriz de adyacencia creada.\n");

        if(adjMatrix != NULL && nodos>0){        
            crearMatrizAdyacencia(adjMatrix, nodos);
            printf("\n"); 
        }   

        createGraph(adjMatrix, a, b, c, 8); 
        imprimirMatrizAdyacencia(adjMatrix);   

        printf("Ejecucion de ruta mas corta\n");
        //Se indica que comience a recorrer desde el nodo 0         
        dijkstra2(adjMatrix, nodos,0);
        printf("Ejecucion de ruta realizada por Pedro\n");         
        prim(adjMatrix, nodos);
        
       
        /* cierre de archivo en caso se encuentre abierto */
        if (fp != stdin)   
            fclose (fp);    
    }
                
    return 0;
}

// Una función de utilidad para encontrar el vértice con el valor de distancia mínimo, desde
// el conjunto de vértices aún no incluido en el árbol de la ruta más corta
int distanciaMinima(int dist[], bool sptSet[]){
    // Se inicializa valor minimo
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

// Funcion utilitaria para mostrar las distancias
void printSolution(int dist[]){

    printf("Vertice \t Distancia desde el origen\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra2(AdjMatrix* m,int n,int startnode){
 
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;
    //pred[] almacena el predecesor de cada nodo
    //count entrega el numeo de nodos vistos hasta ahora
    //se crea la matriz de costo
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(m->adjacencies[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=m->adjacencies[i][j];
    //inicializar pred[],distance[] y visited[]
    for(i=0;i<n;i++){
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1){
        mindistance=INFINITY;
        //nextnode entrega el nodo a una distancia mínima
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i]){
                mindistance=distance[i];
                nextnode=i;
            }
            //comprueba si existe una ruta mejor a través de nextnode
            visited[nextnode]=1;
            for(i=0;i<n;i++){
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i]){
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
            }        
        count++;
    }
    
    //imprime la ruta y la distancia de cada nodo
    for(i=0;i<n;i++){

        if(i!=startnode){
            printf("\nDistancia de nodo %d=%d",i,distance[i]);
            printf("\nCamino=%d",i);
            j=i;
            do{
                j=pred[j];
                printf("<-%d",j);
            }while(j!=startnode);
        }

    }
    printf("\n\n");
    
}

/*
 Algoritmo de Prim implementado en lenguaje C.
*/ 
void prim(AdjMatrix* m, int nodos){

  int no_edge;  // number of edge

   // crea una matriz para almacenar el nodo seleccionado.
   // nodo seleccionado se convertirá en verdadero en caso de otra forma sera falso
  int selected[nodos];

  // se setea seleccionado falso inicialmente
  memset(selected, false, sizeof(selected));
  
  // establece el número de nodo en 0
  no_edge = 0;

  // el número de aristas en el árbol de expansión mínimo será 
  // siempre menor que (V -1), donde V es el número de vértices en 
  // gráfico

  // elige el vértice 0 y hazlo verdadero
  selected[0] = true;

  int x;  //  row number
  int y;  //  col number

  // imprimir por vertice y peso
  printf("origen -> destino : Peso\n");

  while (no_edge < nodos - 1) {
    
    // Para cada vértice del conjunto S, encuentra todos los vértices adyacentes,
    // calcula la distancia desde el vértice seleccionado en el paso 1.
    // si el vértice ya está en el conjunto S, descartarlo en caso contrario
    // elige otro vértice más cercano al vértice seleccionado en el paso.

    int min = INFINITY;
    x = 0;
    y = 0;

    for (int i = 0; i < nodos; i++) {
      if (selected[i]) {
        for (int j = 0; j < nodos; j++) {
          if (!selected[j] && m->adjacencies[i][j]) {  // not in selected and there is an edge
            if (min > m->adjacencies[i][j]) {
              min = m->adjacencies[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d \t-> \t%d : %d\n", x, y, m->adjacencies[x][y]);
    selected[y] = true;
    no_edge++;
  }

}

int minimum_key(int k[], int mst[], int nodos){

   int minimum  = INT_MAX, min,i;  
   
   for (i = 0; i < nodos; i++)  
     if (mst[i] == 0 && k[i] < minimum )  
         minimum  = k[i], min = i;  
   
   return min;  
}  


