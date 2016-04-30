#include "Game.h"
#include "Paddle.h"

Paddle::Paddle()
{
    w = Game::PADDLE_WIDTH;
    h = Game::PADDLE_HEIGHT;
    x = Game::SCREEN_W / 2 - w/2;
    y = Game::SCREEN_H - h - 20;
    rect = {x, y, w, h};
}

void Paddle::Move(int dir){
    rect.x += dir;
}

