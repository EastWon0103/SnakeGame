#include "Rank.h"
#include "ScoreBoard.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

Rank::Rank() : RANK_FILE("RANK.txt")
{
}

void Rank::init() 
{
    ifstream fin;
    fin.open("RANK.txt", ifstream::in);
    while(!fin.eof())
    {
        if(rankArray.size() == 100) break;

        int tmp;
        fin >> tmp;
        rankArray.push_back(tmp);
    }
    if(rankArray.empty())
    {
        rankArray.push_back(0);
    }
    bestScore = rankArray[0];
    fin.close();
}

void Rank::update(Score* score) 
{
    ofstream fout;
    fout.open("RANK.txt", std::ofstream::out | std::ofstream::trunc);
    rankArray.push_back(score->totalScore);
    sort(rankArray.begin(), rankArray.end(), greater<>());
    if (rankArray.size() > 100)
        rankArray.pop_back();

    for(int i = 0; i < rankArray.size(); i++)
    {
        fout << rankArray[i] << "\n";
    }

    fout.close();

}

RankBoard::RankBoard(int height, int width, Rank* r) : rank(r)
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    // int boardYpoint = (yMax/2)-(height/2);
    int boardXpoint = (xMax / 3) - (width / 3) + width;
    rank_board = newwin(3, width / 2, (yMax / 2) - (height / 2) + 18, boardXpoint);
    init();
}

void RankBoard::init()
{
    clear();
    refresh();
    mvwaddstr(rank_board, 1, 1, "Best Score: ");
}

void RankBoard::addBoarder()
{
    box(rank_board, 0, 0);
}

void RankBoard::clear()
{
    wclear(rank_board);
    addBoarder();
}

void RankBoard::addAtState(const Score* score)
{
    if(score->totalScore < rank->bestScore)
        mvwaddstr(rank_board, 1, 13, to_string(rank->bestScore).c_str());
    else
        mvwaddstr(rank_board, 1, 13, to_string(score->totalScore).c_str());
}

void RankBoard::refresh()
{
    wrefresh(rank_board);
}
