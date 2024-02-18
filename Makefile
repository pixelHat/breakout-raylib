CC := gcc
CFLAGS := -Wall -I/usr/include/raylib -lraylib -lm -lpthread -ldl -lrt -lX11

SRC := src/*
EXEC := game.o

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(SRC) -o $(EXEC) $(CFLAGS)
	"./$(EXEC)"
wasm:
	mkdir -p dist
	emcc -o dist/index.html src/*.c -Wall -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -Os -I. -I ./lib/raylib -I ./lib/raylib/external -L. -L ./lib/raylib -s USE_GLFW=3 -s ASYNCIFY -s TOTAL_MEMORY=67108864 -s FORCE_FILESYSTEM=1 --preload-file sounds --preload-file graphics --preload-file fonts --shell-file ./lib/raylib/shell.html ./lib/raylib/web/libraylib.a -DPLATFORM_WEB -s 'EXPORTED_FUNCTIONS=["_free","_malloc","_main"]' -s EXPORTED_RUNTIME_METHODS=ccall
clean:
	rm -f $(EXEC)
