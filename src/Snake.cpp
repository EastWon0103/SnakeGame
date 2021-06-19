#include "Snake.h"

/*  
    @author 김동원(20181580) 50%
    @author 김호준(20181604) 10%
    @author 김호준(20181605) 40%
*/
using namespace std;

// @author 김동원(20181580)
SnakeBody::SnakeBody(int y, int x, PART p)
{
    yPosition = y;
    xPosition = x;
    part = p;
}

// @author 김호준(20181604)
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

// @author 김호준(20181605)
void Snake::plusBody()
{
    int y = body[getLength() - 1].getYposition();
    int x = body[getLength() - 1].getXposition();
    SnakeBody b(y, x, TAIL);
    body.push_back(b);
    gainPlus++;
    length++;
}

// @author 김호준(20181605)
void Snake::minusBody()
{
    gainMinus++;
    length--;
    body.pop_back();
}

// @author 김동원(20181580)
SnakeBody &Snake::operator[](int idx)
{
    return body[idx];
}
