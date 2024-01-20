#UFRGS 2023
#Grupo K
#Carlos Eduardo Westermann - 00327212
#Théo Santiago Müller 00301593

CC = gcc
BISON = bison
FLEX = flex

OBJECTS = main.o functions.o parser.tab.o lex.yy.o
EXECUTABLE = etapa2

all: $(EXECUTABLE)

functions.o: functions.c
	$(CC) $< -c 

main.o: main.c parser.tab.h
	$(CC) $< -c

parser.tab.c parser.tab.h: parser.y
	$(BISON) -d $< 

parser.tab.o: parser.tab.c
	$(CC) $< -c

lex.yy.c: scanner.l
	$(FLEX) $<

lex.yy.o: lex.yy.c
	$(CC) $< -c

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.PHONY: run clean

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS) lex.yy.c parser.tab.c parser.tab.h
