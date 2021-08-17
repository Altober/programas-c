#include <stdio.h>

double media(int a, int b) {
    double res;
    res = 0.5 * (a+b);
    return res;
}

int main() {
    int x=2, y=3;
    double res;

    res = media(x,y);
    printf("La media de %d y %d es %.1lf.", x, y, res);

    return 0;
}