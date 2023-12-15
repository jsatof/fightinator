#pragma once

#include <SDL2/SDL.h>

extern SDL_Color colorscheme[];
extern size_t colorscheme_length;

void setDrawColor(SDL_Renderer *renderer, SDL_Color *c);
