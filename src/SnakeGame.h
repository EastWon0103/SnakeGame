#ifndef __SNAKE_GAME__
#define __SNAKE_GAME__
#include <vector>
#include "Board.h"
#include "ScoreBoard.h"
#include "Mission.h"
#include "Rank.h"
using namespace std;
/*  
    각 헤데파일에 명시한 함수의 저자는 구현부인 cpp파일에다 적음
    기여도 %가 절대적으로 정확한 지표는 아닌 것을 명시함

    @author 김동원(20181580) 40%
    @author 김호준(20181604) 20%
    @author 김호준(20181605) 40%
*/
enum DIRECTION {
    UP, DOWN, RIGHT, LEFT
};

enum GATETYPE {OUTER, INNER};

class Snake;

class SnakeGame{
public:
    SnakeGame(int height, int width);
    ~SnakeGame();

    void processInput();
    void updateState();
    void redraw();
    bool checkWB(int y, int x);
    void checkLength();
    bool checkGate(int y, int x);
    int gateHeadY(int referY, int referX);
    int gateHeadX(int referY, int referX);
    void goDirection();
    void readBoard();
    void makeGItem();
    void makePItem();
    void snakeOnBoard(Snake *s);
    bool isOver();
    void gameOver();
    void setDirection(DIRECTION d);
    void setTimeScore();
    int getTimeScore();
    // void setInnerWall();
    bool makeGateCheck(int num);
    void makeGate();
    void clearGate();
    bool isGate();


    bool getEatTimeItem();
    void setEatTimeItem(bool status);
    void makeTimeItem();
    void clearTimeItem();
    

    int getDelayTime();
    void minusDelayTime();
    void setOriginDelayTime();
    void setHalfDelay(int time);

    bool getEatStartStatus();
    void setEatStartStatus(bool status);

    void updateRank();


private:
    Rank *rank;
    Score *score;
    Mission *mission;
    Board board;
    ScoreBoard score_board;
    MissionBoard mission_board;
    RankBoard rank_board;
    bool game_over;
    DIRECTION direction;
    Snake *snake;
    int gItemNum;
    int pItemNum;

    vector<int> wallYPosition;
    vector<int> wallXPosition;
    int gate1Y = -1;
    int gate1X = -1;
    int gate2Y = -1;
    int gate2X = -1;
    int offsetX[4] = {0,1,0,-1};
    int offsetY[4] = {-1,0,1,0};
    
    bool eatTimeItem;
    
    int tItemY;
    int tItemX;
    int delayTime;

    bool eatStartStatus;

    int gameStage;
    char gameBoard[21][21] = {
                {'2', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '2'},
                {'1', '0', '0', 'g', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
                {'2', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '2'}
            };

};


#endif