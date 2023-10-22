CC = gcc

OBJECTS = main.o functions.o
EXECUTABLE = main

all: $(EXECUTABLE)

functions.o: functions.c
	$(CC) $< -c 

main.o: main.c
	$(CC) $< -c

lex.yy.c: scanner.l
	flex $<

$(EXECUTABLE): $(OBJECTS) lex.yy.c
	$(CC) $(OBJECTS) lex.yy.c -o $@

.PHONY: run clean

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS) lex.yy.c