#include <ncurses.h>
#include "Board.h"
#include "SnakeGame.h"

#define BOARD_DIM 20
#define BOARD_ROW BOARD_DIM
#define BOARD_COL BOARD_ROW * 2

int main(){
    initscr();
    refresh();
    noecho();
    cbreak();

    SnakeGame game(BOARD_ROW, BOARD_COL);
    while(!game.isOver()){
        game.processInput();
        game.updateState();
        game.redraw();
    }

    getch();
    endwin();

    return 0;
}