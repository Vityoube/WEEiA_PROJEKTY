all: comp

CFLAGS=-Wall

comp:  main.o init.o emitter.o lexer.o parser.o error.o symbol.o
	flex lexer.l && bison parser.y -o parser.c -l -d -y
	cc -g -Wall main.c init.c emitter.c lexer.c error.c parser.c symbol.c -o comp -lfl
main.o: main.c global.h
	cc -c main.c
init.o: init.c global.h
	cc -c init.c 
emitter.o: emitter.c global.h
	cc -c emitter.c
error.o: error.c global.h
	cc -c error.c
lexer.o: lexer.c global.h
	cc -c lexer.c
parser.o: parser.c global.h
	cc -c parser.c
symbol.o: symbol.c global.h
	cc -c symbol.c
.PRECIOUS: comp
.PHONY : comp
.EXPORT_ALL_VARIABLES: 1
clean:
	rm comp lexer.c main.o init.o emitter.o lexer.o parser.o error.o symbol.o
.PRECIOUS: main.o

include dependencies.inc
