#ifndef PADDLE_H
#define PADDLE_H

#include "GameObject.h"

#include <SDL/SDL.h>

class Paddle : public GameObject
{
    public:
        Paddle();
        void Move();
        void Move(int dir);
};

#endif // PADDLE_H
