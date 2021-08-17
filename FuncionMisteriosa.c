#include <stdio.h>

void menu() {
    printf("Menú:\n  1. Empezar partida\n  2. Ajustes\n  3. Ayuda\n  4. Salir\n");
    printf("Selecciona una opción: ");
    return;
}

int main() {
    int opcion;
   
    do {
        
        menu();
        scanf("%d", &opcion);
        

    } while (opcion<1 || opcion>4);
   
    switch (opcion) {
        case 1:         
            printf("Has elegido comenzar la partida.\n");
            break;
        case 2:         
            printf("Aquí estará el código para mostrar los ajustes del juego.\n");
            break;
        case 3:         
            printf("Aquí estará el código para mostrar la ayuda.\n");
            break;
        case 4:         
            printf("¡Hasta luego!\n");
            break;
    }

    return 0;
}