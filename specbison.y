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

	extern FILE *output;

	int tipoLadoIzq;
	char nombreBib[20];

%}
%start PROGRAMA

%nonassoc IFX
%nonassoc otro

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

PROGRAMA: {flagGlobal = 1; flagDecl = 1; flagFun = 0;} PROTOTIPOS {flagTipo = 3; fprintf(output, "\n");} CTES {fprintf(output, "\n");} DECLS {fprintf(output, "\n");} FUN_DECLS {flagDecl = 0;} FUN_PRINCIPAL 
;

PROTOTIPOS: incluye menor {flagDecl = -1; fprintf(output, "#include<");} id {strcpy(nombreBib, yytext);} punto {strcat(nombreBib, ".");} id {strcat(nombreBib, yytext);} mayor {flagDecl = 1; flagGlobal = -1; manejaID(nombreBib); flagGlobal = 1; fprintf(output, "%s>\n", apID->info->nombre);} PROTOTIPOS
| /* empty */
;

CTES: /* empty */
| CTES define id {fprintf(output, "#define %s ", yytext, valorNum);} numero {fprintf(output, "%d\n", valorNum);}
;

DECLS: {flagDecl = 1; flagFun = 0;} DECL punto_coma {fprintf(output, ";\n");flagDecl = 0;} DECLS
| /* empty */
;

DECL: entero {flagTipo = 3; fprintf(output, "int ");} LISTA_ID
| flotante {flagTipo = 4; fprintf(output, "float ");} LISTA_ID
| caracter {flagTipo = 5; fprintf(output, "char ");} LISTA_ID
;

LISTA_ID: id {fprintf(output, "%s", yytext);} L
;

L: coma id {fprintf(output, ", %s", yytext);} L
| /* empty */
; 

FUN_DECLS: {flagDecl = 1; flagGlobal =1; flagFun = 1;} FUN_DECL FUN_DECLS
| /* empty */
;

FUN_PRINCIPAL: funcionprincipal paren_open paren_close {fprintf(output, "int main()");} CUERPOFUN
;

FUN_DECL: ENCA CUERPOFUN
;

ENCA: funcion TIPO id {apFun = apID; fprintf(output, "%s", apFun->info->nombre);} paren_open {fprintf(output, "(");} {flagGlobal = 0; flagDecl = 1;} F
;

TIPO: entero {flagTipo = 3; fprintf(output, "int ");}
| flotante {flagTipo = 4; fprintf(output, "float ");}
| caracter {flagTipo = 5; fprintf(output, "char ");}
;

F: {flagFun = 0;} ARGS paren_close {apFun->info->numArgs = $2; flagDecl = 0; fprintf(output, ")");}
| paren_close {apFun->info->numArgs = 0; flagDecl = 0; fprintf(output, ")");}
;

ARGS: TIPO id {$$ = 1; fprintf(output, "%s", apID->info->nombre);}
| TIPO id {fprintf(output, "%s", apID->info->nombre);} coma {fprintf(output, ", ");} ARGS {$$ = 1 + $6;}
;

CUERPOFUN: llave_open {flagGlobal = 0; fprintf(output, "{\n");} DECLS LISTA_INS llave_close {purgeTabla(tablaLocal); flagGlobal = 1; fprintf(output, "\n}\n\n");}
;

CUERPO: llave_open {fprintf(output, "{\n");} LISTA_INS llave_close {fprintf(output, "\n}\n");};
;

LISTA_INS: INS 
| INS LISTA_INS
;

INS: id {tipoLadoIzq = apID->info->tipo; fprintf(output, "%s", apID->info->nombre);} igual {fprintf(output, " = ");} EXP {if ($5 != tipoLadoIzq) errorHandler(-4);} punto_coma {fprintf(output, ";\n");}
| directiva paraleliza punto_coma {fprintf(output, ";\n");}
| si {fprintf(output, "if (");} COND entonces {fprintf(output, ") ");} INSTS H
| mientras {fprintf(output, "while (");} COND haz INSTS
| regresa paren_open {fprintf(output, "return (");} EXP paren_close punto_coma {fprintf(output, ");"); if ($4 != apFun->info->tipo) {errorHandler(-8);}}
;

H: /* empty */
| otro INSTS
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

FACTOR: id {$$ = apID->info->tipo; fprintf(output, "%s", apID->info->nombre);}
| id paren_open paren_close {apFun = apID; $$ = apFun->info->tipo; fprintf(output, "%s ()", apFun->info->nombre); if (apFun->info->numArgs != 0) errorHandler(-5);}
| id paren_open {apFun = apID; fprintf(output, "%s(", apFun->info->nombre);} LISTA_EXP paren_close {fprintf(output, ")"); $$ = apFun->info->tipo; if (apFun->info->numArgs != $4) errorHandler(-5);}
| numero { $$ = 3; fprintf(output, "%d", valorNum);}
| paren_open {fprintf(output, "(");} EXP paren_close {fprintf(output, ")"); $$ = $3;}
;

LISTA_EXP: EXP {$$ = 1;}
| EXP coma {fprintf(output, ", ");} LISTA_EXP {$$ = 1 + $4;}
;

RELOP: mayor_igual {fprintf(output, " >= ");}
| menor_igual {fprintf(output, " <= ");}
| mayor {fprintf(output, " > ");}
| menor {fprintf(output, " < ");}
| igual {fprintf(output, " == ");}
| no_igual {fprintf(output, " != ");}
;

ADOP: mas {fprintf(output, " + ");}
| menos {fprintf(output, " - ");}
;

MULOP: por {fprintf(output, " * ");}
| entre {fprintf(output, " / ");}
;
%%

void yyerror(char *cadena){
	errorHandler(-6);
	
}
