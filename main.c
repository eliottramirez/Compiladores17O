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
int idToken;
extern int numLinea;

extern Nodo * tablaGlobal[];
extern Nodo * tablaLocal[];

extern Nodo * apID;
extern Nodo * apFun;

int flagDecl = 0;
int flagGlobal = 0;
int flagTipo = 3;
int flagFun = 0;

char salida[100];

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
    if (flagDecl == -1){

    }
    else if (flagDecl == 1){

        if (flagGlobal == -1){
            apID = search(tablaGlobal, id);
            if (apID == NULL){
                apID = insert(tablaGlobal, initNodo(0, 36, id, 0, 0.0, '\0'));
            }
            else {
                errorHandler(-7);
            }
        }
        else if (flagGlobal == 1){
            apID = search(tablaGlobal, id);
            if (apID == NULL){
                apID = insert(tablaGlobal, initNodo(flagFun, flagTipo, id, 0, 0.0, '\0'));
            }
            else {
                errorHandler(-1);
            }
        }
        else if (flagGlobal == 0){
            apID = search(tablaLocal, id);
            if (apID == NULL){
                apID = insert(tablaLocal, initNodo(flagFun, flagTipo, id, 0, 0.0, '\0'));
            }
            else {
                errorHandler(-1);
            }
        }
    }
    else if (flagDecl == 0){

        if (flagGlobal == 1){
            apID = search(tablaGlobal, id);
            if (apID == NULL){
                errorHandler(-2);
                apID = insert(tablaGlobal, initNodo(flagFun, flagTipo, id, 0, 0.0, '\0'));
            }
        }
        if (flagGlobal == 0){
            apID = search(tablaLocal, id);
            if (apID == NULL){
                apID = search(tablaGlobal, id);
                if (apID == NULL){
                    errorHandler(-2);
                    apID = insert(tablaLocal, initNodo(flagFun, flagTipo, id, 0, 0.0, '\0'));
                }
            }
        }
    }
}

int errorHandler(int codigoError){

    printf("\nERROR en línea %d:", numLinea);

    switch (codigoError){
        case (-1):
            printf(" Variable '%s' redeclarada.", yytext);
            break;
        
        case (-2):
            printf(" Variable '%s' no declarada.", yytext);
            break;

        case (-3):
            printf(" Token '%s' no reconocido." , yytext);
            break;

        case (-4):
            printf(" Expresión inválida. Operandos con distintos tipos.");
            break;

        case (-5):
            printf(" Cantidad de argumentos incorrecto.");
            break;

        case (-6):
            printf(" Error de sintaxis.");
            break;

        case (-7):
            printf(" Bibloteca '%s' redeclarda.", apID->info->nombre);
            break;

        case (-8):
            printf(" Tipo de regreso inválido.");
            break;
    }

    return 0;
}