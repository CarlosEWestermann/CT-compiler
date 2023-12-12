CC = gcc
BISON = bison
FLEX = flex
CFLAGS = -Wall -Wno-unused-function #-fsanitize=address

OBJECTS = main.o scanner_functions.o AST_functions.o parser.tab.o lex.yy.o symbol_table.o
EXECUTABLE = etapa4

all: $(EXECUTABLE)

AST_functions.o: AST_functions.c
	$(CC) $(CFLAGS) $< -c

scanner_functions.o: scanner_functions.c
	$(CC) $(CFLAGS) $< -c 

main.o: main.c parser.tab.h 
	$(CC) $(CFLAGS) $< -c

symbol_table.o: symbol_table.c
	$(CC) $(CFLAGS) $< -c

parser.tab.c parser.tab.h: parser.y
	$(BISON) -d $< 

parser.tab.o: parser.tab.c
	$(CC) $(CFLAGS) $< -c

lex.yy.c: scanner.l
	$(FLEX) $<

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) $< -c

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.PHONY: run clean

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS) lex.yy.c parser.tab.c parser.tab.h
