#include <ncurses.h>
#include <string>
#include "Snake.h"
#ifndef __SCORE_BOARD__
#define __SCORE_BOARD__
using namespace std;
class Snake;

class Score{
public:
    Score(Snake* s): growthGain(0), poisonGain(0), gateUse(0), second(0) {
        snake = s;
        curLength = snake->getLength();
        maxLength = snake->getLength();
    }

    void Update()
    {
        curLength = snake->getLength();
        if (maxLength < curLength)
            maxLength = snake->getLength();
        growthGain = snake->getGainPlus();
        poisonGain = snake->getGainMinus();
    }
    int curLength;
    int maxLength;
    int growthGain;
    int poisonGain;
    int gateUse;
    int second;
    Snake* snake;
};

class ScoreBoard{
    public: 
        ScoreBoard(){

        }
        ScoreBoard(int height, int width, Score* s){
            int xMax, yMax;
            score = s;
            getmaxyx(stdscr, yMax, xMax);
            // int boardYpoint = (yMax/2)-(height/2);
            int boardXpoint = (xMax/3)-(width/3) + width;
            score_board = newwin(10, width / 2, (yMax/2)-(height/2) + 8, boardXpoint);
            init();
        }
//
        void init(){
            clear();
            refresh();
            mvwaddstr(score_board, 1,1, "    Score Board");
            mvwaddstr(score_board, 2,1, "-------------------");
            mvwaddstr(score_board, 3,1, "B: ");
            mvwaddstr(score_board, 3,7, "/ ");
            mvwaddstr(score_board, 4,1, "+: ");
            mvwaddstr(score_board, 5,1, "-: ");
            mvwaddstr(score_board, 6,1, "G: ");
            mvwaddstr(score_board, 7,1, "T: ");
            mvwaddstr(score_board, 8,1, "TOTAL: ");
        }

        void addBoarder(){  
            box(score_board, 0, 0);
        }

        void clear(){
            wclear(score_board);
            addBoarder();
        }

        void addAtState(){
            // string score_string = stoi(score);
            score->Update();
            mvwaddstr(score_board, 3, 4, to_string(score->curLength).c_str());
            mvwaddstr(score_board, 3, 9, to_string(score->maxLength).c_str());
            mvwaddstr(score_board, 4, 4, to_string(score->growthGain).c_str());
            mvwaddstr(score_board, 5, 4, to_string(score->poisonGain).c_str());
            mvwaddstr(score_board, 6, 4, to_string(score->gateUse).c_str());
            mvwaddstr(score_board, 7, 4, to_string(score->second).c_str());
        }

        void refresh(){
            wrefresh(score_board);
        }

    private:
        WINDOW *score_board;
        Score* score;

};

#endif
