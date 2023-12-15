#include <stdio.h>

#include <color.h>
#include <ui.h>

size_t collisionRectSize = sizeof(collisionRects) / sizeof(SDL_Rect);

typedef struct Rect {
	SDL_Rect rect;
	SDL_Color color;
} Rect;

// draw textures and geometry
void DrawScene(SDL_Renderer *renderer, SDL_Rect dims) {
	SDL_Surface *playerSprite = SDL_LoadBMP("res/sprites/sprPlayer_Idle_Base/db2fc81d-2938-4d75-b1a3-c51d5cf7b5d0.png");
	if (!playerSprite) {
		fprintf(stderr, "Couldnt find sprPlayer_Idle_Base\n");
	}

	SDL_Rect floor = { .x = 0, .y = 648, .w = dims.w, .h = 72 };

	setDrawColor(renderer, &colorscheme[1]);
	SDL_RenderFillRect(renderer, &floor);
}
