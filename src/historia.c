#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void prologo () {

    WINDOW *prologo;
    clear();
    prologo=newwin(30, 100, 5, 10);
    box(prologo, 0, 0);
    keypad(prologo, TRUE);
    mvwprintw(prologo, 1, 2, "Bem-vindo a Arkadia, um vilarejo repleto de harmonia e felicidades...");
    mvwprintw(prologo, 2, 2, "Pelo menos é o que diziam antigamente. Hoje, Arkadia é a entrada para um verdadeiro");
    mvwprintw(prologo, 3, 2, "inferno no reino de Melkior. Tudo isso, graças ao infortunio que se abateu para");
    mvwprintw(prologo, 4, 2, "um grupo de aventureiros que buscavam fortuna.");
    mvwprintw(prologo, 5, 2, "Baltazar, o demônio da perdição encontrava-se aprisionado em uma masmorra a"); 
    mvwprintw(prologo, 6, 2, "muito esquecida. Antigo antro de cantigos profanos de cultistas malignos, a masmorra");
    mvwprintw(prologo, 7, 2, "permaneceu intocada durante séculos. Hoje, novamente ativa, o lugar tornou-se um verdadeiro ");
    mvwprintw(prologo, 8, 2, "inferno dentro do reino de Melkior.");
    mvwprintw(prologo, 9, 2, "Agora, você será um verdadeiro herói?");
    mvwprintw(prologo, 10, 2, "Ou será só mais um covarde?");
    mvwprintw(prologo, 11, 2, "Irá derrotar Baltazar e libertar Arkadia de seu destino cruel?");
    mvwprintw(prologo, 13, 2, "Bom, vamos descobrir...");
    wrefresh(prologo);
    wgetch(prologo);
    delwin(prologo);
}

void a1() {

    printf("oi");
}
