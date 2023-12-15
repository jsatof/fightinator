#include <stdbool.h>
#include <stdio.h>

#include <SDL2/SDL.h>

#include <color.h>
#include <ui.h>

bool isQuitEvent(SDL_Event * const event) {
	return event->type == SDL_KEYDOWN && event->key.keysym.scancode == SDL_SCANCODE_ESCAPE;
}

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);

	int windowWidth = 1280, windowHeight = 720;
	SDL_Rect windowDims = { .x = 0, .y = 0, .w = windowWidth, .h = windowHeight };
	SDL_Window *window = SDL_CreateWindow("Fightinator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_BORDERLESS);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event event;
	
	bool shouldQuit = false;
	while (!shouldQuit) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT || isQuitEvent(&event)) {
			break;
		}

		SDL_RenderClear(renderer);

		setDrawColor(renderer, &colorscheme[0]);

		DrawScene(renderer, windowDims);

		setDrawColor(renderer, &colorscheme[0]);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}
