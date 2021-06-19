#include <ncurses.h>
#include "Board.h"
#include "SnakeGame.h"
#include <iostream>

#define BOARD_DIM 21
#define BOARD_ROW BOARD_DIM
#define BOARD_COL BOARD_ROW * 2
/*
    같이 고민하고 제작한 소스코드의 경우는 %로 임의로 표기

    @author 김동원(20181580) 40%
    @author 김호준(20181604) 20%
    @author 김호준(20181605) 40%
*/
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


    // 여기 
    time_t st = time(NULL);
    while(!game.isOver()){
        time_t checkPoint = time(NULL);
        time_t timeScore = time(NULL);
        time_t wallEnd = time(NULL);
        time_t timeItemInitEnd = time(NULL);
        time_t eatTimeEnd = time(NULL);

        //여기
        // time_t ed = time(NULL);
        // if((double)(ed-st) >= 3){
        //     if(game.canMakeInner()){
        //         game.changeMap();
        //     }
        //     if(game.get()<5){
        //         game.plus();
        //     }
            
        //     st = time(NULL);
        // }

        game.missionUpdate();
        if ((game.isMissionComplete == true && game.getStage() < 4)&&(game.canMakeInner()))
        {   
            game.changeMap();
            game.isMissionComplete = false;
            // if(game.canMakeInner()){
            //     game.changeMap();
            // }
            //스테이지 변경 로직
        }

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