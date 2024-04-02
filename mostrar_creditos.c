#include "mostrar_creditos.h"


void mostrar_creditos(WINDOW *win) {
    wclear(win);
    waddstr(win, "Criador:Alysson Fernandes\n");
    waddstr(win, "Pressione qualquer tecla para voltar\n");
    wrefresh(win);
    wgetch(win);
}
