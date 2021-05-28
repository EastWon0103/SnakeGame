#include <ncurses.h>
#ifndef __RESULT__
#define __RESULT__

class ResultWindow{
    public:
        ResultWindow(){ 
            int height = 6;
            int width = 12;
            int xMax, yMax;
            getmaxyx(stdscr, yMax, xMax);
            result_win = newwin(height, width, (yMax/2)-(height/2), (xMax/2)-(width/2));
            init();
        }

        void init(){
            clear();
            refresh();
        }

        void addBoarder(){
            box(result_win, 0, 0);
        }

        void clear(){
            wclear(result_win);
            addBoarder();
        }

        void refresh(){
            wrefresh(result_win);
        }

        int getInput(){
            keypad(result_win, true);
            return wgetch(result_win);
        }
        
    private:
        WINDOW *result_win;
};


#endif