all: main

lex.yy.c: spec.flex
	flex spec.flex

main: lex.yy.c main.c
	gcc main.c -o main
