#include "Board.h"

Board::Board(int height, int width)
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    board_win = newwin(height, width - 1, (yMax / 2) - (height / 2), (xMax / 3) - (width / 3)); //-1 안하면 안됨
    init();
}

void Board::init()
{
    clear();
    refresh();
}

void Board::addBoarder()
{
    box(board_win, 0, 0);
}

void Board::addAt(int y, int x, chtype ch)
{
    mvwaddch(board_win, y, x, ch);
}

int Board::getInput()
{
    keypad(board_win, true);
    halfdelay(5);
    return wgetch(board_win);
}

void Board::clear()
{
    wclear(board_win);
    addBoarder();
}

void Board::refresh()
{
    wrefresh(board_win);
}

void Board::erase()
{
    erase();
}
