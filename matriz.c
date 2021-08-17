#include <stdio.h>
#define N 4   /* Define la dimensión máxima de la matriz */
#define M 7   /* Define la dimensión máxima de la matriz */

void show(int matrix[][M]);
void llenar_esperilicamente(int matrix[][M]);
int llenar(int matrix[][M], const char axis, const int row, const int start, const int end, int *start_value);

int main(int argc, char *argv[]) {
    int matrix[N][M];

    llenar_esperilicamente(matrix);
    show(matrix);

    return 0;
}

/**
 * Muestra la matriz entregada por parámetro
 * @param matrix matriz a ser mostrada
 */
void show(int matrix[][M]) {
    /* imprime la matriz recibida por parámetro en la pantalla */
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            printf ("%4d", matrix[i][j]);
        printf ("\n");
    }
}

/**
 * Llena la matriz del parámetro en forma de espiral con números ascendientes
 * @param matrix Matriz a ser llenada
 */
void llenar_esperilicamente(int matrix[][M]) {
    int current = 1;
    int n = N-1;
    int m = M-1;
    int aux = 0;

    do {
        llenar(matrix, 'x', aux, aux, m - aux, &current);
        if (current > N*M) break;

        llenar(matrix, 'y', m - aux, (aux + 1), n - aux, &current);
        if (current > N*M) break;

        llenar(matrix, 'x', n - aux, m-(aux + 1), aux, &current);
        if (current > N*M) break;

        llenar(matrix, 'y', aux, n-(aux + 1), (aux + 1), &current);
        aux++;
    } while (current < N*M);
}

/**
 * Llena en una *matrix* dada desde el punto *start* al *end*
 * en algun eje *axis* definido, comenzando con el valor *start_value*
 * @param  matrix      Matriz sobre la que se trabaja
 * @param  axis        eje en que se llena: x o y
 * @param  j           que fila o que columna llenar
 * @param  start       donde comenzar
 * @param  end         donde terminar
 * @param  start_value puntero al contador
 */
int llenar(int matrix[][M], const char axis, const int j, const int start, const int end, int *start_value) {
    int i;
    int step;

    if (start == end) {
        if (axis == 'x')
            matrix[j][end] = (*start_value)++;
        else if (axis == 'y')
            matrix[end][j] = (*start_value)++;
        return 0;
    }

    step = start > end ? -1 : 1;

    for (i = start; start > end ? i >= end : i <= end; i += step) {
        if (axis == 'x')
            matrix[j][i] = (*start_value)++;
        else if (axis == 'y')
            matrix[i][j] = (*start_value)++;
    }

    return 1;
}