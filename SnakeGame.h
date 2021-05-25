#include <ncurses.h>
#include "Board.h"
#ifndef __SNAKE_GAME__
#define __SNAKE_GAME__

class SnakeGame{
    public:
        SnakeGame(int height, int width){
            board = Board(height, width);
            board.init();
            game_over = false;
        }

        void processInput(){
            int input = board.getInput();
            if (input == KEY_DOWN){
                board.addAt(0,0, ACS_DIAMOND);
                board.addAt(0,2, ACS_DIAMOND);
                board.addAt(0,4, ACS_DIAMOND);
                board.addAt(0,6, ACS_DIAMOND);
                board.addAt(0,8, ACS_DIAMOND);
            } else if (input == KEY_UP){
                board.addAt(10,10,'3');
            } else {
                board.addAt(19,19,'5');
            }
            
            // process input
        }

        void updateState(){
            // update state
        }

        void redraw(){
            board.refresh();
        }
        bool isOver(){
            return game_over;
        }
    private:
        Board board;
        bool game_over;

};


#endif