#include <ncurses.h>
#ifndef __BOARD__
#define __BOARD__

class Board{
    public:
        Board(){}
        Board(int height, int width){
            int xMax, yMax;
            getmaxyx(stdscr, yMax, xMax);
            board_win = newwin(height, width-1, (yMax/2)-(height/2), (xMax/3)-(width/3)); //-1 안하면 안됨 
            init();
        }

        void init(){
            clear();
            refresh();
        }

        void addBoarder(){
            box(board_win, 0, 0);
        }

        void addAt(int y, int x, chtype ch){
            mvwaddch(board_win,y, x, ch);
        }

        int getInput(){
            keypad(board_win, true);
            halfdelay(5);
            return wgetch(board_win);
        }
        void clear(){
            wclear(board_win);
            addBoarder();
        }

        void refresh(){
            wrefresh(board_win);
        }

        void erase(){
            erase();
        }
    private:
        WINDOW *board_win;
};


#endif