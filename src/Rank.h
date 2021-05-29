#ifndef __RANK__
#define __RANK__
#include <ncurses.h>

class RankBoard
{
public:
    RankBoard()
    {
    }
    RankBoard(int height, int width);
    void init();
    void addBoarder();
    void clear();
    void addAtState(int score);
    void refresh();

private:
    WINDOW *rank_board;
};

#endif