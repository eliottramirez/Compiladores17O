%{
	extern int declaracion;
	extern int esGlobal;
    extern void yyerror(char* s);
%}
%start PROGRAMA
%token id 1
%token numero 2
%token entero 3
%token flotante 4
%token caracter 5
%token si 6
%token entonces 7
%token otro 8
%token mientras 9
%token haz 10
%token regresa 11
%token directiva 12
%token paraleliza 13
%token incluye 14
%token define 15
%token funcion 16
%token funcionprincipal 17
%token punto 18
%token punto_coma 19
%token coma 20
%token gato 21
%token paren_open 22
%token paren_close 23
%token llave_open 24
%token llave_close 25
%token mayor_igual 26
%token menor_igual 27
%token mayor 28
%token menor 29
%token igual 30
%token no_igual 31
%token mas 32
%token menos 33
%token por 34
%token entre 35
%%
PROGRAMA: PROTOTIPOS {declaracion = 1; esGlobal = 1;} CTES DECLS FUN_PRINCIPAL FUN_DECLS
;

PROTOTIPOS: gato incluye menor id punto id mayor PROTOTIPOS
| /* empty */
;

CTES: /* empty */
| CTES gato define id entero
;

DECLS: /* empty */
| DECLS DECL
;

DECL: entero LISTA_ID punto_coma
| flotante LISTA_ID punto_coma
| caracter LISTA_ID punto_coma
;

LISTA_ID: id
| LISTA_ID coma id
;

FUN_DECLS: /* empty */
| FUN_DECLS FUN_DECL
;

FUN_PRINCIPAL: funcionprincipal paren_open paren_close {esGlobal = 0;} CUERPO
;

FUN_DECL: ENCA DECLS {declaracion = 0;} CUERPO {purgeTabla(tablaLocal);}
;

ENCA: {declaracion = 1; esGlobal = 1;} funcion id {esGlobal = 0;} paren_open F
;

F: ARGS paren_close
| paren_close
;

ARGS: id
| id coma ARGS
;
CUERPO: llave_open LISTA_INS llave_close
;

LISTA_INS: INS punto_coma
| INS punto_coma LISTA_INS
;

INS: id igual EXP
| directiva paraleliza
| si COND entonces INSTS otro INSTS
| si COND entonces INSTS
| mientras COND haz INSTS
| regresa paren_open EXP paren_close
;

INSTS: INS
| CUERPO
;

COND: EXP RELOP EXP
;

EXP: TERMINO
| EXP ADOP TERMINO
;

TERMINO: FACTOR
| TERMINO MULOP FACTOR
;

FACTOR: id
| id paren_open paren_close
| id paren_open LISTA_EXP paren_close
| numero
| paren_open EXP paren_close
;

LISTA_EXP: EXP
| EXP coma LISTA_EXP
;

RELOP: mayor_igual
| menor_igual
| mayor
| menor
| igual
| no_igual
;

ADOP: mas
| menos
;

MULOP: por
| entre
;
%%

void yyerror(char *cadena){
	printf("Parse error: %s\n", cadena);
}
