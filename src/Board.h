#ifndef __BOARD__
#define __BOARD__
#include <ncurses.h>

class Board
{
public:
    Board() {}
    Board(int height, int width);

    void init();
    void addBoarder();

    void addAt(int y, int x, chtype ch);

    int getInput();
    void clear();

    void refresh();
    void erase();

private:
    WINDOW *board_win;
};

#endif