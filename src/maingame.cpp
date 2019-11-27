#include "maingame.h"
#include <cmath>

SDL_Renderer* MainGame::rr;

double rads = 0.0;

void MainGame::update() {
	rads += 0.1;
}

void MainGame::render() {
	SDL_SetRenderDrawColor(rr, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawLine(rr, 300 + (sin(rads) * 50), 300 + (cos(rads) * 50), 300 - (sin(rads) * 50), 300 - (cos(rads) * 50));
	SDL_SetRenderDrawColor(rr, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawLine(rr, 300 + (cos(rads / 2) * 50), 300 + (sin(rads) * 50), 300 - (cos(rads / 2) * 50), 300 - (sin(rads) * 50));
	SDL_SetRenderDrawColor(rr, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderDrawLine(rr, 300 + (cos(rads) * 50), 300 + (sin(rads / 3) * 50), 300 - (cos(rads) * 50), 300 - (sin(rads / 3) * 50));
}