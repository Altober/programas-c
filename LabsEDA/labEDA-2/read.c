#include <stdio.h>

int main() {
   //El fichero es un tipo de dato FILE *.
   FILE *fp;

   char buff[255];
   int a,b,c;
   
   //Se abre el fichero en modo de lectura
   fp = fopen("testEntrada.txt", "r");

   //fscanf funciona como scanf, pero recibe, además, el fichero desde donde lee.
   fscanf(fp, "%s", buff);
   
   //Se imprime por pantalla la información leída
   printf("1: %s\n", buff );
   
   // Para obtener un string. Recibe el nombre del buffer, el tamaño del buffer,
   // y el fichero desde donde leer.
   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );
   
   //Notar que cuando leo, se va moviendo el "cursor" dentro del fichero, por lo que siempre voy
   //avanzando en el fichero hacia la derecha y hacia abajo.
   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   
   //Para obtener los números sin hacer transformaciones
   fgets(buff, 255, (FILE*)fp);
   fscanf(fp, "%d %d %d",&a,&b,&c);
   printf("4: Valores: %d %d %d\n",a,b,c);
   
  

   return 0;
}