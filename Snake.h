#include <vector>
#include "SnakeBody.h"
#ifndef __SNAKE__
#define __SNAKE__
using namespace std;

// 몸통 추가, 삭제 구현해야됨 
class Snake{
    public:
        Snake(int size=3, int startY=10, int startX=10):length(size){
            gainPlus = 0;
            gainMinus = 0;
            for(int i=0;i<size;i++){
                SnakeBody s;
                if(i==0){
                    s = SnakeBody(startY, startX, HEAD);
                } else{
                    s = SnakeBody(startY, ++startX, TAIL);
                }
                body.push_back(s);
            }
        }

        SnakeBody& operator [](int idx){
            return body[idx];
        }

        int getLength(){
            return length;
        }

        void plusBody(){
            int y = body[getLength()-1].getYposition();
            int x = body[getLength()-1].getXposition();
            SnakeBody b(y,x,TAIL);
            body.push_back(b);
            gainPlus++;
            length++;
        }
        void minusBody(){
            gainMinus++;
            length--;
            body.pop_back();
        }

        int getGainPlus() {return gainPlus;}
        int getGainMinus() {return gainMinus;}

    private:
        int gainPlus;
        int gainMinus;
        int length;
        vector <SnakeBody> body;
};

#endif