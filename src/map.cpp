#include "map.h"

SDL_Rect tileRect; // Contains information about the dimesions of the tile which are to be used when rendering.

Map::Map(SDL_Renderer* rr) {
	x = 0;
	y = 0;
	w = 600;
	h = 600;
	mapRect.x = x;
	mapRect.y = y;
	mapRect.w = w;
	mapRect.h = h;
	vScaleFactor = 1; // The map will be scaled to the normal height.
}

void Map::update() {
	mapRect.x = x;
	mapRect.y = y;
	mapRect.w = w;
	mapRect.h = h;
	// Resetting the mapRect.
	
}

void Map::render(SDL_Renderer* rr) {
	SDL_SetRenderDrawColor(rr, 0x00, 0x9F, 0x00, 0xFF);
	SDL_RenderFillRect(rr, &mapRect);
}