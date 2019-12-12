#include <SDL.h>

#ifndef _PLAYER_H_INCLUDED_
#define _PLAYER_H_INCLUDED_

class Player {
	public:
		SDL_Rect rect;
		SDL_Rect collisionRect;
		SDL_Texture* textures[12];
		
		int index;
		int animIndex;
		int rocketsAnimIndex;
		
		bool l, r, u, d, flying;
		Player(SDL_Renderer * rr);
		
		enum vPoint {FROM_FRONT, FROM_LEFT, FROM_RIGHT};
		vPoint vp = FROM_FRONT;
		
		int indexRelVp(); // The index relative to the view point.
		
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