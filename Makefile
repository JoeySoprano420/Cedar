CC = gcc
FLEX = flex
BISON = bison
NASM = nasm
LD = ld

CFLAGS = -Wall -g
LDFLAGS =

SRC = compiler/src
IR = compiler/ir
BIN = compiler/bin

all: $(BIN)/cedarc.exe

$(BIN)/cedarc.exe: $(SRC)/cedar_lexer.c $(SRC)/cedar_parser.c $(SRC)/cedar_ast.c $(SRC)/cedar_codegen.c $(SRC)/cedar_linker.c
	$(CC) $(CFLAGS) -o $@ $^

lexer: $(SRC)/cedar_lexer.c
	$(FLEX) -o $(SRC)/lex.yy.c $^

parser: $(SRC)/cedar_parser.c
	$(BISON) -d -o $(SRC)/cedar_parser.tab.c $^

nasm:
	$(NASM) -f elf32 hello.asm -o hello.o
	$(LD) -m elf_i386 -s -o hello hello.o

clean:
	rm -f $(BIN)/*.exe *.o *.asm *.out *.tab.* lex.yy.c

.PHONY: all clean lexer parser nasm