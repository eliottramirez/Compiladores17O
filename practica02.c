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
void insertNodo(Nodo ** lista, Nodo * newNodo);
int deleteNodo(Nodo ** lista, char nombre[]);
Nodo * searchNodo(Nodo * lista, char nombre[]);
void printNodo(Nodo * nodo);
void nullLL(Nodo ** lista);
void printLista(Nodo * lista);

int fDispersion(char nombre[]);
void insert(Nodo * tablaHash[], Nodo * newNodo);
int delete(Nodo *tablaHash[], char nombre[]);
Nodo * search(Nodo * tablaHash[], char nombre[]);
void nullTH(Nodo * tablaHash[]);
void printTablaHash(Nodo * tablaHash[]);

Nodo * tablaHash[SIZE];

int main(){
    int menu = 0;

    for (int i = 0; i < SIZE; i++){
        tablaHash[i] = NULL;
    }    
    
    while (menu != 6){
        
        if (menu == 0){
            printf("\n¿Qué desea hacer?:\n\
                   1. Dar de alta una variable.\n\
                   2. Dar de baja una variable.\n\
                   3. Buscar una variable.\n\
                   4. Imprimir la tabla de variables.\n\
                   5. Limpiar la lista tabla de variables.\n\
                   6. Salir.\n\
                   ");
            
            scanf("%d", &menu);
        }
        else if (menu == 1){
            
            char tipo[10];
            char nombre[40];
            int intvalor;
            float floatvalor;
            char charvalor;
            
            printf("Proporcione tipo de la variable: \n");
            scanf("%s", tipo);
            
            if ((strcmp("int", tipo) != 0) && (strcmp("float", tipo) != 0) && (strcmp("char", tipo) != 0)){
                printf("Tipo inválido.\n");
                menu = 0;
            }
            else {
                printf("Proporcione nombre de la variable: \n");
                scanf("%s", nombre);
                
                printf("Proporcione valor de la variable: \n");
                if (strcmp("int", tipo) == 0){
                    scanf("%d", &intvalor);
                    floatvalor = 0;
                    charvalor = '\0';
                }
                else if (strcmp("float", tipo) == 0){
                    intvalor = 0;
                    scanf("%f", &floatvalor);
                    charvalor = '\0';
                }
                else if (strcmp("char", tipo) == 0){
                    intvalor = 0;
                    floatvalor = 0;
                    scanf(" %c", &charvalor);
                }
                
                insert(tablaHash, initNodo(tipo, nombre, intvalor, floatvalor, charvalor));
                menu = 0;
            }
        }
        else if (menu == 2){
            char nombre[40];
            int status = 0;
            
            printf("Proporcione el nombre de la variable a eliminar: \n");
            scanf("%s", nombre);
            
            status = delete(tablaHash, nombre);
            
            if (status == 1){
                printf("Variable encontrada y eliminada.\n");
            }
            else if (status == -1){
                printf("Variable no encontrada.\n");
            }
            
            menu = 0;
        }
        else if (menu == 3){
            char nombre[40];
            Nodo * found;

            printf("Proporcione el nombre de la variable a buscar: \n");
            scanf("%s", nombre);
            
            found = search(tablaHash, nombre);
            
            if (found != NULL){
                printf("Variable encontrada:\n");
                printNodo(found);
            }
            else {
                printf("Variable no encontrada.\n");
            }
            
            menu = 0;
        }
        else if (menu == 4){
            printTablaHash(tablaHash);
            menu = 0;
        }
        else if (menu == 5){
            nullTH(tablaHash);
            menu = 0;
        }
        else {
            printf("Opción inválida.\n");
            menu = 0;
        }
    }
}

int fDispersion(char nombre[]){
    int suma = 0;
    
    for (int i = 0; i < strlen(nombre); i++){
       suma = suma + nombre[i];
    }

    return (suma % SIZE);
}

void insert(Nodo * tablaHash[], Nodo * newNodo){
    
    int n = fDispersion(newNodo->info->nombre);
    insertNodo(&tablaHash[n], newNodo);
}

int delete(Nodo * tablaHash[], char nombre[]){
    int status;
    
    for (int i = 0; i < SIZE; i++){
        
        status = deleteNodo(&tablaHash[i], nombre);
        if (status == 1) break;
    } 
   
    return status;
}

Nodo * search(Nodo * tablaHash[], char nombre[]){
    Nodo * found;

    for (int i = 0; i < SIZE; i++){
        
        found = searchNodo(tablaHash[i], nombre);
        if (found != NULL) break;
    }

    return found;
}

void nullTH(Nodo * tablaHash[]){

    for (int i = 0; i < SIZE; i++){
        nullLL(&tablaHash[i]);
        tablaHash[i] = NULL;
    }
} 

void printTablaHash(Nodo * tablaHash[]){

    for (int i = 0; i < SIZE; i++){
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

void insertNodo(Nodo ** lista, Nodo * newNodo){

    newNodo->sig = *lista;
    *lista = newNodo;
}

int deleteNodo(Nodo ** lista, char nombre[]){
    Nodo * currentNodo = *lista;

    if (currentNodo == NULL) return -1;

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

Nodo * searchNodo(Nodo * lista, char nombre[]){
    Nodo * currentNodo = lista;

    while (currentNodo != NULL){
        if (strcmp(currentNodo->info->nombre, nombre) == 0) return currentNodo;
        else currentNodo = currentNodo->sig;
    }

    return NULL;
}

void nullLL(Nodo ** lista){
    Nodo * currentNodo = *lista;
    Nodo * nextNodo;

    while (currentNodo != NULL){
        nextNodo = currentNodo->sig;
        free(currentNodo);
        currentNodo = nextNodo;
    }
}

void printLista(Nodo * lista){
    Nodo * currentNodo = lista;

    while (currentNodo != NULL){
        printNodo(currentNodo);
        currentNodo = currentNodo->sig;
    }
}

void printNodo(Nodo * nodo){

    if (strcmp(nodo->info->tipo, "int") == 0){
        printf("Tipo: int\n");
        printf("Nombre: %s\n", nodo->info->nombre);
        printf("Valor: %d\n", nodo->info->intvalor);
    }
    else if (strcmp(nodo->info->tipo, "float") == 0){
        printf("TIpo: float\n");
        printf("Nombre: %s \n", nodo->info->nombre);
        printf("Valor: %f\n", nodo->info->floatvalor);
    }
    else if (strcmp(nodo->info->tipo, "char") == 0){
        printf("Tipo: char\n");
        printf("Nombre: %s \n", nodo->info->nombre);
        printf("Valor: %c\n", nodo->info->charvalor);
    }

    printf("-->\n");
}