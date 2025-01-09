CC = gcc
BISON = bison
FLEX = flex

all: parser run

parser: lex.yy.c pf.tab.c
	$(CC) lex.yy.c pf.tab.c -o parser.exe

lex.yy.c: pf.l pf.tab.h
	$(FLEX) pf.l

pf.tab.c pf.tab.h: pf.y
	$(BISON) -d pf.y

run:
	parser.exe

clean:
	del /Q parser.exe lex.yy.c pf.tab.c pf.tab.h output.txt 2>nul
