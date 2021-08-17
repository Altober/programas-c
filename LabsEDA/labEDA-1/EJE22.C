#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------------------------------*/
/*                            DECLARACIONES                          */
/*-------------------------------------------------------------------*/

struct Nodo
{   int info;
    struct Nodo *sig;
};

/*-------------------------------------------------------------------*/

struct Nodo * elimLista(struct Nodo *cab , int elem)
{    
     struct Nodo *p;
     if (cab==NULL || cab->info>elem)          /* Salidas 1 y 3 */
        return cab;                
      else if(cab->info == elem)              /* Salida 2 */
      { 
            p = cab->sig;
            free(cab);
            return p;
      }   
      else 
      { 
          cab->sig=elimLista(cab->sig, elem);  /* Avance */
          return cab;
      }
}

/*-------------------------------------------------------------------*/
/*                        PROGRAMA DE PRUEBA                         */
/*-------------------------------------------------------------------*/

int main(void)
{   
  
    int num,i;
    struct Nodo *cab,*p,*q;

    /* Lee la lista encadenada */
    printf("Numero de elementos: ");
    scanf("%d",&num);
    for (i=1, cab=NULL; i<=num; i++)
    {   p=(struct Nodo *)malloc(sizeof(struct Nodo));
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
   /* Imprime la lista leida */
   for (p=cab; p!=NULL; p=p->sig)
     printf("%d ",p->info);

   /* Elimina el elemento pedido por el usuario */
   do
    { 
      printf("\nNumero que desea eliminar (0 para terminar): ");
      scanf("%d",&num);
      cab=elimLista(cab,num);
      for (p=cab; p!=NULL; p=p->sig)
	        printf("%d\n",p->info);
    } while( num!=0 );
    return 0;
}