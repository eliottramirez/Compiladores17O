%{
    int numLinea = 0;
    extern int valorNum;
    extern char *valorString;
    //extern Nodo * apID;
%}
l   [a-zA-Z]
d   [0-9]
%%
<<EOF>>     {return 0;}
\n          {numLinea++;}
" "         {/*Espacio en blanco;*/}
entero         {return 22;}
flotante       {return 23;}
caracter        {return 24;}
si          {return 25;}
entonces    {return 26;}
otro        {return 27;}
mientras    {return 28;}
haz         {return 29;}
regresa     {return 30;}
directiva   {return 31;}
paraleliza  {return 32;}
{l}({l}|{d})*   {
    valorString = yytext;
    return 1;
}
{d}+    {
    valorNum = atoi(yytext);
    return 2;
}
[;]     {return 3;}
[,]     {return 4;}
[(]     {return 5;}
[)]     {return 6;}
[{]     {return 7;}
[}]     {return 8;}
[[]     {return 9;}
[]]     {return 10;}
">="    {return 11;}
"<="    {return 12;}
[>]     {return 13;}
[<]     {return 14;}
[=]     {return 15;}
"!="    {return 16;}
"=="    {return 17;}
[+]     {return 18;}
[-]     {return 19;}
[*]     {return 20;}
"/"     {return 21;}
.       {printf("Error.\n");}
%%
