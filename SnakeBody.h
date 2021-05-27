#ifndef __SNAKE_BODY__
#define __SNAKE_BODY__

enum PART {HEAD, TAIL};
class SnakeBody{
    public:
        SnakeBody(int y=10, int x=10, PART p=HEAD){
            yPosition = y;
            xPosition = x;
            part = p;
        }
        int getXposition(){
            return xPosition;
        }
        int getYposition(){
            return yPosition;
        }
        void setXposition(int p){
            xPosition = p;
        }
        void setYposition(int p){
            yPosition = p;
        }
        PART getPart(){
            return part;
        }

    protected:
        int xPosition;
        int yPosition;
        PART part;
};

#endif