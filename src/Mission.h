#ifndef __MISSION__
#define __MISSION__
#include <ncurses.h>
class Score;

/*  
    각 헤더파일에 명시한 함수의 저자는 구현부인 cpp파일에다 적음
    기여도 %가 절대적으로 정확한 지표는 아닌 것을 명시함

    @author 김동원(20181580) 20%
    @author 김호준(20181604) 60%
    @author 김호준(20181605) 20%
*/
class Mission
{
public:
    Mission() {}
    Mission(Score *s);

    int check();
    int stage;
private:

    Score *score;
    int checkFlag;
};

class MissionBoard
{
public:
    MissionBoard() {}
    MissionBoard(int height, int width, Mission *m);
    
    void init();
    void addBoarder();
    void clear();
    bool addAtState();
    void refresh();

private:
    WINDOW *mission_board;
    Mission *mission;
};

#endif