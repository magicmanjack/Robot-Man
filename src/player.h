#include <SDL.h>

#ifndef _PLAYER_H_INCLUDED_
#define _PLAYER_H_INCLUDED_

class Player {
	public:
		SDL_Rect rect;
		SDL_Rect collisionRect;
		SDL_Texture* textures[8];
		
		int index;
		int animIndex;
		
		bool l, r, u, d, flying;
		Player(SDL_Renderer * rr);
		
		enum vPoint {FROM_FRONT = 0, FROM_LEFT = -2, FROM_RIGHT = 2};
		vPoint vp = FROM_FRONT;
		
		void update();
		void render(SDL_Renderer* rr);
		
		double xCoord, yCoord;
		double xVel;
		double yVel;
		double xAcc;
		double yAcc;
		
		const double max_x_vel = 4;
		const double max_y_vel = 4;
};

#endif