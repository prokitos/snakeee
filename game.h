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
struct apple
{
    int x;
    int y;
};

class Game
{
public:
    void startGame();   // инициализация параметров
private:
    void mainLoop();        // запуск главного игрового цикла
    void addSnakeToMap();   // добавить змейку на карту
    void addAppleToMap();   // добавить яблоко на карту
    void SnakeEatApple();   // змея съедает яблоко
    void move(int x, int y);    // движение змейки
    void moveMiniSnakes();      // движение тела за головой
    void addFieldToMap();       // создание карты, и добавление её в переменную
    void showScreen();          // показать карту на экране
    void clearScreen();         // очистка экрана
    void endGame();         // конец игры

    int score = 0;
    int maxHeight;
    int maxWidth;
    std::vector<snake> allSnakes;
    std::vector<std::string> mapp;
    apple applePos;
    bool infinity = true;
};







