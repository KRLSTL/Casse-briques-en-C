#include <stdlib.h>

#include "pong.h"
//
// Created by Karl on 10/12/2025.
//
void addPong(pong **p, int x, int y, int h, int w, int red, int green, int blue)
{
    pong *element = malloc(sizeof(pong));
    if(!element) exit(EXIT_FAILURE);     /* Si l'allocation a échoué. */
    element->x = x;
    element->y = y;
    element->h = h;
    element->w = w;
    element->red = red;
    element->green = green;
    element->blue = blue;

    element->prev = *p;
    *p = element;       /* Le pointeur pointe sur le dernier élément. */
}

void pongCheck(pong *thePong)
{
    if (thePong[0].x + thePong[0].w > 640)
    {
        thePong[0].x=0;
    }
    if (thePong[0].x + thePong[0].w < 100)
    {
        thePong[0].x=540;
    }
}
#include "pong.h"