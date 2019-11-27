#include <SDL.h>

#ifndef _MAING_H_INCLUDED_
#define _MAING_H_INCLUDED_

class MainGame {
	public:
		MainGame();
		static SDL_Renderer * rr;
		static void update();
		static void render();
};

#endif