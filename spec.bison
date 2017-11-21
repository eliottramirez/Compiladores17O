%{
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
%token puntocoma 18
%token coma 19
%token parentesisabre 20
%token parentesiscierra 21
%token llaveabre 22
%token llavecierra 23
%token mayorigual 24
%token menorigual 25
%token mayor 26
%token menor 27
%token igual 28
%token noigual 29
%token mas 30
%token menos 31
%token por 32
%token entre 33
%token gato 34
%token punto 35
%%
PROGRAMA: PROTOTIPOS CTES DECLS FUN_PRINCIPAL FUN_DECLS
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

DECL: entero LISTA_ID
| flotante LISTA_ID
| caracter LISTA_ID
;

LISTA_ID: id
| LISTA_ID coma id
;

FUN_DECLS: /* empty */
| FUN_DECLS FUN_DECL
;

FUN_PRINCIPAL: funcionprincipal parentesisabre parentesiscierra CUERPO
;

FUN_DECL: ENCA DECLS CUERPO
;

ENCA: funcion id parentesisabre ARGS parentesiscierra
| funcion id parentesisabre parentesiscierra
;

ARGS: id
| id coma ARGS
;
CUERPO: llaveabre LISTA_INS llavecierra
;

LISTA_INS: INS
| INS puntocoma LISTA_INS
;

INS: id igual EXP
| directiva paraleliza
| si COND entonces INSTS otro INSTS
| si COND entonces INSTS
| mientras COND haz INSTS
| regresa parentesisabre EXP parentesiscierra
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
| id parentesisabre parentesiscierra
| id parentesisabre LISTA_EXP parentesiscierra
| numero
| parentesisabre EXP parentesiscierra
;

LISTA_EXP: EXP
| EXP coma LISTA_EXP
;

RELOP: mayorigual
| menorigual
| mayor
| menor
| igual
| noigual
;

ADOP: mas
| menos
;

MULOP: por
| entre
;
%%
