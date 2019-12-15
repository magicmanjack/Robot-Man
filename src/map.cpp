#include "map.h"
#include <cmath>

SDL_Rect tileRect; // Contains information about the dimesions of a tile and is used for rendering the tiles.

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
	//^^Resetting the mapRect.
	tileRect.w = tile_width;
	tileRect.h = tile_height;
	
	if(vp == FROM_LEFT || vp == FROM_RIGHT) {
		mapRect.h = mapRect.h * vScaleFactor;
		tileRect.h = round(tileRect.h * vScaleFactor);
		// Applying height adjustments when the view point is side on.
	}
}

void Map::render(SDL_Renderer* rr) {
	SDL_SetRenderDrawColor(rr, 0x00, 0x9F, 0x00, 0xFF);
	SDL_RenderFillRect(rr, &mapRect);
	for(int ix = 0; ix < tiles_wide; ix++) {
		for(int iy = 0; iy < tiles_high; iy++) {
			tileRect.x = mapRect.x + (ix * tileRect.w);
			tileRect.y = mapRect.y + (iy * tileRect.h);
			if(vp == FROM_LEFT) {
				tileRect.x = mapRect.x + (iy * tileRect.w);
				tileRect.y = mapRect.y + (((tiles_wide - 1) - ix) * tileRect.h);
			} else if(vp == FROM_RIGHT) {
				
			}
			SDL_SetRenderDrawColor(rr, 0xFF, 0x00, 0x00, 0xFF);
			SDL_RenderDrawRect(rr, &tileRect);
		}
	}
}