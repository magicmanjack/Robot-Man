#include <SDL.h>

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
		
		int mapTiles[10][10]; // Each number corresponds to a specific texture.
		
		void update();
		void render(SDL_Renderer* rr);
};

#endif