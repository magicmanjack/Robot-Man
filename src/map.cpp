#include "map.h"

Map::Map(SDL_Renderer* rr) {
	x = 0;
	y = 0;
	w = 600;
	h = 600;
	mapRect.x = x;
	mapRect.y = y;
	mapRect.w = w;
	mapRect.h = h;
}

void Map::update() {
	
}

void Map::render(SDL_Renderer* rr) {
	SDL_SetRenderDrawColor(rr, 0x00, 0x9F, 0x00, 0xFF);
	SDL_RenderFillRect(rr, &mapRect);
}