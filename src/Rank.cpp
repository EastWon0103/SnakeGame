#include "Rank.h"
#include "ScoreBoard.h"
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

// @author 김호준(20181604)
Rank::Rank() : RANK_FILE("RANK.txt")
{
}

// @author 김호준(20181604)
void Rank::init() 
{
    ifstream fin;
    fin.open(RANK_FILE, ifstream::in);
    while(!fin.eof())
    {
        if(rankArray.size() == 100) break;

        int tmp;
        fin >> tmp;
        rankArray.push_back(tmp);
    }
    rankArray.pop_back();
    if(rankArray.empty())
    {
        rankArray.push_back(0);
    }
    bestScore = rankArray[0];
    fin.close();
}

// @author 김호준(20181604)
void Rank::update(Score* score) 
{
    ofstream fout;
    fout.open(RANK_FILE, std::ofstream::out | std::ofstream::trunc);
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

// @author 김호준(20181605)
RankBoard::RankBoard(int height, int width, Rank* r) : rank(r)
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    // int boardYpoint = (yMax/2)-(height/2);
    int boardXpoint = (xMax / 3) - (width / 3) + width;
    rank_board = newwin(3, width / 2, (yMax / 2) - (height / 2) + 18, boardXpoint);
    init();
}

// @author 김호준(20181605)
void RankBoard::init()
{
    clear();
    refresh();
    mvwaddstr(rank_board, 1, 1, "Best Score: ");
}

// @author 김호준(20181605)
void RankBoard::addBoarder()
{
    box(rank_board, 0, 0);
}

// @author 김호준(20181605)
void RankBoard::clear()
{
    wclear(rank_board);
    addBoarder();
}

// @author 김호준(20181604)
void RankBoard::addAtState(const Score* score)
{
    if(score->totalScore < rank->bestScore)
        mvwaddstr(rank_board, 1, 13, to_string(rank->bestScore).c_str());
    else
        mvwaddstr(rank_board, 1, 13, to_string(score->totalScore).c_str());
}

// @author 김호준(20181605)
void RankBoard::refresh()
{
    wrefresh(rank_board);
}
