CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = src/main.c src/leitura_csv.c src/hash.c src/testes.c
OUT = programa.exe

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -f $(OUT)