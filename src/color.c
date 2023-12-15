#include <color.h>

SDL_Color colorscheme[] = {
	{ .r = 68, .g = 76, .b = 56, .a = 255 },
	{ .r = 25, .g = 25, .b = 25, .a = 255 },
};

size_t colorscheme_length = sizeof(colorscheme) / sizeof(SDL_Color);

void setDrawColor(SDL_Renderer *renderer, SDL_Color *c) {
	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, c->a);
}
