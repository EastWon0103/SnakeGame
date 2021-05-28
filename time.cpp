#include <iostream>
#include <time.h>
#include <unistd.h>
#include <random>
using namespace std;

int main(){
    srand((int)time(0));
    int r = rand()%11+1;
    cout << r;
    return 0;
};