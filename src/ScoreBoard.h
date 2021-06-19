#ifndef __SCORE_BOARD__
#define __SCORE_BOARD__
#include <ncurses.h>

/*  
    각 헤더파일에 명시한 함수의 저자는 구현부인 cpp파일에다 적음
    기여도 %가 절대적으로 정확한 지표는 아닌 것을 명시함

    @author 김호준(20181604) 60%
    @author 김호준(20181605) 40%
*/

class Snake;


class Score
{
public:
    Score(Snake *s);

    void Update();

public:
    int curLength;
    int maxLength;
    int growthGain;
    int poisonGain;
    int gateUse;
    int second;
    int missionComplete;
    int totalScore;
    Snake *snake;
};

class ScoreBoard
{
public:
    ScoreBoard() {}
    ScoreBoard(int height, int width, Score *s);

    void init();
    void addBoarder();
    void clear();
    void addAtState();
    void refresh();

private:
    WINDOW *score_board;
    Score *score;
};

#endif