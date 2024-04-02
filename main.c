#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include "modo_livre.h"
#include "iniciar_jogo.h"
#include "mostrar_creditos.h"
#include "menu_principal.h"


int main() {
    initscr();
    keypad(stdscr, TRUE);

    int altura, largura;
    getmaxyx(stdscr, altura, largura);
    WINDOW *win = newwin(altura, largura, 0, 0);

    menu_principal(win);

    endwin();
    return 0;
}
