#include <SDL.h>

#ifndef _PLAYER_H_INCLUDED_
#define _PLAYER_H_INCLUDED_

class Player {
	public:
		SDL_Rect rect;
		SDL_Texture* textures[6];
		
		bool l, r, u, d;
		Player(SDL_Renderer * rr);
		
		void update();
		void render(SDL_Renderer* rr);
		
		double xVel;
		double yVel;
		double xAcc;
		double yAcc;
		
		const double max_x_vel = 4;
		const double max_y_vel = 4;
};

#endif