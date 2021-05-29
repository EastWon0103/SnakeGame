#include <ncurses.h>
#include <string>
#ifndef __RANK__
#define __RANK__

class RankBoard{
    public: 
        RankBoard(){

        }
        RankBoard(int height, int width){
            int xMax, yMax;
            getmaxyx(stdscr, yMax, xMax);
            // int boardYpoint = (yMax/2)-(height/2);
            int boardXpoint = (xMax/3)-(width/3) + width;
            rank_board =  newwin(3, width / 2, (yMax/2)-(height/2) + 18, boardXpoint);
            init();
        }
//
        void init(){
            clear();
            refresh();
            mvwaddstr(rank_board, 1,1, "Best Score: ");
        }

        void addBoarder(){  
            box(rank_board, 0, 0);
        }

        void clear(){
            wclear(rank_board);
            addBoarder();
        }

        void addAtState(int score){
            std::string tmp= std::to_string(score);
            const char *chScore = tmp.c_str();
            // string score_string = stoi(score);
            mvwaddstr(rank_board, 2, 4, chScore);
        }

        void refresh(){
            wrefresh(rank_board);
        }

    private:
        WINDOW *rank_board;
};

#endif
