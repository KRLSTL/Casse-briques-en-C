#include <SDL_ttf.h>
//
// Created by Karl on 09/12/2025.
//
void displayText(SDL_Renderer *renderer, char* path)
{
    TTF_Font* font = TTF_OpenFont("C:\\Users\\Karl\\Desktop\\ENIGMA\\1st year\\C\\projects\\HelloSDL2025\\fonts\\8Bit", 130);
    SDL_Color color = {255,0,0};
    SDL_Surface* surface = TTF_RenderText_Blended(font, "game", color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest = {50,200,300,100};
    SDL_RenderCopy(renderer,texture,NULL,&dest);
}
#include "text.h"