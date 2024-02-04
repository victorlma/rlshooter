CC=gcc
CFLAGS=--std=c99 -Wall -ggdb
LIBS=`pkg-config --libs raylib` -lm
BUILDIR=build

.PHONY: run clean
run: game
	@$(BUILDIR)/$<

game: main.c
	@mkdir -p $(BUILDIR)
	$(CC) $(CFLAGS) $< -o $(BUILDIR)/$@ $(LIBS)


clean:
	rm -rf $(BUILDIR)
