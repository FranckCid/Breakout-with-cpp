#ifndef GAME_H
#define GAME_H

class Game
{
    public:
        static const int SCREEN_W, SCREEN_H, PADDLE_WIDTH, PADDLE_HEIGHT, FPS;
        Game();
        static int nprand();
};

#endif // GAME_H
