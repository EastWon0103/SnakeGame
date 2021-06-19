#ifndef __SNAKE_BODY__
#define __SNAKE_BODY__
#include <vector>


/*  
    각 헤데파일에 명시한 함수의 저자는 구현부인 cpp파일에다 적음
    기여도 %가 절대적으로 정확한 지표는 아닌 것을 명시함

    @author 김동원(20181580) 50%
    @author 김호준(20181604) 10%
    @author 김호준(20181605) 40%
*/

using namespace std;
enum PART
{
    HEAD,
    TAIL
};

// @author 김동원(20181580)
class SnakeBody
{
public:
    SnakeBody(int y = 10, int x = 10, PART p = HEAD);
    int getXposition()
    {
        return xPosition;
    }
    int getYposition()
    {
        return yPosition;
    }
    void setXposition(int p)
    {
        xPosition = p;
    }
    void setYposition(int p)
    {
        yPosition = p;
    }
    PART getPart()
    {
        return part;
    }

protected:
    int xPosition;
    int yPosition;
    PART part;
};


class Snake
{
public:
    Snake(int size = 3, int startY = 10, int startX = 10);

    SnakeBody &operator[](int idx);

    int getLength()
    {
        return length;
    }

    void plusBody();
    void minusBody();
    int getGainPlus() { return gainPlus; }
    int getGainMinus() { return gainMinus; }

private:
    int gainPlus;
    int gainMinus;
    int length;
    vector<SnakeBody> body;
};

#endif