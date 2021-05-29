#ifndef __SNAKE_BODY__
#define __SNAKE_BODY__
#include <vector>

using namespace std;
enum PART
{
    HEAD,
    TAIL
};

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

// 몸통 추가, 삭제 구현해야됨
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