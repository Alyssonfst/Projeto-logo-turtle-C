#include "modo_livre.h"

void modo_livre(WINDOW *win) {
    wclear(win);
    int altura, largura;
    getmaxyx(win, altura, largura);
    altura -= 1;
    largura -= 1;

    int x = largura / 2;
    int y = altura / 2;

    keypad(win, TRUE);

    while (1) {
        mvwaddch(win, y, x, '#');
        wrefresh(win);

        int tecla = wgetch(win);

        if (tecla == KEY_UP) {
            y -= 1;
        } else if (tecla == KEY_DOWN) {
            y += 1;
        } else if (tecla == KEY_LEFT) {
            x -= 1;
        } else if (tecla == KEY_RIGHT) {
            x += 1;
        } else if (tecla == 27) {
            endwin();
            exit(0);
        } else if (tecla == 'q') {
            wclear(win);
            x = largura / 2;
            y = altura / 2;
            continue;
        }

        if (x < 0) {
            x = 0;
        } else if (x >= largura) {
            x = largura - 1;
        }
        if (y < 0) {
            y = 0;
        } else if (y >= altura) {
            y = altura - 1;
        }
    }
}
