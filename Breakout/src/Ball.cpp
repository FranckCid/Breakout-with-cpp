#include "Game.h"
#include "Ball.h"


Ball::Ball()
{
    RestartBall();
}

void Ball::Move(){
    rect.x += velx;
    rect.y += -vely;
    if(rect.x <= 0 || rect.x >= Game::SCREEN_W-rect.w){
        velx *= -1;
    }else if(rect.y <= 0){
        vely *= -1;
    }else if(rect.y >= Game::SCREEN_H){
        RestartBall();
    }
}

void Ball::RestartBall(){
    w = 20;
    h = 20;
    x = Game::SCREEN_W/2-w;
    y = Game::SCREEN_H/2-h;

    rect = {x, y, w, h};

    velx = Game::nprand();
    vely = 1;
}
