#include "ball.h"
#include <process.h>
#include <SDL_events.h>
#include <stdio.h>
#include <stdlib.h>
#include "brick.h"
//
// Created by Karl on 09/12/2025.
//

void addBall(ball **p, char nom, int x, int y, int h, int w, int lives, int speedX, int speedY, int red, int green, int blue)
{
    ball *element = malloc(sizeof(ball));
    if(!element) exit(EXIT_FAILURE);     /* Si l'allocation a échoué. */
    element->nom = nom;
    element->x = x;
    element->y = y;
    element->h = h;
    element->w = w;
    element->lives = lives;
    element->speedX = speedX;
    element->speedY = speedY;
    element->red = red;
    element->green = green;
    element->blue = blue;

    element->prev = *p;
    *p = element;       /* Le pointeur pointe sur le dernier élément. */
}



bool collisions(ball *theBall, pong *thePong, brick *theBrick)
{
    if (theBall[0].x + theBall[0].w + theBall[0].speedX > 640 || theBall[0].x + theBall[0].speedX < 0)
    {
        if (theBall[0].x + theBall[0].w + theBall[0].speedX < 0)
        {
            theBall[0].x=5;
        }
        theBall[0].speedX *= -1;
        theBall[0].red=rand() % 255;
        theBall[0].blue=rand() % 255;
        theBall[0].green=rand() % 255;
    }

    if (theBall[0].y + theBall[0].w + theBall[0].speedY > 480 || theBall[0].y + theBall[0].speedY < 0)
    {
        theBall[0].red=rand() % 255;
        theBall[0].blue=rand() % 255;
        theBall[0].green=rand() % 255;
        if (theBall[0].y + theBall[0].w + theBall[0].speedY > 480)
        {
            theBall[0].lives-=1;
            theBall[0].x=thePong[0].x;
            theBall[0].y=thePong[0].y-100;
        }

        if (theBall[0].lives==0)
        {
            printf("Perdu!");
            return true;
        }
    }

    if (theBall[0].x + theBall[0].w + theBall[0].speedX > 640 || theBall[0].x + theBall[0].speedX < 0)
    {
        theBall[0].speedX *= -1;
        theBall[0].red=rand() % 255;
        theBall[0].blue=rand() % 255;
        theBall[0].green=rand() % 255;
    }

    if (theBall[0].y + theBall[0].w + theBall[0].speedY > 480 || theBall[0].y + theBall[0].speedY < 0)
    {
        theBall[0].speedY *= -1;
        theBall[0].red=rand() % 255;
        theBall[0].blue=rand() % 255;
        theBall[0].green=rand() % 255;
    }

    if (theBall[0].y + theBall[0].h >= thePong[0].y &&
        theBall[0].y <= thePong[0].y + thePong[0].h &&
        theBall[0].x + theBall[0].w >= thePong[0].x &&
        theBall[0].x <= thePong[0].x + thePong[0].w)
    {
        theBall[0].speedY *= -1;
        theBall[0].y -= 3;
        theBall[0].red = rand() % 255;
        theBall[0].blue = rand() % 255;
        theBall[0].green = rand() % 255;
    }

    while (theBrick->prev!=NULL)
    {
        theBrick=theBrick->prev;
        if (theBall[0].y + theBall[0].h >= theBrick[0].y &&
            theBall[0].y <= theBrick[0].y + theBrick[0].h &&
            theBall[0].x + theBall[0].w >= theBrick[0].x &&
            theBall[0].x <= theBrick[0].x + theBrick[0].w)
        {
            theBall[0].speedY *= -1;
            theBall[0].y = theBrick[0].y+theBrick[0].h+2;
            theBrick[0].lives-=1;
            theBall[0].red = rand() % 255;
            theBall[0].blue = rand() % 255;
            theBall[0].green = rand() % 255;
        }
    }
}

//unused
/*void checkCollisions(ball *theBall)
{
    int playerCount = 0;
    ball* b = theBall;
    while (b->prev!=NULL)
    {
        playerCount++;
        b = b->prev;
    }
    for (int count = 0; count > playerCount; count++)
    {
        if (theBall[count].x + theBall[count].w + theBall[count].speedX > 640 || theBall[count].x + theBall[count].speedX < 0)
        {
            theBall[count].speedX *= -1;
            theBall[count].red=rand() % 255;
            theBall[count].blue=rand() % 255;
            theBall[count].green=rand() % 255;
        }

        if (theBall[count].y + theBall[count].w + theBall[count].speedY > 480 || theBall[count].y + theBall[count].speedY < 0)
        {
            theBall[count].speedY *= -1;
            theBall[count].red=rand() % 255;
            theBall[count].blue=rand() % 255;
            theBall[count].green=rand() % 255;
        }

        if (theBall[count].x + theBall[count].w + theBall[count].speedX > 640 || theBall[count].x + theBall[count].speedX < 0)
        {
            theBall[count].speedX *= -1;
            theBall[count].red=rand() % 255;
            theBall[count].blue=rand() % 255;
            theBall[count].green=rand() % 255;
        }

        if (theBall[count].y + theBall[count].w + theBall[count].speedY > 480 || theBall[count].y + theBall[count].speedY < 0)
        {
            theBall[count].speedY *= -1;
            theBall[count].red=rand() % 255;
            theBall[count].blue=rand() % 255;
            theBall[count].green=rand() % 255;
        }
            if (theBall[0].x+theBall[0].w*2+theBall[0].speedX == theBall[0].x+theBall[0].w+theBall[0].speedX)
            {
                theBall[0].speedX *= -1;
                theBall[0].red=rand() % 255;
                theBall[0].blue=rand() % 255;
                theBall[0].green=rand() % 255;
                theBall[0].speedX *= -1;
                theBall[0].red=rand() % 255;
                theBall[0].blue=rand() % 255;
                theBall[0].green=rand() % 255;
            }

            if (theBall[0].y+theBall[0].w*2+theBall[0].speedY == theBall[0].y+theBall[0].w+theBall[0].speedY)
            {
                theBall[0].speedY *= -1;
                theBall[0].red=rand() % 255;
                theBall[0].blue=rand() % 255;
                theBall[0].green=rand() % 255;
                theBall[0].speedY *= -1;
                theBall[0].red=rand() % 255;
                theBall[0].blue=rand() % 255;
                theBall[0].green=rand() % 255;
            }
        }
    }*/