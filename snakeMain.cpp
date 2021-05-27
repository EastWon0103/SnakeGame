#include <ncurses.h>
#include "Board.h"
#include "SnakeGame.h"

#define BOARD_DIM 21
#define BOARD_ROW BOARD_DIM
#define BOARD_COL BOARD_ROW * 2
//getch 잡는거 확인하셈
int main(){
    initscr();
    refresh();
    noecho();
    cbreak();
    curs_set(0);
    SnakeGame game(BOARD_ROW, BOARD_COL);
    while(!game.isOver()){
        game.processInput();
        game.updateState();
        game.redraw();
    }
    game.redraw();
    getch();
    endwin();

    return 0;
}