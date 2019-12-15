#include <SDL.h>
#include "view.h"

#ifndef _MAP_H_INCLUDED_
#define _MAP_H_INCLUDED_

class Map {
	public:
		int x;
		int y;
		int w;
		int h;
		
		SDL_Rect mapRect;
		
		Map(SDL_Renderer* rr);
		
		static const int tiles_wide = 10;
		static const int tiles_high = 10;
		int mapTiles[tiles_wide][tiles_high]; // Each number corresponds to a specific texture.
		static const int tile_width = 60; // The width of each tile.
		static const int tile_height = 60; // The height of each tile.
		
		double vScaleFactor; // The scale factor of the map vertically. 
		
		void update();
		void render(SDL_Renderer* rr);
		
		bool showTileBounds;
};

#endif