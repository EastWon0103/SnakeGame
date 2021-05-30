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
// 게이트 랜덤하게 생성++ 지나고 있으면 생성되지 않음,
int main(){
    initscr();
    refresh();
    noecho();
    cbreak();
    curs_set(0);
    time_t start = time(NULL);
    time_t scoreStart = time(NULL);
    time_t wallStart = time(NULL);
    time_t timeItemInitStart = time(NULL);
    time_t eatTimeStart = time(NULL);
    SnakeGame game(BOARD_ROW, BOARD_COL);
    while(!game.isOver()){
        time_t checkPoint = time(NULL);
        time_t timeScore = time(NULL);
        time_t wallEnd = time(NULL);
        time_t timeItemInitEnd = time(NULL);
        time_t eatTimeEnd = time(NULL);

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

        if((double)(wallEnd-wallStart) >= 4){
            if(game.isGate()){
                wallStart = time(NULL);
            }else{
                game.clearGate();
                game.makeGate();
                wallStart = time(NULL);
            }
        }

        if((double)(timeItemInitEnd-timeItemInitStart)>=5){
            timeItemInitStart = time(NULL);
            game.clearTimeItem();
            game.makeTimeItem();
        }

        if(game.getEatStartStatus()){
            eatTimeStart = time(NULL);
            game.setEatStartStatus(false);
        }

        if((game.getEatTimeItem())&&((double)(eatTimeEnd-eatTimeStart)>=7)){
            game.setOriginDelayTime();
            game.setHalfDelay(game.getDelayTime());
            game.setEatTimeItem(false);
            eatTimeStart = time(NULL);
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