#include "Mission.h"
#include "ScoreBoard.h"
#include <string>

Mission::Mission(Score *s)
{
    score = s;
    checkFlag = 0b0000;
}

int Mission::check()
{
    if ((score->curLength) >= 10)
    {
        checkFlag |= 0b1000;
    }
    if ((score->growthGain) >= 5)
    {
        checkFlag |= 0b0100;
    }
    if ((score->poisonGain) >= 2)
    {
        checkFlag |= 0b0010;
    }
    if ((score->gateUse) >= 1)
    {
        checkFlag |= 0b0001;
    }
    return checkFlag;
}

MissionBoard::MissionBoard(int height, int width, Mission *m)
{
    int xMax, yMax;
    mission = m;
    getmaxyx(stdscr, yMax, xMax);
    // int boardYpoint = (yMax/2)-(height/2);
    int boardXpoint = (xMax / 3) - (width / 3) + width;
    mission_board = newwin(8, width / 2, (yMax / 2) - (height / 2), boardXpoint);
    init();
}

void MissionBoard::init()
{
    clear();
    refresh();
    mvwaddstr(mission_board, 1, 1, "      Mission");
    mvwaddstr(mission_board, 2, 1, "-------------------");
    mvwaddstr(mission_board, 3, 1, "B: ");
    mvwaddstr(mission_board, 3, 4, "10");
    mvwaddstr(mission_board, 3, 7, "(");
    mvwaddstr(mission_board, 3, 9, ")");
    mvwaddstr(mission_board, 4, 1, "+: ");
    mvwaddstr(mission_board, 4, 4, "5");
    mvwaddstr(mission_board, 4, 7, "(");
    mvwaddstr(mission_board, 4, 9, ")");
    mvwaddstr(mission_board, 5, 1, "-: ");
    mvwaddstr(mission_board, 5, 4, "2");
    mvwaddstr(mission_board, 5, 7, "(");
    mvwaddstr(mission_board, 5, 9, ")");
    mvwaddstr(mission_board, 6, 1, "G: ");
    mvwaddstr(mission_board, 6, 4, "1");
    mvwaddstr(mission_board, 6, 7, "(");
    mvwaddstr(mission_board, 6, 9, ")");
}

void MissionBoard::addBoarder()
{
    box(mission_board, 0, 0);
}

void MissionBoard::clear()
{
    wclear(mission_board);
    addBoarder();
}

void MissionBoard::addAtState()
{
    int flag = mission->check();
    int check = 0b1000;
    for (int i = 0; i < 4; i++)
    {
        if ((flag & check) != 0)
        {
            mvwaddstr(mission_board, 3 + i, 8, "v");
        }
        check >>= 1;
    }
}

void MissionBoard::refresh()
{
    wrefresh(mission_board);
}
