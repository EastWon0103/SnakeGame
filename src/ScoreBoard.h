#ifndef __SCORE_BOARD__
#define __SCORE_BOARD__
#include <ncurses.h>

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