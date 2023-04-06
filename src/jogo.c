#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>
#include "header.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char *escolhas[] = {"1. CONTINUAR;", "2. NOVO JOGO;", "3. SAIR."};
int nescolhas = ARRAY_SIZE(escolhas);

void menuop (WINDOW *janela, int destaque);

void menu () {

    WINDOW *janela;
    int destaque = 1;
    int escolha = 0;
    int c;

    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    janela = newwin(10, 40, 5, 10);
    keypad(janela, TRUE);

    box(janela, 0, 0);
    refresh();
    wrefresh(janela);

    menuop(janela, destaque);

    while (1)
    {
        c = wgetch(janela);
        switch (c)
        {
        case KEY_UP:
                if (destaque == 1)
                    destaque = nescolhas;
                else
                    --destaque;
            break;
        case KEY_DOWN:
                if (destaque == nescolhas)
                    destaque = 1;
                else
                    ++destaque;
            break;
        case 10:
                escolha = destaque;
            break;
        default:
            break;
        }
        menuop(janela, destaque);
        if (escolha != 0)
            break;
    }

    switch (escolha)
    {
    case 1:
        // Opção 1 - Continuar
        mvprintw(LINES - 2, 0, "Ok, vamos continuar...\n");
        clear();
        break;

    case 2:
        // Opção 2 - Novo Jogo
        prologo();
        clear();
        break;

    case 3:
        // Opção 3 - Sair
        mvprintw(LINES - 2, 0, "Até logo...\n");
        break;
    default:
        break;
    }
    getch();
    endwin();
}

void menuop(WINDOW *janela, int destaque) {
    int i;
    int x = 2;
    int y = 3;

    for (i = 0; i < nescolhas; i++)
    {
        if (destaque == i + 1){
            wattron(janela, A_REVERSE);
            mvwprintw(janela, y, x, "%s", escolhas[i]);
            wattroff(janela, A_REVERSE);
        } else {
            mvwprintw(janela, y, x, "%s", escolhas[i]);
        }
        ++y;
    }
    wrefresh(janela);
}
