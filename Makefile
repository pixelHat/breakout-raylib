CC := gcc
CFLAGS := -Wall -I/usr/include/raylib -lraylib -lm -lpthread -ldl -lrt -lX11

SRC := src/main.c
EXEC := my_game

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(SRC) -o $(EXEC) $(CFLAGS)

clean:
	rm -f $(EXEC)

