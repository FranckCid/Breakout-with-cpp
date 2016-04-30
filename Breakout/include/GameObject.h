#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL/SDL.h>

class GameObject
{
    public:
        SDL_Rect rect;
        GameObject();
        bool Intersects(SDL_Rect r);
    protected:
        int x, y, w, h;
};

#endif // GAMEOBJECT_H
