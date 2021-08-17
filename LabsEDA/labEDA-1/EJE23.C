/*---- --------------------------------------------------------------*/
/* "DISENO Y MANEJO DE ESTRUCTURAS DE DATOS EN C" - V. 1.0           */
/* J. Villalobos, A. Quintero - Universidad de los Andes             */
/*-------------------------------------------------------------------*/
/*  Cap 0. - Ejemplo 23 - Buscar recursivamente un elemento en una   */
/*           lista encadenada.                                       */
/*-------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
/*-------------------------------------------------------------------*/
/*                            DECLARACIONES                          */
/*-------------------------------------------------------------------*/

struct nodo
{   int info;
    struct nodo *sig;
};

/*-------------------------------------------------------------------*/

int estaLista(struct nodo *cab, int valor)
{   if (cab==NULL)
       return 0;
     else if (cab->info==valor)
       return 1;
     else
       return estaLista(cab->sig,valor);
}

/*-------------------------------------------------------------------*/
/*                        PROGRAMA DE PRUEBA                         */
/*-------------------------------------------------------------------*/

int main(void)
{   int num,i;
    struct nodo *cab,*p,*q;

    /* Lee la lista encadenada */
    printf("Numero de elementos: ");
    scanf("%d",&num);
    for (i=1, cab=NULL; i<=num; i++)
    {
        p=(struct nodo *)malloc(sizeof(struct nodo));
        printf("Elemento: ");
        scanf("%d",&p->info);
        p->sig=NULL;
       if (cab==NULL)
          cab=q=p;
        else
        { q->sig=p;
          q=p;
        }
    }

    /* Verifica si un elemento se encuentra en la lista */
    do
    {  
       printf("Elemento por buscar (0 para terminar): ");
       scanf("%d",&num);
       if (estaLista(cab,num))
          printf("El elemento esta en la lista\n");
       else
	      printf("El elemento NO esta en la lista\n");
    } while( num!=0 );

    return 0;
}
