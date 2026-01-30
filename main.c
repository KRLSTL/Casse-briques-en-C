#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <SDL.h>
#include <windows.h>
#include <time.h>
#include "ball.h"
#include "pong.h"
#include "brick.h"
#include <SDL_ttf.h>

void gameloop(SDL_Renderer *renderer)
{
    SDL_bool quit = false;
    SDL_Event event;

    ball *theBall = NULL;
    pong *thePong = NULL;
    brick *theBrick = NULL;

    addBall(&theBall,'b',250,275,50,50,3,2,3,0,255,0);
    addPong(&thePong, 275, 420, 10, 100, 255, 255, 255);
    int brickCountPerLine=9;
    int lines = 3;
    int addY = 0;
    for (int lineCount = 0; lineCount<lines;lineCount++)
    {
        int addX = 0;
        addY+=50;
        for (int count = 0; count < brickCountPerLine; count++)
        {
            addX+=75;
            addBrick(&theBrick, -35+addX, 0+addY, 20, 50, 3, 0, 0, 0);
        }
    }

    int bricksCount = brickCountPerLine * lines;
    bricksCount-=3;
    // addBall(&theBall,'c',150,20,50,50,1,1,255,0,0);
    // addBall(&theBall,'d',130,75,50,50,1,1,0,0,255);

    int lastTimer = SDL_GetTicks();

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
                break;
            }
            else if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
            {
                quit = true;
                break;
            }
            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT)
            {
                thePong->x-=5;
            }
            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT)
            {
                thePong->x+=5;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);


        if (SDL_GetTicks() - lastTimer > 16)
        {
            theBall[0].x += theBall[0].speedX;
            theBall[0].y += theBall[0].speedY;
            // theBall->prev->x += theBall->prev->speedX;
            // theBall->prev->y += theBall->prev->speedY;
            // theBall->prev->prev->x += theBall->prev->prev->speedX;
            // theBall->prev->prev->y += theBall->prev->prev->speedY;
            lastTimer = SDL_GetTicks();
        }

        quit = collisions(theBall, thePong, theBrick);
        if (quit == true)
        {
            break;
        }
        quit = lives(theBrick, bricksCount);
        pongCheck(thePong);

        SDL_Rect ballRect = {theBall->x, theBall->y, theBall->w, theBall->h};
        SDL_Rect pongRect = {thePong->x,thePong->y,thePong->w,thePong->h};
        SDL_Rect brickRect = {theBrick->x,theBrick->y,theBrick->w,theBrick->h};
        // SDL_Rect ballRect2 = {theBall->prev->x, theBall->prev->y, theBall->prev->w, theBall->prev->h};
        // SDL_Rect ballRect3 = {theBall->prev->prev->x, theBall->prev->prev->y, theBall->prev->prev->w, theBall->prev->prev->h};


        SDL_SetRenderDrawColor(renderer, theBall->red,theBall->green,theBall->blue,255);
        SDL_RenderFillRect(renderer, &ballRect);

        SDL_SetRenderDrawColor(renderer, thePong->red,thePong->green,thePong->blue,255);
        SDL_RenderFillRect(renderer, &pongRect);

        brick* current = theBrick;
        for (int lineCount=0; lineCount<lines; lineCount++)
        {
            current=theBrick;
            while (current != NULL)
            {
                SDL_SetRenderDrawColor(renderer, current->red, current->green, current->blue, 255);
                SDL_Rect brickRect = {
                    current->x,
                    current->y,
                    current->w,
                    current->h
                };

                SDL_RenderFillRect(renderer, &brickRect);

                current = current->prev;
            }
        }

        // SDL_SetRenderDrawColor(renderer, theBall->prev->red,theBall->prev->green,theBall->prev->blue,255);
        // SDL_RenderFillRect(renderer, &ballRect2);
        //
        // SDL_SetRenderDrawColor(renderer, theBall->prev->prev->red,theBall->prev->prev->green,theBall->prev->prev->blue,255);
        // SDL_RenderFillRect(renderer, &ballRect3);
        SDL_RenderPresent(renderer);
    }
}

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    if (TTF_Init() == -1)
    {
        fprintf(stderr, "TTF_Init failed: %s", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    if (0!=SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr,"Erreur SDL_Init : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    if (NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
    if (NULL==renderer)
    {
        fprintf(stderr,"Erreur SDL_CreateRenderer : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    gameloop(renderer);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}