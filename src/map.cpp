#include "map.h"
#include <cmath>

SDL_Rect tileRect; // Contains information about the dimesions of a tile and is used for rendering the tiles.
SDL_Texture* tileTextures[7];

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
	showTileBounds = false; // If true, the outlines of every tile is shown. Useful for debugging.
	tileTextures[1] = SDL_CreateTextureFromSurface(rr, SDL_LoadBMP("res/road_1.bmp"));
	tileTextures[2] = SDL_CreateTextureFromSurface(rr, SDL_LoadBMP("res/road_2.bmp"));
	tileTextures[3] = SDL_CreateTextureFromSurface(rr, SDL_LoadBMP("res/road_3.bmp"));
	tileTextures[4] = SDL_CreateTextureFromSurface(rr, SDL_LoadBMP("res/road_4.bmp"));
	tileTextures[5] = SDL_CreateTextureFromSurface(rr, SDL_LoadBMP("res/road_5.bmp"));
	tileTextures[6] = SDL_CreateTextureFromSurface(rr, SDL_LoadBMP("res/road_6.bmp"));
	
	SDL_RWops* file = SDL_RWFromFile("res/map.txt", "rb");
	char mapInChars[101];
	if(file != NULL) {
		if(!file->read(file, mapInChars, 1, sizeof (mapInChars))) {
			SDL_Log("map.txt could not be read or is empty");
		} else {
			for(int i = 0; mapInChars[i] != 0; i++) {
				mapTiles[i - ((int)floor(i / tiles_wide) * tiles_wide)][(int)floor(i / tiles_wide)] = (int)mapInChars[i] - (int)'0';
				SDL_Log("%d - %d", (int)mapInChars[i], (int)'0');
			}
		}
		SDL_RWclose(file);	
	}
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
	for(int ix = 0; ix < tiles_wide; ix++) {
		for(int iy = 0; iy < tiles_high; iy++) {
			tileRect.x = mapRect.x + (ix * tileRect.w);
			tileRect.y = mapRect.y + (iy * tileRect.h);
			if(vp == FROM_LEFT) {
				tileRect.x = mapRect.x + (iy * tileRect.w);
				tileRect.y = mapRect.y + (((tiles_wide - 1) - ix) * tileRect.h);
			} else if(vp == FROM_RIGHT) {
				tileRect.x = mapRect.x + (((tiles_high -1) - iy) * tileRect.w);
				tileRect.y = mapRect.y + (ix * tileRect.h);
			}
			if(mapTiles[ix][iy] == 0) {
				SDL_SetRenderDrawColor(rr, 0x1C, 0x71, 0x00, 0xFF);
				SDL_RenderFillRect(rr, &tileRect);
			} else {
				SDL_RenderCopy(rr, tileTextures[mapTiles[ix][iy]], NULL, &tileRect);
			}
			if(showTileBounds) {
				SDL_SetRenderDrawColor(rr, 0xFF, 0x00, 0x00, 0xFF);
				SDL_RenderDrawRect(rr, &tileRect);
			}
		}
	}
}