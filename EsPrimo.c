#include <stdio.h>
#include <math.h>

int esPrimo(int num) {
    int i;
    for (i=2; i<=sqrt(num); i++) {
        if (num%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num;

    printf("Introduce un número entero: ");
    scanf("%d", &num);

    if (esPrimo(num))
        printf("%d es primo.", num);
    else
        printf("%d no es primo", num);

    return 0;
}