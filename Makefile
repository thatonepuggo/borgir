CC=gcc
OUTPUT=borgir
FILES=main.c
FLAGS=-Wall -std=c99 -g

build:
	$(CC) $(FLAGS) -o $(OUTPUT) $(FILES)

.PHONY: clean
clean:
	rm $(OUTPUT)

install: build
	install ./$(OUTPUT) /usr/bin/
