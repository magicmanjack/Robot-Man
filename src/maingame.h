#include <SDL.h>
#include <list>

#ifndef _MAING_H_INCLUDED_
#define _MAING_H_INCLUDED_

class MainGame {
	public:
		MainGame();
		static std::list<SDL_Event> eventsQueued;
		static SDL_Renderer * rr;
		static void init(SDL_Renderer* rr);
		static void update();
		static void render();
};

#endif