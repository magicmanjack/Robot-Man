#include <SDL.h>

#ifndef _PLAYER_H_INCLUDED_
#define _PLAYER_H_INCLUDED_

class Player {
	public:
		SDL_Rect rect;
		SDL_Texture* textures[6];
		
		Player(SDL_Renderer * rr);
		
		void update();
		void render(SDL_Renderer* rr);
};

#endif