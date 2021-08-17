#include <stdio.h>

void media(int a, int b) {
    double res;
    res = 0.5 * (a+b);
    printf("La media de %d y %d es %.1lf \n", a, b, res);
    return;
}

int main() {
    int x=2, y=0;
    media(x,y);
    return 0;
}