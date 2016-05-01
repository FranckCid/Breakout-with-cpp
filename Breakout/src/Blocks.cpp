#include "Blocks.h"

const int BLOCK_WEIGHT=45, BLOCK_HEIGHT=20;

Block::Block(){
    x = 10;
    y = 10;
    w = BLOCK_WEIGHT;
    h = BLOCK_HEIGHT;
    rect = {x, y, w, h};
}

Block::Block(int x, int y){
    w = BLOCK_WEIGHT;
    h = BLOCK_HEIGHT;
    rect = {x, y, w, h};
}

Block::Block(int x, int y, int w, int h){
    rect = {x, y, w, h};
}


