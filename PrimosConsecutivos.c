/* Este programa muestra por pantalla los pares de primos consecutivos
menores que un número (100 por defecto). */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM 100

int es_primo (int n)
{
    int i;
    if(n==2) return 1;
    if(n%2==0) return 0;
    for(i=3;i<=sqrt(n);i++){
        if (n%i==0) return 0;
    }
    return 1;
}

int main()
{
    int i, cuenta=0;
    for(i=2;i<=NUM;i++){
        if(es_primo(i)==1 && es_primo(i+2)==1){
            printf("%d y %d, ",i,i+2);
            cuenta++;
        }
    }
    printf("\nPares de primos consecutivos menores que %d: %d \n \n",NUM,cuenta);
    return 0;
}
 