#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Informacion {
    char nombre[40];
    char tipo[10];
    int intvalor;
    float floatvalor;
    char charvalor;
} Info;

typedef struct Nodos {
    struct Informacion * info;
    struct Nodos * sig;
} Nodo;

/**
    Inicializa un Nodo
 
    @param nombre
    @param tipo
    @param intvalor
    @param floatvalor
    @param charvalor
    @return Regresa un Nodo * inicializado
*/
Nodo * initNodo(char nombre[], char tipo[], int intvalor, float floatvalor, char charvalor);

/**
	Imprime en pantalla una lista ligada.
	@param lista Lista ligada a imprimir (nodo cabeza).
*/
void printLista(Nodo * lista);

/**
	Inserta un nodo al principio de una lista ligada.
	@param lista
	@param newNodo
*/
void insertNodo(Nodo ** lista, Nodo * newNodo);

/**
	Elimina un nodo de una lista ligada encontrado por su nombre.
	@param lista
	@param nombre[]
*/
void deleteNodo(Nodo ** lista, char nombre[]);

Nodo * lista;

int main(){

    lista = NULL;
    Nodo * newNodo;
    
    newNodo = initNodo("x", "int", 1, 0, '\0');
    insertNodo(&lista, newNodo);

    newNodo = initNodo("y", "float", 0, 2, '\0');
    insertNodo(&lista, newNodo);
    
    newNodo = initNodo("z", "char", 0, 0, '3');
    insertNodo(&lista, newNodo);

    printf("LISTA:\n");
    printLista(lista);

    deleteNodo(&lista, "z");
    printf("\nLISTA MODIFICADA:\n");
    printLista(lista);
}

Nodo * initNodo(char nombre[], char tipo[], int intvalor, float floatvalor, char charvalor){
    Nodo * newNodo = malloc(sizeof(Nodo));
    
    newNodo->info = malloc(sizeof(Info));
    strcpy(newNodo->info->nombre, nombre);
    strcpy(newNodo->info->tipo, tipo);
    newNodo->info->intvalor = intvalor;
    newNodo->info->floatvalor = floatvalor;
    newNodo->info->charvalor = charvalor;
    
    return newNodo;
}

void printLista(Nodo * lista){
    Nodo * nodoActual = lista;

    while (nodoActual != NULL){
        printf("\
        Nombre: %s \n\
        Tipo: %s \n\
        Valor entero: %d \n\
        Valor float: %f \n\
        Valor char: %c \n\
         ->\n",
        nodoActual->info->nombre,
        nodoActual->info->tipo,
        nodoActual->info->intvalor,
        nodoActual->info->floatvalor,
        nodoActual->info->charvalor);
        
        nodoActual = nodoActual->sig;
    }
}

void insertNodo(Nodo ** lista, Nodo * newNodo){
    newNodo->sig = *lista;
    *lista = newNodo;
}

void deleteNodo(Nodo ** lista, char nombre[]){
    Nodo * nodoAnterior = *lista;
    Nodo * nodoActual = nodoAnterior->sig;

    if (strcmp(nodoAnterior->info->nombre, nombre) != 0){
        
        while (strcmp(nodoActual->info->nombre, nombre) != 0){
            nodoAnterior = nodoActual;
            nodoActual = nodoActual->sig;
        }

        nodoAnterior->sig = nodoActual->sig;
        free(nodoActual);
    }
    else {
        *lista = nodoActual;
        free(nodoAnterior);
    }
}
