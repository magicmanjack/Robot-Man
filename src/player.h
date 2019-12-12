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
		void changeViewPoint(vPoint viewPoint);
		
		void update();
		void render(SDL_Renderer* rr);
		
		double xCoord, yCoord;
		double xVel;
		double getHorVel();
		void setHorVel(double vel);
		
		double yVel;
		double getVertVel();
		void setVertVel(double vel);
		
		double acc;
		
		const double max_vel = 4;
};

#endif