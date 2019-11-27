#include <iostream>
#include "SDL.h"

const int w_width = 600, w_height = 600;
SDL_Window * window;
SDL_Renderer * rr;

int main(int argc, char** argv) {
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
		std::cout << "COULD NOT INITIALIZE SDL!" << std::endl;
	}
	window = SDL_CreateWindow("Robot Man", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_width, w_height, 0);
	rr = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	bool closed = false;
	SDL_Event event;
	while(!closed) {
		if(SDL_PollEvent(&event)) {
			if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
				closed = true;
			}
		}
	}
	SDL_Quit();
	return 0;
}