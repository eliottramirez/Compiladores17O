all: main

lex.yy.c: patterns
	flex patterns

main: lex.yy.c main.c
	gcc main.c -o main
