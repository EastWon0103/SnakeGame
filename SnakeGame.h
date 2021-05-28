#include <ncurses.h>
#include "Board.h"
#include "ScoreBoard.h"
#include "Snake.h"
#include <time.h>
#include <random>
#include <unistd.h>
#include <random>
#ifndef __SNAKE_GAME__
#define __SNAKE_GAME__

enum DIRECTION{UP, DOWN, RIGHT, LEFT};


//제대로 된 게임오버 구현해야함
class SnakeGame{
    public:
        SnakeGame(int height, int width){
            board = Board(height, width);
            score = 0;
            score_board = ScoreBoard(height, width);
            score_board.init();
            score_board.addAtState(score);
            score_board.refresh();
            direction = LEFT;
            snake = Snake(8, height/2, width/4-3);
            snakeOnBoard(snake);
            board.init();
            readBoard();
            game_over = false;
            gItemNum = 0;
            pItemNum = 0;
        }

        void delay(int t){
            usleep(t);
        }

        void processInput(){
            int input = board.getInput();
            switch(input){
                case KEY_LEFT:
                    if(direction!=LEFT){
                        setDirection(LEFT);
                    }
                    break;
                case KEY_RIGHT:
                    if(direction!=RIGHT){
                        setDirection(RIGHT);
                    }
                    break;
                case KEY_DOWN:
                    if(direction!=DOWN){
                        setDirection(DOWN);
                    }
                    break;
                case KEY_UP:
                    if(direction!=UP){
                        setDirection(UP);
                    }
                    break;
                default:
                    break;
            }
            goDirection();
            board.clear();
            readBoard();
        }

        void updateState(){
            score_board.addAtState(score);
            score_board.refresh();
        }

        void redraw(){
            board.refresh();
        }
        bool checkWB(int y, int x){
            char referPoint = gameBoard[y][x];
            if ((referPoint=='1')||(referPoint=='4')){
                game_over = true;
                return true;
            } else if(referPoint=='G'){
                gItemNum--;
                snake.plusBody();
                return false;
            } else if(referPoint=='P'){
                pItemNum--;
                int minusY = snake[snake.getLength()-1].getYposition();
                int minusX = snake[snake.getLength()-1].getXposition();
                snake.minusBody();
                gameBoard[minusY][minusX] = '0';
                return false;
            } else {
                return false;
            }
            
        }
        void goDirection(){
            int preY = snake[0].getYposition();
            int preX = snake[0].getXposition();
            int moveY,moveX;
            switch(direction){
                case LEFT:
                    moveY = preY;
                    moveX = preX-1;
                    break;
                case RIGHT:
                    moveY = preY;
                    moveX = preX+1;
                    break;
                case UP:
                    moveY = preY-1;
                    moveX = preX;
                    break;
                case DOWN:
                    moveY = preY+1;
                    moveX = preX;
                    break;
                default:
                    break;
            }
            if (checkWB(moveY, moveX)){
                return;
            }
            snake[0].setYposition(moveY);
            snake[0].setXposition(moveX);
            for(int i=1;i<snake.getLength();i++){
                int tmpY = snake[i].getYposition();
                int tmpX = snake[i].getXposition();
                snake[i].setYposition(preY);
                snake[i].setXposition(preX);
                preY = tmpY;
                preX = tmpX;
            }
            gameBoard[preY][preX] = '0';
            snakeOnBoard(snake);
        }
        void readBoard(){
            for(int i=0;i<20;i++){
                for(int j=0;j<20;j++){
                    char point = gameBoard[i][j];
                    if(point == '3'){
                        board.addAt(i,j*2,'3');
                    } else if(point == '4'){
                        board.addAt(i,j*2,'4');
                    } else if(point =='G'){
                        board.addAt(i,j*2,'G');
                    } else if(point == 'P'){
                        board.addAt(i,j*2,'P');
                    }
                }
            }

        };
        

        void makeGItem(){            
            if(gItemNum<3){
                int y = rand()%19+1;
                int x = rand()%19+1;
                while(true){
                    char refer = gameBoard[y][x];
                    if(refer=='0'){
                        gameBoard[y][x] = 'G';
                        ++gItemNum;
                        break;
                    } else {
                        y = rand()%19+1;
                        x = rand()%19+1;
                    }
                }

            }
        }
        void makePItem(){            
            if(pItemNum<3){
                int y = rand()%19+1;
                int x = rand()%19+1;
                while(true){
                    char refer = gameBoard[y][x];
                    if(refer=='0'){
                        gameBoard[y][x] = 'P';
                        ++pItemNum;
                        break;
                    } else {
                        y = rand()%19+1;
                        x = rand()%19+1;
                    }
                }

            }
        }
        void snakeOnBoard(Snake s){
            for(int i=0;i<s.getLength();i++){
                int y= s[i].getYposition();
                int x= s[i].getXposition();
                PART p = s[i].getPart();
                if(p==HEAD){
                    gameBoard[y][x] = '3';
                } else {
                    gameBoard[y][x] = '4';
                }
            }
        }

        bool isOver(){
            return game_over;
        }

        void setDirection(DIRECTION d){
            direction = d;
        }

    private:
        Board board;
        ScoreBoard score_board;
        bool game_over;
        DIRECTION direction;
        Snake snake;
        int score;
        int gItemNum;
        int pItemNum;
        char gameBoard[21][21] = {
            {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
            {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
        };
        
};

#endif