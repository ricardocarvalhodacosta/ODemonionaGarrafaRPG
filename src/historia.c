#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void prologo () {
    char *prologo = "historia/prologo.txt"; // nome do arquivo
    FILE *fp;
    char ch;
    int lines = 0, chars = 0;

    // Abre o arquivo
    fp = fopen(prologo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Lê o número de linhas e caracteres no arquivo
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
        chars++;
    }

    // Fecha o arquivo
    fclose(fp);

    // Inicializa a biblioteca ncurses
    initscr();
    noecho();
    curs_set(FALSE);

    // Cria a janela
    WINDOW *win = newwin(lines + 2, chars + 2, 0, 0);
    // box(win, 0, 0); // adiciona uma borda à janela

    // Abre o arquivo novamente e imprime o conteúdo na janela
    fp = fopen(prologo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int x = 1, y = 1;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            y++;
            x = 1;
        } else {
            mvwaddch(win, y, x, ch);
            x++;
        }
    }

    // Fecha o arquivo
    fclose(fp);

    // Atualiza a janela
    wrefresh(win);

    // Aguarda a tecla ser pressionada
    getch();

    // Finaliza a biblioteca ncurses
    endwin();

    getch();
}
