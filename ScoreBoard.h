#include <ncurses.h>
#include <string>
#ifndef __SCORE_BOARD__
#define __SCORE_BOARD__

class ScoreBoard{
    public: 
        ScoreBoard(){

        }
        ScoreBoard(int height, int width){
            int xMax, yMax;
            getmaxyx(stdscr, yMax, xMax);
            // int boardYpoint = (yMax/2)-(height/2);
            int boardXpoint = (xMax/2)-(width/2);
            score_board = newwin(3, width, (yMax/2)+(height/2)+1, boardXpoint);
            init();
        }

        void init(){
            clear();
            refresh();
            mvwaddstr(score_board, 1,1, "score: ");
        }

        void addBoarder(){
            box(score_board, 0, 0);
        }

        void clear(){
            wclear(score_board);
            addBoarder();
        }

        void addAtState(int score){
            std::string tmp= std::to_string(score);
            const char *chScore = tmp.c_str();
            // string score_string = stoi(score);
            mvwaddstr(score_board, 1, 7, chScore);
        }

        void refresh(){
            wrefresh(score_board);
        }

    private:
        WINDOW *score_board;
};

#endif
