#ifndef BLOCKS_H
#define BLOCKS_H

#include "GameObject.h"

class Block : public GameObject
{
    public:
        Block();
        Block(int x, int y);
        Block(int x, int y, int w, int h);
    protected:
    private:
};

#endif // BLOCKS_H
