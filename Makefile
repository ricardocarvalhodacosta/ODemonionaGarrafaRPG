# Variáveis
CC := gcc
CFLAGS := -Wall -g
INCLUDE := -Iinclude
LIBS := -L$(HOME)/Desktop/C/odemonionagarrafatest/include -lncurses -lSDL2 -lcaca -ljson-c
TARGET := bin/playgame

$(TARGET): build/historia.o build/jogo.o build/main.o build/opcoes.o
	$(CC) $(CFLAGS) $(INCLUDE) -o $(TARGET) $^ $(LIBS)

build/historia.o: src/historia.c include/historia.h
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

build/jogo.o: src/jogo.c include/jogo.h include/historia.h
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

build/main.o: src/main.c include/jogo.h include/historia.h include/opcoes.h
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

build/opcoes.o: src/opcoes.c include/opcoes.h
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	rm -rf build/*.o $(TARGET)

