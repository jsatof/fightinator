#pragma once

#include <SDL2/SDL.h>

extern SDL_Rect collisionRects[64];
extern size_t collisionRectSize;

void DrawScene(SDL_Renderer *renderer, SDL_Rect dim);
