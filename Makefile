CC=gcc
CFLAGS=--std=c99 -Wall -ggdb
LIBS=`pkg-config --libs raylib` -lm
BUILDIR=build
HEADERS=*.h

.PHONY: run clean
run: game
	@$(BUILDIR)/$<

game: main.c $(HEADERS)
	@mkdir -p $(BUILDIR)
	$(CC) $(CFLAGS) $< -o $(BUILDIR)/$@ $(LIBS)


clean:
	rm -rf $(BUILDIR)
