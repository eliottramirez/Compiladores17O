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
void deleteNodo(Nodo ** lista, char nombre[]);

void printMenu();

Nodo * lista = NULL;

int main(){

    int menu = 0;
    
    printf("Bienvenido, ");
    
    while (menu != 4){
        
        if (menu == 0){
            printMenu();
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
            else {
                printf("Error en tipo.");
                menu = 4;
            }
            
            insertNodo(&lista, initNodo(nombre, tipo, intvalor, floatvalor, charvalor));
            menu = 0;
        }
        else if (menu == 2){
            char nombre[40];
            
            printf("Proporcione el nombre de la variable a eliminar: \n");
            scanf("%s", nombre);
            
            deleteNodo(&lista, "z");
            menu = 0;
            
        }
        else if (menu == 3){
            
            printLista(lista);
            menu = 0;
        }
        else {
            printf("Error en menu.");
            menu = 4;
        }
    }
    
    
    /*insertNodo(&lista, initNodo("x", "int", 1, 0, '\0'));

    insertNodo(&lista, initNodo("y", "float", 0, 2, '\0'));
    
    insertNodo(&lista, initNodo("z", "char", 0, 0, '3'));

    deleteNodo(&lista, "z");
    
    printLista(lista);*/
}

void printMenu(){
    printf("¿que desea hacer?:\n\
           1. Dar de alta una variable.\n\
           2. Dar de baja una variable.\n\
           3. Imprimir la lista de variables.\n\
           4. Salir.\n\
           ");
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

void deleteNodo(Nodo ** lista, char nombre[]){
    Nodo * currentNodo = *lista;
    
    if (strcmp(currentNodo->info->nombre, nombre) != 0){
        
        while ((currentNodo->sig != NULL) && (strcmp(currentNodo->sig->info->nombre, nombre) != 0)){
            currentNodo = currentNodo->sig;
            currentNodo->sig = currentNodo->sig->sig;
        }
        
        if(currentNodo->sig != NULL){
            currentNodo->sig = currentNodo->sig->sig;
            free(currentNodo->sig);
        }
        
    }
    else {
        *lista = currentNodo->sig;
        free(currentNodo);
    }
}
