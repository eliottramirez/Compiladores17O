#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tablas.c"
#include "lex.yy.c"
#include "specbison.tab.c"

extern int yylex();
extern int yyparse();

int yywrap();
int manejaID(char id[]);
int errorHandler(int codigoError);

int valorNum;
char *valorString;
int idToken;
extern int numLinea;

extern Nodo * tablaGlobal[];
extern Nodo * tablaLocal[];
extern Nodo * apID;
int declaracion = 0;
int esGlobal = 0;

int main (int argc, char *argv[]){

    initTablas();

    yyin = fopen(argv[1], "r");

    do {
        yyparse();
    } while(idToken != 0);

    return 0;
}

int yywrap(){
    return 1;
}

int manejaID(char id[]){

    //printf("\nENTRÉ A manejaID() D: %d G: %d", declaracion, esGlobal);
    if (declaracion == 1){
        if (esGlobal == 1){
            apID = search(tablaGlobal, id);
            if (apID == NULL){
                apID = insert(tablaGlobal, initNodo("entero", id, 0, 0.0, '\0'));
            }
            else {
                errorHandler(-1);
            }
        }
        else {
            apID = search(tablaLocal, id);
            if (apID == NULL){
                apID = insert(tablaLocal, initNodo("entero", id, 0, 0.0, '\0'));
            }
            else {
                errorHandler(-1);
            }
        }
    }
    else {
        if (esGlobal == 1){
            apID = search(tablaGlobal, id);
            if (apID == NULL){
                errorHandler(-2);
                insert(tablaGlobal, initNodo("entero", id, 0, 0.0, '\0'));
            }
        }
        else {
            apID = search(tablaLocal, id);
            if (apID == NULL){
                apID = search(tablaGlobal, id);
                if (apID == NULL){
                    errorHandler(-2);
                    apID = insert(tablaLocal, initNodo("entero", id, 0, 0.0, '\0'));
                }
            }
        }
    }

    /*printf("\nSALÍ DE manejaID():");
    printf("\nTABLA GLOBAL:\n");
    printTabla(tablaGlobal);
    printf("---------------------------");
    printf("\nTABLA LOCAL:\n");
    printTabla(tablaLocal);
    printf("===========================\n\n");*/
}

int errorHandler(int codigoError){

    printf("\nERROR:");
    
    if (codigoError == -1){
        printf(" Variable '%s' redeclarada.", yytext);
    }
    else if (codigoError == -2){
        printf(" Variable '%s' no declarada.", yytext);
    }
    else if (codigoError == -3){
        printf(" Token '%s' no reconocido.", yytext);
    }
    
    printf(" Línea: %d\n", numLinea);

    return 0;
}