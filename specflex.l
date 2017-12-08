%{
    #include "specbison.tab.h"

    extern int errorHandler(int codigoError);

    extern int valorNum;
    extern char *valorString;
    extern int manejaID(char id[]);

    int numLinea = 1;
     
%}
l   [a-zA-Z]
d   [0-9]
%%
<<EOF>>     {return (0);}
\n          {numLinea++;}
" "         {/*Espacio en blanco;*/}
entero      {return (3);}
flotante    {return (4);}
caracter    {return (5);}
si          {return (6);}
entonces    {return (7);}
otro        {return (8);}
mientras    {return (9);}
haz         {return (10);}
regresa     {return (11);}
directiva   {return (12);}
paraleliza  {return (13);}
incluye     {return (14);}
define      {return (15);}
funcion     {return (16);}
funcionprincipal {return (17);}
{l}({l}|{d})*   {
    manejaID(yytext);

    valorString = yytext;
    return (1);
}
{d}+    {
    valorNum = atoi(yytext);
    return (2);
}
"."     {return (18);}
[;]     {return (19);}
[,]     {return (20);}
"#"     {return (21);}
[(]     {return (22);}
[)]     {return (23);}
[{]     {return (24);}
[}]     {return (25);}
">="    {return (26);}
"<="    {return (27);}
[>]     {return (28);}
[<]     {return (29);}
[=]     {return (30);}
"<>"    {return (31);}
[+]     {return (32);}
[-]     {return (33);}
[*]     {return (34);}
"/"     {return (35);}

.       {errorHandler(-3);}
%%
