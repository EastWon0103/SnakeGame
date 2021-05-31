#ifndef __RANK__
#define __RANK__
#include <ncurses.h>
#include <string>
#include <vector>
class Score;

class Rank
{
public:
    Rank();
    void init();
    void update(Score* score);
    
public:
    int bestScore;

private:
    const std::string RANK_FILE;
    std::vector<int> rankArray;
};

class RankBoard
{
public:
    RankBoard() {}
    RankBoard(int height, int width, Rank* r);
    void init();
    void addBoarder();
    void clear();
    void addAtState(const Score* score);
    void refresh();

private:
    WINDOW *rank_board;
    Rank *rank;
};

#endif