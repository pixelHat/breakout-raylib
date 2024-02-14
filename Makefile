CC := gcc
CFLAGS := -Wall -I/usr/include/raylib -lraylib -lm -lpthread -ldl -lrt -lX11

SRC := src/*
EXEC := game.o

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(SRC) -o $(EXEC) $(CFLAGS)
	"./$(EXEC)"

clean:
	rm -f $(EXEC)
