//
// Created by Karl on 09/12/2025.
//

#ifndef HELLOSDL2025_BALL_H
#define HELLOSDL2025_BALL_H
#include "pong.h"
#include "brick.h"
#ifndef BALL_H
#define BALL_H

typedef struct pong pong;
typedef struct brick brick;


typedef struct ball
{
    char nom;

    int x;
    int y;
    int h;
    int w;
    int lives;

    int speedX;
    int speedY;

    int red;
    int green;
    int blue;

    struct ball *prev;
} ball;

void addBall(ball **p, char nom, int x, int y, int h, int w, int lives, int speedX, int speedY, int red, int green, int blue);
bool collisions(ball *theBall, pong *thePong, brick *theBrick);

// void checkCollisions(ball *theBall);
#endif
#endif //HELLOSDL2025_BALL_H