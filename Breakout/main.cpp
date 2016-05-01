#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <iostream>
#include <time.h>
#include <unistd.h>
#include <vector>

#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "Blocks.h"

#include <SDL/SDL.h>

//Engine Methods
void Load();
void Logic();
void DrawScreen();
void Quit();

SDL_Event event;
int starttime=0, endtime=0, delta=0;

int main ( int argc, char** argv )
{
    bool running = true;

    Load();

    while(running){

        starttime = SDL_GetTicks();

        SDL_PollEvent(&event);

        if(event.type == SDL_QUIT){
            running = false;
        }

        Logic();
        DrawScreen();

        std::cout << starttime << " : " << endtime << " | " << delta << "\n";

        endtime = SDL_GetTicks();

        delta = endtime - starttime;

        usleep(100 * delta);

    }

    Quit();

    return 0;
}

//Game Engine variables
Paddle player;
Ball ball;
SDL_Surface *screen;

std::vector<Block> blocks;

void Load(){

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_WM_SetCaption("Breakout", NULL);
    screen = SDL_SetVideoMode(Game::SCREEN_W, Game::SCREEN_H, 32, SDL_SWSURFACE);

    srand(static_cast<unsigned int>(time(0)));

    for(int j=0; j<5; j++){
        for(int i=0; i<10; i++){
            blocks.push_back(Block(50*i, 30*j+10));
        }
    }

}

void Logic(){

    Uint8 *keystates = SDL_GetKeyState(NULL);

    if(keystates[SDLK_a] && player.rect.x > 0){
        player.Move(-1);
    }else if(keystates[SDLK_d] && player.rect.x + player.rect.w < Game::SCREEN_W){
        player.Move(1);
    }

    if(player.Intersects(ball.rect)){
        ball.rect.y -= 10;
        ball.vely *= -1;
    }

    for(int i=0; i<blocks.size(); i++){
        if(ball.Intersects(blocks[i].rect)){
            blocks.erase(blocks.begin() + i);
            ball.rect.y += 10;
            ball.vely *= -1;
        }
    }

    ball.Move();

}

void DrawScreen(){

    SDL_FillRect(screen, NULL, 0);

    //SDL_Rect r = {0, 0, 20, 20};

    SDL_FillRect(screen, &player.rect, 0x55FF5555);
    SDL_FillRect(screen, &ball.rect, 0x5555FF55);

    for(int i=0; i<blocks.size(); i++){
        SDL_FillRect(screen, &blocks[i].rect, 0x555555FF);
    }

    SDL_Flip(screen);

}

void Quit(){
    SDL_Quit();
}
