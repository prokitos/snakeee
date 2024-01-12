#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <memory>
#include <numeric>
#include <sstream>
#include <iterator>

#include "game.h"

void consoleClear()
{

    for (short i = 0; i < 10; i++)
    {
        std::cout << "\t\n"; 
    }
    
}


int main()
{
    consoleClear();
    Game game;
    game.startGame();
    
    return 0;
}

