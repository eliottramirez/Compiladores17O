#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tablaSimbolos.c"
#include "lex.yy.c"

//extern Nodo *apID;

int yywrap();

/*int valorNum;
char *valorString;*/
int idToken;

int main (int argc, char *argv[]){
    yyin = fopen(argv[1], "r");
    
    idToken = yylex();
    while(idToken != 0){
        printf("%d: %s\n", idToken, yytext);
       
        idToken = yylex();
    }

    printf("\nNúmero de lineas: %d\n", numLinea);
}

int yywrap(){
    return 1;
}
