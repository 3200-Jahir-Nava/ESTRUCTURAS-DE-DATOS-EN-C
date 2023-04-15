#include <stdio.h>
typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
}nodo;

nodo *primero=NULL;

void insertar();
void mostrar();
void buscar();
void modificar();
void eliminar();

int main()
{
	int op,op2,i,nd;
	do
	{
		printf("Implementacion de pila con memoria dinamica");
		printf("\nSeleccione una opcion");
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
				printf("Ingrese cuantos datos desea registrar:\t");
				scanf("%d",&nd);
				for(i=0;i<nd;i++)
                {
                    printf("\nIngresa el dato %d:",i+1);
                    insertar();
                }
                printf("\n\nLos datos se almacenaron exitosamente");

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
		printf("\n\nIngrese el numero 10 si desea volver a ver le menu principal:\t");
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
        printf("La pila se encuentra vacia");
    }
}
void eliminar()
{
    if(primero!=NULL)
    {
        struct nodo *eli=primero;
        primero=primero->siguiente;
        free(eli);
        printf("\nEl ultimo elemento ingresado fue eliminado");
    }else
    {
        system("cls");
        printf("La pila esta vacia");
    }

}
