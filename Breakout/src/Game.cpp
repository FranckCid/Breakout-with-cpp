#include "Game.h"

#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

const int Game::SCREEN_W = 500, Game::SCREEN_H = 500, Game::PADDLE_WIDTH = 100, Game::PADDLE_HEIGHT = 30, Game::FPS = 60;

Game::Game()
{
    //ctor
}

int Game::nprand(){
    if(rand() % 50 > 25){
        return 1;
    }
    return -1;
}
