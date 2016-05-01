#ifndef BALL_H
#define BALL_H

#include "GameObject.h"

#include <SDL/SDL.h>

class Ball : public GameObject
{
    public:
        Ball();
        void Move();
        void RestartBall();
};

#endif // BALL_H
