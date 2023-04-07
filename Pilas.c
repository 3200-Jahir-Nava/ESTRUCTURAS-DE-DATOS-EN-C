#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *siguiente;

}nodo;

void insertar();
void mostrar();
void buscar();
void modificar();
void eliminar();

nodo *primero=NULL;

int main()
{
    int i,nr,op,op2;
    do
    {
        printf("Seleccione una opcion");
        printf("\n1-Ingresar dato");
        printf("\n2-Ver pila");
        printf("\n3-Buscar");
        printf("\n4-Modficar un dato");
        printf("\n5-Eliminar un dato");
        printf("\n\nIngrese la opcion seleccionada:\t");scanf("%d",&op);
        switch(op)
        {
            case 1:
                system("cls");
                printf("\nIngrese cuantos datos desea ingresar a la pila:\t");
                scanf("%d",&nr);
                for(i=0;i<nr;i++)
                {
                    insertar();
                }
                break;

            case 2:
                system("cls");
                mostrar();
                break;
            case 3:
                system("cls");
                buscar();
                break;
            case 4:
                system("cls");
                modificar();
                break;
            case 5:
                system("cls");
                eliminar();
                break;

            default:
                printf("Opcion invalida");
                break;

        }
        printf("\n\nIngrese el nuemro 10 si desea volver a ver el menu principal:\t");
        scanf("%d",&op2);
        system("cls");
    }while(op2==10);

}

void insertar()
{
    nodo *nuevo=(nodo*)malloc(sizeof(nodo));
    printf("Ingrese el dato:\t");
    scanf("%d",&nuevo->dato);
    nuevo->siguiente=primero;
    primero=nuevo;

}

void mostrar()
{
    nodo *actual=(nodo*)malloc(sizeof(nodo));
    actual=primero;
    if(primero!=NULL)
    {
        while(actual!=NULL)
        {
            printf("\n\n%d",actual->dato);
            actual=actual->siguiente;
        }

    }else{
        system("cls");
        printf("La pila se encuentra vacia");
    }

}

void buscar()
{
    nodo *actual=(nodo*)malloc(sizeof(nodo));
    actual=primero;
    int nodobuscado=0,encontrado=0;
    printf("\n\nIngrese el dato a buscar en la pila:\t");
    scanf("%d",&nodobuscado);
    printf("\n");
    if(primero!=NULL)
    {
        while(actual!=NULL)
        {
            if(actual->dato==nodobuscado)
            {
                printf("\nEl nodo con el dato %d fue encoontrado",nodobuscado);
                encontrado=1;
            }
            actual=actual->siguiente;
        }
        if(encontrado==0)
        {
            system("cls");
            printf("\nDato no encontrado");
        }

    }else{
        system("cls");
        printf("La pila se encuentra vacia");
    }

}

void modificar()
{
    nodo *actual=(nodo*)malloc(sizeof(nodo));
    actual=primero;
    int nodobuscado=0,encontrado=0;
    printf("\n\nIngrese el dato a modificar de la pila:\t");
    scanf("%d",&nodobuscado);
    printf("\n");
    if(primero!=NULL)
    {
        while(actual!=NULL)
        {
            if(actual->dato==nodobuscado)
            {
                printf("\nEl nodo con el dato %d fue encoontrado",nodobuscado);
                printf("\nIngrese el nuevo dato para el nodo:\t");
                scanf("%d",&actual->dato);
                printf("\nNodo modificado");
                encontrado=1;
            }
            actual=actual->siguiente;
        }
        if(encontrado==0)
        {
            system("cls");
            printf("\nDato no encontrado");
        }

    }else{
        system("cls");
        printf("La pila se encuentra vacia");
    }

}
void eliminar()
{
    nodo *actual=(nodo*)malloc(sizeof(nodo));
    actual=primero;
    nodo *anterior=(nodo*)malloc(sizeof(nodo));
    anterior=NULL;
    int nodobuscado=0,encontrado=0;
    printf("\n\nIngrese el dato a eliminar de la pila:\t");
    scanf("%d",&nodobuscado);
    printf("\n");
    if(primero!=NULL)
    {
        while(actual!=NULL &&encontrado!=1)
        {
            if(actual->dato==nodobuscado)
            {
                if(actual==primero)
                {
                    primero=primero->siguiente;
                }else
                {
                    anterior->siguiente=actual->siguiente;
                }
                printf("\nEl dato ha sido eliminado de la pila");
                encontrado=1;
            }
            anterior=actual;
            actual=actual->siguiente;
        }
        if(encontrado==0)
        {
            system("cls");
            printf("\nDato no encontrado");
        }else
        {
            free(anterior);
        }

    }else{
        system("cls");
        printf("La pila se encuentra vacia");
    }

}
