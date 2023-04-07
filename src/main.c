#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>
#include <locale.h>
#include "header.h"

int main () {

    setlocale(LC_ALL, "portuguese-brazilian"); 
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    menu();
    prologo();

    refresh();
    getch();
    endwin();
    return(0);
}
