#include "iniciar_jogo.h"
#include <curses.h>
#include <string.h>

void iniciar_jogo(WINDOW *win) {
    wclear(win);
    int altura, largura;
    getmaxyx(win, altura, largura);
    altura -= 1;
    largura -= 1;
    char tela[altura][largura];
    memset(tela, ' ', sizeof(tela));

    int x = largura / 2;
    int y = altura / 2;
    int tecla;

    while (1) {
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                mvwaddch(win, i, j, tela[i][j]);
            }
        }
        wrefresh(win);
        echo();
        curs_set(1);

        mvwprintw(win, altura, 0, "Digite um comando ('cima', 'baixo', 'esquerda', 'direita'): ");
        wrefresh(win);

        tecla = wgetch(win);

        if (tecla == 'q') {
            memset(tela, ' ', sizeof(tela));
            x = largura / 2;
            y = altura / 2;
            continue;
        }

        char comando[8];
        while (1) {
            mvwgetstr(win, 0, 0, comando);
            if (strcmp(comando, "cima") == 0 ||
                strcmp(comando, "baixo") == 0 ||
                strcmp(comando, "esquerda") == 0 ||
                strcmp(comando, "direita") == 0) {
                break;
            }
            mvwaddstr(win, 2, 0, "Comando inválido. Tente novamente.");
            wclrtoeol(win);
            wrefresh(win);
        }

        int num_movimentos;
        while (1) {
            char input[8];
            mvwgetstr(win, 1, 0, input);
            num_movimentos = atoi(input);
            if (num_movimentos > 0) {
                break;
            }
            mvwaddstr(win, y + 2, 0, "Valor inválido. Tente novamente.");
            wclrtoeol(win);
            wrefresh(win);
        }

        for (int i = 0; i < num_movimentos; i++) {
            tela[y][x] = '*';

            if (strcmp(comando, "cima") == 0) {
                y -= 1;
            } else if (strcmp(comando, "baixo") == 0) {
                y += 1;
            } else if (strcmp(comando, "esquerda") == 0) {
                x -= 1;
            } else if (strcmp(comando, "direita") == 0) {
                x += 1;
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
}
