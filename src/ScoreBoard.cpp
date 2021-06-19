#include "ScoreBoard.h"
#include "Snake.h"
#include <string>

// @author 김호준(20181604)
Score::Score(Snake *s) : growthGain(0), poisonGain(0), gateUse(0), second(0), totalScore(0), 
                         missionComplete(0)
{
    snake = s;
    curLength = snake->getLength();
    maxLength = snake->getLength();
}

// @author 김호준(20181604)
void Score::Update()
{
    curLength = snake->getLength();
    if (maxLength < curLength)
        maxLength = snake->getLength();
    growthGain = snake->getGainPlus();
    poisonGain = snake->getGainMinus();
    totalScore = second * 12 + growthGain * 100 - poisonGain * 100 + gateUse * 300 + missionComplete * 300;
}

// @author 김호준(20181604)
ScoreBoard::ScoreBoard(int height, int width, Score *s)
{
    int xMax, yMax;
    score = s;
    getmaxyx(stdscr, yMax, xMax);
    // int boardYpoint = (yMax/2)-(height/2);
    int boardXpoint = (xMax / 3) - (width / 3) + width;
    score_board = newwin(10, width / 2, (yMax / 2) - (height / 2) + 8, boardXpoint);
    init();
}

// @author 김호준(20181604)
void ScoreBoard::init()
{
    clear();
    refresh();
    mvwaddstr(score_board, 1, 1, "    Score Board");
    mvwaddstr(score_board, 2, 1, "-------------------");
    mvwaddstr(score_board, 3, 1, "B: ");
    mvwaddstr(score_board, 3, 7, "/ ");
    mvwaddstr(score_board, 4, 1, "+: ");
    mvwaddstr(score_board, 5, 1, "-: ");
    mvwaddstr(score_board, 6, 1, "G: ");
    mvwaddstr(score_board, 7, 1, "T: ");
    mvwaddstr(score_board, 8, 1, "TOTAL: ");
}

// @author 김호준(20181605)
void ScoreBoard::addBoarder()
{
    box(score_board, 0, 0);
}

// @author 김호준(20181605)
void ScoreBoard::clear()
{
    wclear(score_board);
    addBoarder();
}

// @author 김호준(20181605)
void ScoreBoard::addAtState()
{
    // string score_string = stoi(score);
    score->Update();
    string curLengthStr = to_string(score->curLength);
    if(curLengthStr.size() == 1)
        curLengthStr += " ";
    mvwaddstr(score_board, 3, 4, curLengthStr.c_str());
    mvwaddstr(score_board, 3, 9, to_string(score->maxLength).c_str());
    mvwaddstr(score_board, 4, 4, to_string(score->growthGain).c_str());
    mvwaddstr(score_board, 5, 4, to_string(score->poisonGain).c_str());
    mvwaddstr(score_board, 6, 4, to_string(score->gateUse).c_str());
    mvwaddstr(score_board, 7, 4, (to_string(score->second) + "s.").c_str());
    mvwaddstr(score_board, 8, 8, to_string(score->totalScore).c_str());
}

// @author 김호준(20181605)
void ScoreBoard::refresh()
{
    wrefresh(score_board);
}
