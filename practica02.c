#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 31

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

Nodo * initNodo(char tipo[], char nombre[], int intvalor, float floatvalor, char charvalor);
void printLista(Nodo * lista);
void insertNodo(Nodo ** lista, Nodo * newNodo);
int deleteNodo(Nodo ** lista, char nombre[]);
void hazNull(Nodo ** lista);

int fDispersion(char nombre[]);
void insert(Nodo * tablaHash[], Nodo * newNodo);
int delete(Nodo *tablaHash[], char nombre[]);
void search(Nodo * tablaHash, char nombre[]);
void hazNull(Nodo ** tablaHash);
void printTablaHash(Nodo * tablaHash[]);

Nodo * lista = NULL;

int main(){
    int i;


    Nodo * tablaHash[SIZE];
    for (i = 0; i < SIZE; i++){
        tablaHash[i] = NULL;
    }    
    insertNodo(&tablaHash[0], initNodo("int", "x", 1, 0, '\0'));
    
    printTablaHash(tablaHash);
}

int fDispersion(char nombre[]){
    int i;
    int suma = 0;
    for (i = 0; i < strlen(nombre); i++){
       suma = suma + nombre[i];
    }

    suma = suma % SIZE;
    return suma;
}


void insert(Nodo * tablaHash[], Nodo * newNodo){
    
    int n = fDispersion(newNodo->info->nombre);
    insertNodo(&tablaHash[n], newNodo);
}

int delete(Nodo * tablaHash[], char nombre[]){
    int status;
    
    while (status != 1){
        for (int i = 0; i < SIZE; i++){
            status = deleteNodo(tablaHash[i], nombre);
        } 
    }
   
    return status;
}

void printTablaHash(Nodo * tablaHash[]){
    int i;
    for (i = 0; i < SIZE; i++){
        printLista(tablaHash[i]);
    }
}

Nodo * initNodo(char tipo[], char nombre[], int intvalor, float floatvalor, char charvalor){
    Nodo * newNodo = malloc(sizeof(Nodo));
    
    newNodo->info = malloc(sizeof(Info));
    strcpy(newNodo->info->tipo, tipo);
    strcpy(newNodo->info->nombre, nombre);
    newNodo->info->intvalor = intvalor;
    newNodo->info->floatvalor = floatvalor;
    newNodo->info->charvalor = charvalor;
    
    return newNodo;
}

void printLista(Nodo * lista){
    Nodo * currentNodo = lista;

    while (currentNodo != NULL){
        
        if (strcmp(currentNodo->info->tipo, "int") == 0){
            printf("Tipo: int\n");
            printf("Nombre: %s\n", currentNodo->info->nombre);
            printf("Valor: %d\n", currentNodo->info->intvalor);
        }
        else if (strcmp(currentNodo->info->tipo, "float") == 0){
            printf("TIpo: float\n");
            printf("Nombre: %s \n", currentNodo->info->nombre);
            printf("Valor: %f\n", currentNodo->info->floatvalor);
        }
        else if (strcmp(currentNodo->info->tipo, "char") == 0){
            printf("Tipo: char\n");
            printf("Nombre: %s \n", currentNodo->info->nombre);
            printf("Valor: %c\n", currentNodo->info->charvalor);
        }

        printf("-->\n");
        
        currentNodo = currentNodo->sig;
    }
}

void insertNodo(Nodo ** lista, Nodo * newNodo){
    newNodo->sig = *lista;
    *lista = newNodo;
}

int deleteNodo(Nodo ** lista, char nombre[]){
    Nodo * currentNodo = *lista;

    //Busca en el primer nodo.
    if (strcmp(currentNodo->info->nombre, nombre) == 0){
        *lista = currentNodo->sig;
        free(currentNodo);
        return 1;
    }
    
    //Apartir de aquí hace la búsqueda apartir del '->sig'.
    while (currentNodo->sig != NULL){

        if (strcmp(currentNodo->sig->info->nombre, nombre) == 0){
            currentNodo->sig = currentNodo->sig->sig;
            free(currentNodo->sig);
            return 1;
        }
        else {
            currentNodo = currentNodo->sig;
        }
    }

    //Si llega aquí es que no lo encontró.
    return -1;
}
