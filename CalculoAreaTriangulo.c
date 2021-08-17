
#include <stdio.h>

int calcularAreaTriangulo(int base, int altura) {
    return ((base * altura)/2);
}

void menu(){
    printf("Calculo del Area de un Triangulo:\n");
    printf("Ingrese Base y Altura:\n");
    return;
}

int main(){
    int base, altura= 0;
    menu();
    scanf("%d", &base);
    scanf("%d", &altura);
    printf("\nEl area triangulo de base %d y altura %d es: %d\n",base,altura,calcularAreaTriangulo(base, altura));
    return 0;
}