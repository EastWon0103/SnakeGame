#include "Board.h"


// @author 김동원(20181580)
Board::Board(int height, int width)
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    board_win = newwin(height, width - 1, (yMax / 2) - (height / 2), (xMax / 3) - (width / 3)); //-1 안하면 안됨
    init();
}

// @author 김호준(20181604)
void Board::init()
{
    clear();
    refresh();
}

// @author 김호준(20181604)
void Board::addBoarder()
{
    box(board_win, 0, 0);
}

// @author 김호준(20181604)
void Board::addAt(int y, int x, chtype ch)
{
    mvwaddch(board_win, y, x, ch);
}

// @author 김호준(20181604)
int Board::getInput()
{
    keypad(board_win, true);
    return wgetch(board_win);
}

// @author 김호준(20181604)
void Board::clear()
{
    wclear(board_win);
    addBoarder();
}

// @author 김호준(20181605)
void Board::refresh()
{
    wrefresh(board_win);
}

// @author 김호준(20181605)
void Board::erase()
{
    erase();
}
