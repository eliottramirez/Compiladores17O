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

Nodo * initNodo(char tipo[], char nombre[], int intvalor, float floatvalor, char charvalor);
void printLista(Nodo * lista);
void insertNodo(Nodo ** lista, Nodo * newNodo);
int deleteNodo(Nodo ** lista, char nombre[]);

Nodo * lista = NULL;

int main(){

    int menu = 0;
    
    printf("Bienvenido. ");
    
    while (menu != 4){
        
        if (menu == 0){
            printf("¿Qué desea hacer?:\n\
                   1. Dar de alta una variable.\n\
                   2. Dar de baja una variable.\n\
                   3. Imprimir la lista de variables.\n\
                   4. Salir.\n\
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
                
                insertNodo(&lista, initNodo(tipo, nombre, intvalor, floatvalor, charvalor));
                menu = 0;
            }
        }
        else if (menu == 2){
            char nombre[40];
            int status = 0;
            
            printf("Proporcione el nombre de la variable a eliminar: \n");
            scanf("%s", nombre);
            
            status = deleteNodo(&lista, nombre);
            
            if (status == 1){
                printf("Variable encontrada y eliminada.\n");
            }
            else if (status == -1){
                printf("Variable no encontrada.\n");
            }
            
            menu = 0;
        }
        else if (menu == 3){
            printLista(lista);
            menu = 0;
        }
        else {
            printf("Opción inválida.\n");
            menu = 0;
        }
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
            printf("Nombre: %s \n", currentNodo->info->nombre);
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
