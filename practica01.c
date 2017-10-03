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
    Inicializa un Nodo.
 
    @param nombre
    @param tipo
    @param intvalor
    @param floatvalor
    @param charvalor
 
    @return Un 'Nodo *' inicializado
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
int deleteNodo(Nodo ** lista, char nombre[]);


Nodo * lista = NULL;

int main(){

    int menu = 0;
    
    printf("Bienvenido, ");
    
    while (menu != 4){
        
        if (menu == 0){
            printf("¿qué desea hacer?:\n\
                   1. Dar de alta una variable.\n\
                   2. Dar de baja una variable.\n\
                   3. Imprimir la lista de variables.\n\
                   4. Salir.\n\
                   ");
            
            scanf("%d", &menu);
        }
        else if (menu == 1){
            
            char nombre[40];
            char tipo[10];
            int intvalor;
            float floatvalor;
            char charvalor;
            
            printf("Proporcione tipo de la variable: \n");
            scanf("%s", tipo);
            
            if ((strcmp("int", tipo) != 0) && (strcmp("float", tipo) != 0) && (strcmp("char", tipo) != 0)){
                printf("Tipo inválido.");
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
                
                insertNodo(&lista, initNodo(nombre, tipo, intvalor, floatvalor, charvalor));
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
            printf("Error en menu.\n");
            menu = 4;
        }
    }
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
    Nodo * currentNodo = lista;

    while (currentNodo != NULL){
        printf("\
        Nombre: %s \n\
        Tipo: %s \n\
        Valor entero: %d \n\
        Valor float: %f \n\
        Valor char: %c \n\
         ->\n",
        currentNodo->info->nombre,
        currentNodo->info->tipo,
        currentNodo->info->intvalor,
        currentNodo->info->floatvalor,
        currentNodo->info->charvalor);
        
        currentNodo = currentNodo->sig;
    }
}

void insertNodo(Nodo ** lista, Nodo * newNodo){
    newNodo->sig = *lista;
    *lista = newNodo;
}

int deleteNodo(Nodo ** lista, char nombre[]){
    Nodo * currentNodo = *lista;
    
    if (strcmp(currentNodo->info->nombre, nombre) != 0){
        
        while ((currentNodo->sig != NULL) && (strcmp(currentNodo->sig->info->nombre, nombre)) != 0){
            currentNodo = currentNodo->sig;
            currentNodo->sig = currentNodo->sig->sig;
        }
        
        if (currentNodo->sig != NULL){
            currentNodo->sig = currentNodo->sig->sig;
            free(currentNodo->sig);
            
            return 1;
        }
        else {
            return -1;
        }
        
    }
    else {
        *lista = currentNodo->sig;
        free(currentNodo);
        
        return 1;
    }
}
