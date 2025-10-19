#include <iostream>

#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>

int main(int argc, char* argv[]) {
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "Failed to initialize: " << SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	SDL_Window* window = SDL_CreateWindow("SDL3", 800, 600, SDL_WINDOW_RESIZABLE);
	
	if (window == nullptr) {
		std::cerr << "Window pointer was null: " << SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}
	
	SDL_Event event;
	bool isRunning = true;

	while (isRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}
		}
	}
}