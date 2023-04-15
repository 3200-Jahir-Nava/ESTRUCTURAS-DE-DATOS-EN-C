#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
	int dato;
	struct nodo *siguiente;

}nodo;

nodo *primero=NULL;

void insertar();
void mostrar();
void eliminar();


int main()
{
	int op,op2,i,nd;
	do
	{
		printf("Implementacion de pila con reserva de memoria dinmica");
		printf("\nSeleccione una opercion");
		printf("\n1-Ingresar datos");
		printf("\n2-Mostrar pila");
		printf("\n3-Eliminar");
		printf("\nIngrese la opcion seleccionada:\t");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
				system("cls");
				printf("\nCuantos datos desea registrar:\t");
				scanf("%d",&nd);
				for(i=0;i<nd;i++)
				{
					printf("\nIngrese el elemento %d:",i+1);
                    insertar();
				}
				printf("Los datos ingresados se almacenaron en la pila correctamente");
			}
			break;
			case 2:
			{
			    system("cls");
			    mostrar();

			}
			break;
			case 3:
			{
			    system("cls");
			    eliminar();

			}
			break;
			default:
			printf("\nOpcion invalida");
			break;
		}
		printf("\nIngrese el numero 10 si desea volver a ver el menu pricipal:\t");
		scanf("%d",&op2);
        system("cls");

	}while(op2==10);

}




void insertar()
{
	nodo *nuevo=(nodo*)malloc(sizeof(nodo));
	scanf("%d",&nuevo->dato);
	nuevo->siguiente=primero;
	primero=nuevo;
}

void mostrar()
{
    nodo *aux=(nodo*)malloc(sizeof(nodo));
    aux=primero;
    if(aux!=NULL)
    {
        while(aux!=NULL)
        {
            printf("%d\n\n",aux->dato);
            aux=aux->siguiente;
        }
    }else
    {
        printf("\nLa pila esta vacia");
    }
}

void eliminar()
{
    if(primero!=NULL)
    {
        nodo *eli=primero;
        primero=primero->siguiente;
        free(eli);
        printf("\nEl ultimo elemento ingresado fue eliminado exitosamente");

    }else
    {
        system("cls");
        printf("No hay elementos para eliminar");

    }


}
