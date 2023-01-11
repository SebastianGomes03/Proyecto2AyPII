//Estructura nodo
typedef struct node {
    int item;
    struct node *link;
} node;

//Estructura de la lista (cabeza y cola)
typedef struct list {
    node *head, *tail;
}list;

//Implementa el xor con dos punteros, haciendo el intercambio
node *xor(node *a, node *b);

//Generar una lista nueva
list *crearLista();

//Inicializa la lista
void Inicializar(list *l);

//Verifica si la lista se encuentra vacia
int esVacia(list *l);

//Inserta elementos al principio de la lista
int insertarPrincipio(list *l, int data);

//Inserta elementos al final de la lista
int insertarFinal(list *l, int data);

// Inserta un elemento en una lista ordenada
int insertarOrden(list *l, int data);

//Elimina el primer elemento de una lista
int sacarPrincipio(list *l, int *data);

//Elimina el ultimo elemento de una lista
int sacarFinal(list *l, int *data);

//Elimina la primera ocurrencia de un elemento en la lista
int sacarPrimeraOcurrencia(list *l, int data);

void listarInicioAFinal(list *l);

void listarFinalAIinicio(list *l);

int cantidadElementos(list *l);




