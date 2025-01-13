CC = gcc
BISON = bison
FLEX = flex

all: parser run

parser: lex.yy.c 2007007.tab.c
	$(CC) lex.yy.c 2007007.tab.c -o parser.exe

lex.yy.c: 2007007.l 2007007.tab.h
	$(FLEX) 2007007.l

2007007.tab.c 2007007.tab.h: 2007007.y
	$(BISON) -d 2007007.y

run:
	parser.exe

clean:
	del /Q parser.exe lex.yy.c 2007007.tab.c 2007007.tab.h testout.txt 2>nul
