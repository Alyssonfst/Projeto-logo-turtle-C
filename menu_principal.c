#include "menu_principal.h"

void menu_principal() {
    initscr();
    keypad(stdscr, TRUE);

    int altura, largura;
    getmaxyx(stdscr, altura, largura);
    WINDOW *win = newwin(altura, largura, 0, 0);

    while (1) {
        wclear(win);
        waddstr(win, "Menu Principal\n");
        waddstr(win, "1 - Iniciar Jogo\n");
        waddstr(win, "2 - Criadores\n");
        waddstr(win, "3 - Sair\n");
        waddstr(win, "4 - Modo Livre\n");
        wrefresh(win);

        int key = wgetch(win);
        if (key == '1') {
            iniciar_jogo(win);
        } else if (key == '2') {
            mostrar_creditos(win);
        } else if (key == '3') {
            break;
        } else if (key == '4') {
            modo_livre(win);
        }
    }

    endwin();
}
