#include "game.h"
#include <winuser.h>


void Game::startGame()
{
    std::cout << "place a map height: " << std::endl;
    std::cin >> maxHeight;
    std::cout << "place a map width: " << std::endl;
    std::cin >> maxWidth;

    snake mainSnake;
    mainSnake.x = 1;
    mainSnake.y = 1;
    allSnakes.push_back(mainSnake);

    applePos.x = 2;
    applePos.y = 2;

    mainLoop();
}

void Game::mainLoop()
{
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

        if(allSnakes.front().x == applePos.x && allSnakes.front().y == applePos.y)
            SnakeEatApple();

        // отрисовка игры
        clearScreen();
        addFieldToMap();
        addSnakeToMap();
        addAppleToMap();
        showScreen();
    }

    endGame();
}

void Game::addSnakeToMap()
{
    for(auto snake : allSnakes)
    {
        mapp[snake.y][snake.x] = 'O';
    }
}

void Game::addAppleToMap()
{
    mapp[applePos.y][applePos.x] = 'X';
}

void Game::SnakeEatApple()
{
    srand(time(0));
    applePos.x = rand() % maxWidth;
    applePos.y = rand() % maxHeight;

    snake newSnake;
    newSnake.x = allSnakes.back().x;
    newSnake.y = allSnakes.back().y;
    allSnakes.push_back(newSnake);

    score ++;
}

void Game::move(int x, int y)
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

void Game::moveMiniSnakes()
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

void Game::addFieldToMap()
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

void Game::showScreen()
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

void Game::clearScreen()
{
    system("cls");
}

void Game::endGame()
{
    clearScreen();
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "you loose" << std::endl;
    std::cout << "score: " << score;
    std::string ever;
    std::cin >> ever;
}



