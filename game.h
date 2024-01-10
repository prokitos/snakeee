#include <windows.h>
#include <conio.h>
#include <vector>
#include <iostream>
#include <string>

struct snake
{
    int x;
    int y;
};


void move(int x, int y);
void moveMiniSnakes();
void addFieldToMap();
void showScreen();
void addSnakeToMap();
void addAppleToMap();
void SnakeEatApple();
void startGame();
void clearScreen();




