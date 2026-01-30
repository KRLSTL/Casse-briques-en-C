//
// Created by Karl on 10/12/2025.
//

#ifndef HELLOSDL2025_PONG_H
#define HELLOSDL2025_PONG_H
#include "ball.h"
#include "brick.h"
#ifndef PONG_H
#define PONG_H

typedef struct pong
{
    int x;
    int y;
    int h;
    int w;

    int red;
    int green;
    int blue;

    struct pong *prev;
} pong;

void addPong(pong **p, int x, int y, int h, int w, int red, int green, int blue);
void pongCheck(pong *thePong);
#endif
#endif //HELLOSDL2025_PONG_H