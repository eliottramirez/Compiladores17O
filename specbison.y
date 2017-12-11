%{
	
	extern Nodo * apID;
	extern Nodo * apFun;
	extern int valorNum;
	extern int flagDecl;
	extern int flagGlobal;
	extern int flagTipo;
	extern int flagFun;
    
	extern void yyerror(char* s);
	extern void purgeTabla(Nodo * tabla[]);
	extern void printTabla(Nodo * tabla[]);

	int tipoLadoIzq;
	char nombreBib[20];

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

PROGRAMA: {flagGlobal = 1; flagDecl = 1; flagFun = 0;} PROTOTIPOS {flagTipo = 3; printf("\n");} CTES {printf("\n");} DECLS {printf("\n");} FUN_DECLS {flagDecl = 0;} FUN_PRINCIPAL 
;

PROTOTIPOS: incluye menor {flagDecl = -1; printf("#include<");} id {strcpy(nombreBib, yytext);} punto {strcat(nombreBib, ".");} id {strcat(nombreBib, yytext);} mayor {flagDecl = 1; flagGlobal = -1; manejaID(nombreBib); flagGlobal = 1; printf("%s>\n", apID->info->nombre);} PROTOTIPOS
| /* empty */
;

CTES: /* empty */
| CTES define id {printf("#define %s ", yytext, valorNum);} numero {printf("%d\n", valorNum);}
;

DECLS: {flagDecl = 1; flagFun = 0;} DECL punto_coma {printf(";\n");flagDecl = 0;} DECLS
| /* empty */
;

DECL: entero {flagTipo = 3; printf("int ");} LISTA_ID
| flotante {flagTipo = 4; printf("float ");} LISTA_ID
| caracter {flagTipo = 5; printf("char ");} LISTA_ID
;

LISTA_ID: id {printf("%s", yytext);} L
;

L: coma id {printf(", %s", yytext);} L
| /* empty */
; 

FUN_DECLS: {flagDecl = 1; flagGlobal =1; flagFun = 1;} FUN_DECL FUN_DECLS
| /* empty */
;

FUN_PRINCIPAL: funcionprincipal paren_open paren_close {printf("int main()");} CUERPOFUN
;

FUN_DECL: ENCA CUERPOFUN
;

ENCA: funcion TIPO id {apFun = apID; printf("%s", apFun->info->nombre);} paren_open {printf("(");} {flagGlobal = 0; flagDecl = 1;} F
;

TIPO: entero {flagTipo = 3; printf("int ");}
| flotante {flagTipo = 4; printf("float ");}
| caracter {flagTipo = 5; printf("char ");}
;

F: {flagFun = 0;} ARGS paren_close {apFun->info->numArgs = $2; flagDecl = 0; printf(")");}
| paren_close {apFun->info->numArgs = 0; flagDecl = 0; printf(")");}
;

ARGS: TIPO id {$$ = 1; printf("%s", apID->info->nombre);}
| TIPO id {printf("%s", apID->info->nombre);} coma {printf(", ");} ARGS {$$ = 1 + $6;}
;

CUERPOFUN: llave_open {flagGlobal = 0; printf("{\n");} DECLS LISTA_INS llave_close {purgeTabla(tablaLocal); flagGlobal = 1; printf("\n}\n\n");}
;

CUERPO: llave_open {printf("{\n");} LISTA_INS llave_close {printf("\n}\n");};
;

LISTA_INS: INS 
| INS LISTA_INS
;

INS: id {tipoLadoIzq = apID->info->tipo; printf("%s", apID->info->nombre);} igual {printf(" = ");} EXP {if ($5 != tipoLadoIzq) errorHandler(-4);} punto_coma {printf(";\n");}
| directiva paraleliza punto_coma {printf(";\n");}
| si {printf("if (");} COND entonces {printf(") ");} INSTS
| mientras {printf("while (");} COND haz INSTS
| regresa paren_open {printf("return (");} EXP paren_close punto_coma {printf(");"); if ($4 != apFun->info->tipo) {errorHandler(-8);}}
;

INSTS: INS
| CUERPO
;

COND: EXP RELOP EXP {if ($1 != $3) errorHandler(-4); }
;

EXP: TERMINO {$$ = $1;}
| EXP ADOP TERMINO {if (($1 == 3) && ($3 == 3)) $$ = 3; else if (($1 == 4) && ($3 == 4)) $$ = 4; else errorHandler(-4);}
;

TERMINO: FACTOR {$$ = $1;}
| TERMINO MULOP FACTOR {if (($1 == 3) && ($3 == 3)) $$ = 3; else if (($1 == 4) && ($3 == 4)) $$ = 4; else errorHandler(-4);}
;

FACTOR: id {$$ = apID->info->tipo; printf("%s", apID->info->nombre);}
| id paren_open paren_close {apFun = apID; $$ = apFun->info->tipo; printf("%s ()", apFun->info->nombre); if (apFun->info->numArgs != 0) errorHandler(-5);}
| id paren_open {apFun = apID; printf("%s(", apFun->info->nombre);} LISTA_EXP paren_close {printf(")"); $$ = apFun->info->tipo; if (apFun->info->numArgs != $4) errorHandler(-5);}
| numero { $$ = 3; printf("%d", valorNum);}
| paren_open {printf("(");} EXP paren_close {printf(")"); $$ = $3;}
;

LISTA_EXP: EXP {$$ = 1;}
| EXP coma {printf(", ");} LISTA_EXP {$$ = 1 + $4;}
;

RELOP: mayor_igual {printf(" >= ");}
| menor_igual {printf(" <= ");}
| mayor {printf(" > ");}
| menor {printf(" < ");}
| igual {printf(" == ");}
| no_igual {printf(" != ");}
;

ADOP: mas {printf(" + ");}
| menos {printf(" - ");}
;

MULOP: por {printf(" * ");}
| entre {printf(" / ");}
;
%%

void yyerror(char *cadena){
	errorHandler(-6);
	
}
