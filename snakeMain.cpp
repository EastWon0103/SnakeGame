#include <ncurses.h>
#include "Board.h"
#include "SnakeGame.h"
#include <iostream>

#define BOARD_DIM 21
#define BOARD_ROW BOARD_DIM
#define BOARD_COL BOARD_ROW * 2


// board.h의 width에 -1 하나 빼주었다.
// setinnergamewall 추가
// board 그려주는거 잠시 수정
// gameboard의 가장자리 1->2로 수정
// gate추가 
// gate 테스트중임
int main(){
    initscr();
    refresh();
    noecho();
    cbreak();
    curs_set(0);
    time_t start = time(NULL);
    time_t scoreStart = time(NULL);
    SnakeGame game(BOARD_ROW, BOARD_COL);
    while(!game.isOver()){
        time_t checkPoint = time(NULL);
        time_t timeScore = time(NULL);
        if((double)(timeScore-scoreStart) >= 1){
            scoreStart = time(NULL);
            game.setTimeScore();

        }
        game.processInput();
        if((double)(checkPoint-start) >= 5){
            game.makeGItem();
            game.makePItem();
            start = time(NULL);
        }
        game.updateState();
        game.redraw();
    }
    game.redraw();
    game.gameOver();
    game.updateState();
    game.redraw();
    int n;
    std::cin >> n;
    getch();
    endwin();

    return 0;
}