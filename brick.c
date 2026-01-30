//
// Created by Karl on 16/01/2026.
//
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include "brick.h"

#include <SDL.h>

void addBrick(brick **p, int x, int y, int h, int w, int lives, int red, int green, int blue)
{
    brick *element = malloc(sizeof(brick));
    if(!element) exit(EXIT_FAILURE);     /* Si l'allocation a échoué. */
    element->x = x;
    element->y = y;
    element->h = h;
    element->w = w;
    element->lives = lives;
    element->red = red;
    element->green = green;
    element->blue = blue;

    element->prev = *p;
    *p = element;       /* Le pointeur pointe sur le dernier élément. */
}

bool lives(brick *theBrick, int bricksCount)
{
    brick* current = theBrick;
    while (current->prev!=NULL)
    {
        current=current->prev;
        if (current->lives == 3)
        {
            current->green=255;
            current->blue=50;
        }
        else if (current->lives == 2)
        {
            current->green=255;
            current->red=255;
            current->blue=0;
        }
        else if (current->lives == 1)
        {
            current->green=0;
            current->red=255;
        }
        else
        {
            current->x=999;
            current->y=999;
            current->green=0;
            current->red=0;
            current->blue=0;
            bricksCount-=1;
        }
    }
    if (bricksCount==0)
    {
        printf("Bravo !");
        return true;
    }
}
