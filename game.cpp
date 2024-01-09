#include "game.h"
#include <winuser.h>

int maxHeight;
int maxWidth;
std::vector<snake> allSnakes;
std::vector<std::string> mapp;


void startGame()
{

    maxHeight = 20;
    maxWidth =  20;

    snake first;
    first.x = 10;
    first.y = 10;
    allSnakes.push_back(first);

    // главный цикл игры
    while(true)
    {

        int temp = _getch();
        if(GetAsyncKeyState('W'))
            move(0,-1);
        if(GetAsyncKeyState('S'))
            move(0,1);
        if(GetAsyncKeyState('A'))
            move(-1,0);
        if(GetAsyncKeyState('D'))
            move(1,0);

        clearScreen();
        addToMap();
        addSnakeToMap();
        showScreen();


        if(GetAsyncKeyState('P'))
            break;

    }

    


    


}

void addSnakeToMap()
{
    for(auto snake : allSnakes)
    {
        mapp[snake.y][snake.x] = 'O';
    }
}

void move(int x, int y)
{
    int tempX = allSnakes.front().x;
    int tempY = allSnakes.front().y;

    tempX += x;
    tempY += y;

    if(tempX < 0)
    tempX = maxWidth - 1;
    if(tempY < 0)
    tempY = maxHeight - 1;

    if(tempX >= maxWidth)
    tempX = 0;
    if(tempY >= maxHeight)
    tempY = 0;

    tempX = allSnakes.front().x = tempX;
    tempY = allSnakes.front().y = tempY;

}

void addToMap()
{
    mapp = {};

    for(int i = 0; i < maxHeight; i++)
    {
        mapp.push_back("");
        for(int j = 0; j < maxWidth; j++)
        {
            mapp[i] += ' ';

            // right border
            if(j + 1 == maxWidth)
            mapp[i] += '`';
        }
    }

    mapp.push_back("");
    for(int j = 0; j < maxWidth + 1; j++)
    mapp[maxWidth] += '`';


}


void showScreen()
{
    system("color 1");
    for(int i = 0; i < maxHeight + 1; i++)
    {
        for(int j = 0; j < maxWidth + 1; j++)
        {
            std::cout << mapp[i][j];
        }
        std::cout << std::endl;
    }

    
}

void clearScreen()
{
    system("cls");
}