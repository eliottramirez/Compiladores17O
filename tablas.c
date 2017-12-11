#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 31

typedef struct structInfo {
    char nombre[40];
    int fun;
    int tipo;
    int intvalor;
    float floatvalor;
    char charvalor;
    int numArgs;
} Info;

typedef struct structNodo {
    struct structInfo * info;
    struct structNodo * next;
} Nodo;

void initMenu();
void initTablas();

Nodo * initNodo(int fun, int tipo, char nombre[], int intvalor, float floatvalor, char charvalor);
void insertNodo(Nodo ** lista, Nodo * newNodo);
int deleteNodo(Nodo ** lista, char nombre[]);
Nodo * searchNodo(Nodo * lista, char nombre[]);
void printNodo(Nodo * nodo);

int fHash(char nombre[]);
Nodo * insert(Nodo * tabla[], Nodo * newNodo);
int delete(Nodo *tabla[], char nombre[]);
Nodo * search(Nodo * tabla[], char nombre[]);

void purgeLista(Nodo ** lista);
void printLista(Nodo * lista);
void purgeTabla(Nodo * tabla[]);
void printTabla(Nodo * tabla[]);

Nodo * tablaGlobal[SIZE];
Nodo * tablaLocal[SIZE];

Nodo * apID;
Nodo * apFun;

void initTablas(){
    
    for (int i = 0; i < SIZE; i++){
        tablaGlobal[i] = NULL;
    }

    for (int i = 0; i < SIZE; i++){
        tablaLocal[i] = NULL;
    }
}

int fHash(char nombre[]){
    int suma = 0;
    int len = strlen(nombre);
    
    for (int i = 0; i < len; i++){
       suma += nombre[i];
    }

    return (suma % SIZE);
}

Nodo * insert(Nodo * tabla[], Nodo * newNodo){
    
    insertNodo(&tabla[fHash(newNodo->info->nombre)], newNodo);
    return search(tabla, newNodo->info->nombre);
}

int delete(Nodo * tabla[], char nombre[]){
    int found = -1;
    
    for (int i = 0; i < SIZE; i++){
        found = deleteNodo(&tabla[i], nombre);
        if (found == 1) break;
    }
   
    return found;
}

Nodo * search(Nodo * tabla[], char nombre[]){
    Nodo * found;

    for (int i = 0; i < SIZE; i++){
        found = searchNodo(tabla[i], nombre);
        if (found != NULL) break;
    }

    return found;
}

void purgeTabla(Nodo * tabla[]){

    for (int i = 0; i < SIZE; i++){
        purgeLista(&tabla[i]);
        tabla[i] = NULL;
    }
} 

void printTabla(Nodo * tabla[]){

    for (int i = 0; i < SIZE; i++){
        printLista(tabla[i]);
    }
}

Nodo * initNodo(int fun, int tipo, char nombre[], int intvalor, float floatvalor, char charvalor){
    Nodo * newNodo = malloc(sizeof(Nodo));
    newNodo->info = malloc(sizeof(Info));
    
    newNodo->info->fun = fun;
    newNodo->info->tipo = tipo;
    strcpy(newNodo->info->nombre, nombre);
    newNodo->info->intvalor = intvalor;
    newNodo->info->floatvalor = floatvalor;
    newNodo->info->charvalor = charvalor;
    
    return newNodo;
}

void insertNodo(Nodo ** lista, Nodo * newNodo){

    newNodo->next = *lista;
    *lista = newNodo;
}

int deleteNodo(Nodo ** lista, char nombre[]){
    Nodo * current;
    Nodo * next;
    
    if (*lista == NULL){
        return -1;
    }
    else {
        current = *lista;
        next = current->next;
    }

    //Busca en el primer nodo.
    if (strcmp(current->info->nombre, nombre) == 0){
        
        *lista = next;
        free(current);
        return 1;
    }
    
    //A partir de aquí hace la búsqueda apartir del next.
    while (next != NULL){

        if (strcmp(next->info->nombre, nombre) == 0){
            current->next = next->next;
            free(next);
            return 1;
        }
        else {
            current = next;
            next = current->next;
        }
    }

    return -1;
}

Nodo * searchNodo(Nodo * lista, char nombre[]){
    Nodo * current = lista;

    while (current != NULL){
        if (strcmp(current->info->nombre, nombre) == 0) break;
        else current = current->next;
    }

    return current;
}

void purgeLista(Nodo **lista){
    Nodo *current = *lista;
    Nodo *next;

    while (current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}

void printLista(Nodo *lista){
    Nodo *current = lista;

    while (current != NULL){
        printNodo(current);
        current = current->next;
    }
}

void printNodo(Nodo *nodo){

    
    if (nodo->info->fun == 1){
        printf("Función\n");
    }
    else if (nodo->info->tipo == 3){
        printf("Tipo: entero\n");
        printf("Nombre: %s\n", nodo->info->nombre);
    }
    else if (nodo->info->tipo == 4){
        printf("Tipo: flotante\n");
        printf("Nombre: %s\n", nodo->info->nombre);
    }
    else if (nodo->info->tipo == 5){
        printf("Tipo: caracter\n");
        printf("Nombre: %s\n", nodo->info->nombre);
    }
    else if (nodo->info->tipo == 36){
        printf("Tipo: biblioteca\n");
        printf("Nombre: %s\n", nodo->info->nombre);
    }

    printf("-->\n");
}