#include <ncurses.h>
#include "SnakeGame.h"
#include "resultWindow.h"
// #include <time.h>
#include <ctime>

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
    time_t start = time(NULL);
    SnakeGame game(BOARD_ROW, BOARD_COL);
    while(!game.isOver()){
        time_t checkPoint = time(NULL);
        game.processInput();
        if((double)(checkPoint-start) >= 5){
            game.makeGItem();
            game.makePItem();
            start = time(NULL);
        }
        game.updateState();
        game.redraw();
    }
    ResultWindow result;
    result.init();
    while(true){
        int c = result.getInput();
        if (c!=-1){
            break;
        }
    }
    
    

    endwin();

    return 0;
}