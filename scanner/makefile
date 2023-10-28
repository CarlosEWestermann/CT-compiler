CC = gcc
BISON = bison
FLEX = flex

OBJECTS = main.o functions.o parser.tab.o lex.yy.o
EXECUTABLE = etapa2

all: $(EXECUTABLE)

functions.o: functions.c
	$(CC) $< -c 

main.o: main.c
	$(CC) $< -c

parser_errors.o: parser_errors.c
	$(CC) $< -c

parser.tab.c parser.tab.h: parser.y
	$(BISON) -d $<

lex.yy.c: parser.tab.h
	$(FLEX) $<

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.PHONY: run clean

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS) lex.yy.c parser.tab.c parser.tab.h
