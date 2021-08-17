#include <stdio.h>
#include <math.h>

int esPrimo(int num) {
         int i;
         for (i=2; i<=sqrt(num); i++) {
                      if (num%i == 0) {
                                       return 0;
        }     }     return -1; 
}
int main() {
    int num=0;
    printf("Introduce un número entero: ");
    scanf("%d", &num);
    for (int i = 4; i<= num;  i++){
            if (esPrimo(i) && esPrimo(i+2) )
                printf("%d es primo y %d es su gemelo \n",i, i+2);
            if (!esPrimo(i))
                printf("%d no es primo\n",i);
    }
    return 0;
}