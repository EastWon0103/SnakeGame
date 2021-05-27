#include <vector>
#include "SnakeBody.h"
#ifndef __SNAKE__
#define __SNAKE__
using namespace std;

// 몸통 추가, 삭제 구현해야됨 
class Snake{
    public:
        Snake(int size=3, int startY=10, int startX=10):length(size){
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

    private:
        int length;
        vector <SnakeBody> body;
};

#endif