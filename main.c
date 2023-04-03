#include <ncurses.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char *choices[] = {"Continuar", "Novo Jogo", "Sair"};
int n_choices = ARRAY_SIZE(choices);

void menu(WINDOW *menu_win, int highlight);

int main()
{
    WINDOW *menu_win;
    int highlight = 1;
    int choice = 0;
    int c;

    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0); // oculta o cursor
    start_color(); // ativa o uso de cores
    init_pair(1, COLOR_RED, COLOR_BLACK); // define a cor do texto
    init_pair(2, COLOR_BLACK, COLOR_RED); // define a cor do fundo

    // cria a janela do menu com as dimensões 10x40, posicionada na linha 5 e coluna 10 da tela
    menu_win = newwin(10, 40, 5, 10);
    keypad(menu_win, TRUE);

    // define o título do menu
    mvprintw(2, 10, "O Demônio na Garrafa:");

    // desenha a borda da janela do menu
    box(menu_win, 0, 0);
    refresh();
    wrefresh(menu_win);

    // exibe as opções do menu
    menu(menu_win, highlight);

    // aguarda a seleção do usuário
    while (1)
    {
        c = wgetch(menu_win);
        switch (c)
        {
        case KEY_UP:
            if (highlight == 1)
                highlight = n_choices;
            else
                --highlight;
            break;
        case KEY_DOWN:
            if (highlight == n_choices)
                highlight = 1;
            else
                ++highlight;
            break;
        case 10:
            choice = highlight;
            break;
        default:
            break;
        }
        menu(menu_win, highlight);
        if (choice != 0)
            break;
    }

    // exibe a opção selecionada pelo usuário
    mvprintw(LINES - 2, 0, "Você escolheu a opção %d - %s\n", choice, choices[choice - 1]);
    getch();

    // libera a janela do menu e finaliza a biblioteca ncurses
    delwin(menu_win);
    endwin();
    return 0;
}

void menu(WINDOW *menu_win, int highlight)
{
    int i;
    int x = 2;
    int y = 3;

    for (i = 0; i < n_choices; ++i)
    {
        if (highlight == i + 1)
        {
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        }
        else
        {
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        }
        ++y;
    }
    wrefresh(menu_win);
}
