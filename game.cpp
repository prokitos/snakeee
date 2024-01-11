#include "game.h"
#include <winuser.h>

int maxHeight;
int maxWidth;
std::vector<snake> allSnakes;
std::vector<std::string> mapp;
int appleX;
int appleY;
bool infinity = true;


void startGame()
{

    std::cout << "place a map height: " << std::endl;
    std::cin >> maxHeight;
    std::cout << "place a map width: " << std::endl;
    std::cin >> maxWidth;

    snake first;
    first.x = 1;
    first.y = 1;
    allSnakes.push_back(first);

    appleX = 2;
    appleY = 2;

    // главный цикл игры
    while(infinity)
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
        if(GetAsyncKeyState('P'))
            break;


        if(allSnakes.front().x == appleX && allSnakes.front().y == appleY)
            SnakeEatApple();



        clearScreen();
        addFieldToMap();
        addSnakeToMap();
        addAppleToMap();
        showScreen();
        


    }

    clearScreen();
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "you loose" << std::endl;
    std::string ever;
    std::cin >> ever;
    
    

    


}



void addSnakeToMap()
{
    for(auto snake : allSnakes)
    {
        mapp[snake.y][snake.x] = 'O';
    }
}

void addAppleToMap()
{
    mapp[appleY][appleX] = 'X';
}


void SnakeEatApple()
{
    srand(time(0));
    appleX = rand() % maxWidth;
    appleY = rand() % maxHeight;

    snake temp;
    temp.x = allSnakes.back().x;
    temp.y = allSnakes.back().y;
    allSnakes.push_back(temp);
}


void moveMiniSnakes()
{
    int tempX = allSnakes.front().x;
    int tempY = allSnakes.front().y;
    for(auto &elements : allSnakes)
    {
        int tX = elements.x;
        int tY = elements.y;

        elements.x = tempX;
        elements.y = tempY;

        tempX = tX;
        tempY = tY;
    }
  
}

void move(int x, int y)
{
    moveMiniSnakes();

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

    allSnakes.front().x = tempX;
    allSnakes.front().y = tempY;

    if(mapp.size() > 0 && mapp[tempY][tempX] == 'O')
    {
        infinity = false;
    }
    

}

void addFieldToMap()
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