#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "proyecto2.h"

int main(){
    list *lista;
    int choice, element;

    do 
    {
        printf("\n");
        printf("¿Que desea hacer?\n");
        printf("1. Crear lista\n");
        printf("2. Inicializar la lista\n");
        printf("3.  Verificar si la lista esta vacia\n");
        printf("4. Insertar elemento al principio\n");
        printf("5. Insertar elemento al final\n");
        printf("6. Insertar un elemento en orden\n");
        printf("7. Eliminar elemento al principio\n");
        printf("8. Eliminar elemento al final\n");
        printf("9. Eliminar la primera ocurrencia\n");
        printf("10. Listar de inicio a final\n");
        printf("11. Listar de final a inicio\n");
        printf("12. Mostrar cantidad de elementos de la lista\n");
        printf("13. Exit\n");
        printf("--------------------------------\n");
        scanf("%d",&choice);
    
        system("clear");

        switch (choice)
        {
            case 1:
            lista = crearLista();
            printf("La lista ha sido creada\n");
            break;

            case 2:
            Inicializar(lista);
            printf("La lista ha sido inicializada\n");
            break;

            case 3:
            if(esVacia(lista))
            printf("La lista se encuentra vacia\n");
            else
            printf("La lista NO se encuentra vacia");
            break;

            case 4:
            printf("¿Que elemento desea insertar al principio?\n");
            scanf("%i", &element);
            insertarPrincipio(lista, element);
            printf("El elemento ha sido insertado al principio de la lista\n");
            break;

            case 5:
            printf("¿Que elemento desea insertar al final?\n");
            scanf("%i", &element);
            insertarFinal(lista, element);
            printf("El elemento ha sido insertado al final de la lista\n");
            break; 
            
            case 6:
            printf("¿Que elemento desea insertar a la lista?\n");
            scanf("%i", &element);
            insertarOrden(lista, element);
            printf("El elemento ha sido insertado en orden\n");
            break; 

            case 7: 
            sacarPrincipio(lista, &element);
            printf("El elemento del principio  eliminado es: %i\n", element);
            break; 

            case 8:
            sacarFinal(lista, &element);
            printf("El elemento del final eliminado es: %i\n", element);
            break; 

            case 9:
            printf("¿Cual es el elemento que desea eliminar de la lista?\n");
            scanf("%i", &element);
            sacarPrimeraOcurrencia(lista,element);
            printf("El elemento ha sido eliminado\n");
            break; 

            case 10:
            printf("La lista de elementos:\n");
            listarInicioAFinal(lista);
            break; 

            case 11:
            printf("La lista de elementos inversa:\n");
            listarFinalAIinicio(lista);
            break; 

            case 12:
            printf("La cantidad de elementos en la lista: %i", cantidadElementos(lista));
            break; 

            case 13:
            printf("Ha salido exitosamente\n");
            break;

            default: printf("Hasta luego\n");
            break;
        } 
 
    } while (choice != 13);

}
