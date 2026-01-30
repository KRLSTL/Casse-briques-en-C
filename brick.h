//
// Created by Karl on 16/01/2026.
//

#ifndef HELLOSDL2025_BRICK_H
#define HELLOSDL2025_BRICK_H
#include "pong.h"
#include "ball.h"
#ifndef BRICK_H
#define BRICK_H

typedef struct brick
{
    int x;
    int y;
    int h;
    int w;
    int lives;

    int red;
    int green;
    int blue;

    struct brick *prev;
} brick;

void addBrick(brick **p, int x, int y, int h, int w, int lives, int red, int green, int blue);
bool lives(brick *theBrick, int bricksCount);
#endif
#endif //HELLOSDL2025_BRICK_H

