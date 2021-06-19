#ifndef __BOARD__
#define __BOARD__
#include <ncurses.h>

/*  
    각 헤데파일에 명시한 함수의 저자는 구현부인 cpp파일에다 적음
    기여도 %가 절대적으로 정확한 지표는 아닌 것을 명시함

    @author 김동원(20181580) 30%
    @author 김호준(20181604) 40%
    @author 김호준(20181605) 30%
*/

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