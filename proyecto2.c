#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "proyecto2.h"

//Implementa el xor con dos punteros, haciendo el intercambio
node *xor(node *a, node *b)
{
    return (node*) ((uintptr_t) a ^ (uintptr_t) b);
}

//Generar una lista nueva
list *crearLista() {
    list *newlist;

    if ((newlist = (list*)malloc(sizeof(list))) == NULL) {
        printf("error");
        return NULL;
    }

    newlist->head = newlist->tail = NULL;

    return newlist;
}

//Inicializa la lista
void Inicializar(list *l){
    l->head = l->tail = NULL;
}

//Verifica si la lista se encuentra vacia
int esVacia(list *l){

    if (l->head == NULL){
        return 1;
    }
    return 0;
}

//Inserta elementos al principio de la lista
int insertarPrincipio(list *l, int data){
    node *ptr;

    ptr = (node *)malloc(sizeof(node));
    ptr->item = data;
    if (l->head == NULL){
        ptr->link = NULL;
        l->head = l->tail = ptr;
        return 0;
    }
    else{
        ptr->link = xor(NULL, l->head);
        l->head->link = xor(ptr, l->head->link);
        l->head = ptr;
        return 1;
    }
}

//Inserta elementos al final de la lista
int insertarFinal(list *l, int data){
    node *ptr;

    ptr = (node *)malloc(sizeof(node));
    ptr->item = data;
    ptr->link=NULL;
    if (l->head == NULL){
        ptr->link = NULL;
        l->head = l->tail = ptr;
        return 0;
    }
    else{
        ptr->link = xor(l->tail, NULL);
        l->tail->link = xor(ptr, xor(l->tail->link, NULL));
        l->tail = ptr;
        return 1;
    }
}

// Inserta un elemento en una lista ordenada
int insertarOrden(list *l, int data){
    node *ptr;

    // Se confirma si hay suficiente espacio de memoria para el nodo
    if ((ptr = (node *)malloc(sizeof(node))) == NULL)
        return 0;

    ptr->item = data;
    
    if (esVacia(l)){ 
        ptr->link = l->head;
        l->head = l->tail = ptr;
    }
    // Si el dato es menor al primero de la lista
    else if (data <= l->head->item){ 
        ptr->link = l->head;
        node *sig = l->head->link;
        l->head->link = xor(ptr, sig);
        l->head = ptr;
    }
    // Si el dato es mayor al ultimo de la lista
    else if (data >= l->tail->item){ 
        ptr->link = l->tail;
        node *ant = l->tail->link;
        l->tail->link = xor(ant, ptr);
        l->tail = ptr;
    }
    else {
        //Se recorre la lista buscando que el xnext sea mayor al dato introducido
        node *prev = NULL;
        node *curr = l->head;
        node *next = xor(prev, curr->link);
        node *xnext = xor(curr, next->link);

        while (data >= next->item){
            prev = curr;
            curr = next;
            next = xnext;
            xnext = xor(curr, next->link);
        }

        ptr->link = xor(curr, next);
        curr->link = xor(prev, ptr);
        next->link = xor(ptr, xnext);
    }

    return 1;
}

//Elimina el primer elemento de una lista
int sacarPrincipio(list *l, int *data){
    node *ptr = l->head;

    if(esVacia(l)){
        printf("La lista se encuentra vacia\n");
        return 0;
    }

    *data = ptr->item;

    if (l->head == l->tail){
        free(l->head);
        l->head = l->tail = NULL;
        return 1;
    }

    l->head = l->head->link;
    l->head->link = xor(ptr, l->head->link);
    free(ptr);
    return 1;
}

//Elimina el ultimo elemento de una lista
int sacarFinal(list *l, int *data){
    node *ptr = l->tail;
    node *prev = xor(ptr->link, NULL);

    if(esVacia(l)){ 
        printf("La lista se encuentra vacia\n");
        return 0;
    }
    
    *data = ptr->item;

    if (prev == NULL)
        l->head =NULL;
    else
        prev->link = xor(ptr, xor(prev->link, NULL));
    
    l->tail = prev;
    free(ptr);
    ptr = NULL;
    return 1;
}

//Elimina la primera ocurrencia de un elemento en la lista
int sacarPrimeraOcurrencia(list *l, int data){
    if (esVacia(l)){
        printf("La lista se encuentra vacia\n");
        return 0;
    }

    //En caso de que la primera ocurrencia sea el primer elemento
    if (l->head->item == data){
        int i;
        return sacarPrincipio(l, &i);
    }

    if (l->tail->item == data){
            int i;
            return sacarFinal(l, &i);
        }
    
    node *prev = NULL;
    node *curr = l->head;
    node *next;

    //Mientras el nodo actual exista y el elemento sea distinto del dato
    while(curr != NULL && curr->item != data){
        next = xor(prev, curr->link);
        prev = curr;
        curr = next;
    }
    if (curr != NULL){
        next = xor(prev, curr->link);
        node *xprev = xor(prev->link, curr);
        node *xnext = xor(curr, next->link);

        prev->link = xor(xprev, next);

        next->link = xor(prev, xnext);

        free(curr);

        return 1;
    }    
    return 0;
}

void listarInicioAFinal(list *l){
    node *prev = NULL, *curr = l->head, *next;

    while (curr)
    {
        printf(" %d ", curr->item);
        next = xor(prev, curr->link);
        prev = curr;
        curr = next;
    }

    printf("\n");    
}

void listarFinalAIinicio(list *l){
    node *prev, *curr = l->tail, *next = NULL;

    while(curr)
    {
        printf(" %d ", curr->item);
        prev = xor(curr->link, next);
        next = curr;
        curr = prev;    
    }
    
    printf("\n");
}

int cantidadElementos(list *l){
     node *prev, *curr = l->tail, *next = NULL;
    int i;

    while(curr)
    {
        prev = xor(curr->link, next);
        next = curr;
        curr = prev; 
        i++;
    }
    return i;
}

