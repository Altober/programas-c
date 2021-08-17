#include <stdio.h>
#include <stdlib.h>

struct AdjMatrix{
    int ** adjacencies;
    int nodes;
}; typedef struct AdjMatrix AdjMatrix;


void createAdjMatrix(AdjMatrix* m ,int n){
    m->adjacencies = (int**)malloc(sizeof(int*)*n);
    m->nodes = n;
    for(int i = 0; i<n; i++){
        m->adjacencies[i] = (int*)malloc(sizeof(int)*n);
        for(int j = 0; j<n; j++){
            m->adjacencies[i][j] = 0;
        }
    }
}

void createGraph(AdjMatrix* m, int edges[7][2], int numberOfEdges){
    int x;
    int y;
    for(int i = 0; i < numberOfEdges; i++){
        x = edges[i][0];
        y = edges[i][1];
        m->adjacencies[x-1][y-1] = 1;
        m->adjacencies[y-1][x-1] = 1;
    }
}

void printAdjMatrix(AdjMatrix* m){
    for(int i = 0; i < m->nodes; i++){
        for(int j = 0; j < m->nodes; j++ ){
            printf("%d ", m->adjacencies[i][j]);
        }
        printf("\n");
    }
}


int path(AdjMatrix* m, int x, int y){
    printf("%d\n", x);
    if(m->adjacencies[x-1][y-1] == 1){
        return 1;
    }
    else{
        for(int i = 0; i < m->nodes; i++){
            if(m->adjacencies[x-1][i] == 1){
                int aux = path(m, i+1, y);
                if(aux == 1){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
    }
    
    
}

int main(){

    AdjMatrix* adjMatrix = (AdjMatrix*)malloc(sizeof(AdjMatrix));
 
    createAdjMatrix(adjMatrix, 5);
 
    int edges[7][2] = {{1,2},{1,3},{1,3},
                    {2,3},{2,4},
                    {3,4},
                    {4,5}};
 
    createGraph(adjMatrix, edges, 7);
 
    printAdjMatrix(adjMatrix);
 
    int aux = path(adjMatrix, 5, 1);

    return 0;
}