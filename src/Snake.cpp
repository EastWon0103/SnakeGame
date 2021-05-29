#include "Snake.h"

using namespace std;
SnakeBody::SnakeBody(int y, int x, PART p)
{
    yPosition = y;
    xPosition = x;
    part = p;
}

Snake::Snake(int size, int startY, int startX): length(size)
{
    gainPlus = 0;
    gainMinus = 0;
    for (int i = 0; i < size; i++)
    {
        SnakeBody s;
        if (i == 0)
        {
            s = SnakeBody(startY, startX, HEAD);
        }
        else
        {
            s = SnakeBody(startY, ++startX, TAIL);
        }
        body.push_back(s);
    }
}

void Snake::plusBody()
{
    int y = body[getLength() - 1].getYposition();
    int x = body[getLength() - 1].getXposition();
    SnakeBody b(y, x, TAIL);
    body.push_back(b);
    gainPlus++;
    length++;
}

void Snake::minusBody()
{
    gainMinus++;
    length--;
    body.pop_back();
}

SnakeBody &Snake::operator[](int idx)
{
    return body[idx];
}
