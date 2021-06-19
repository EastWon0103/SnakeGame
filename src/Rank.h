#ifndef __RANK__
#define __RANK__
#include <ncurses.h>
#include <string>
#include <vector>
class Score;
/*  
    각 헤더파일에 명시한 함수의 저자는 구현부인 cpp파일에다 적음
    기여도 %가 절대적으로 정확한 지표는 아닌 것을 명시함

    @author 김호준(20181604) 70%
    @author 김호준(20181605) 30%
*/
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