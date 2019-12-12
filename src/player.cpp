#include "player.h"
#include <cmath>

int ticks;

Player::Player(SDL_Renderer* rr) {
	index = 0;
	animIndex = 0;
	rocketsAnimIndex = 0;
	xCoord = 250;
	yCoord = 0;
	collisionRect.w = 60;
	collisionRect.h = 60;
	rect.x = xCoord;
	rect.y = rect.y = round(yCoord - (rect.h - collisionRect.h));
	rect.w = 60;
	rect.h = 100;
	SDL_Surface* surface;
	surface = SDL_LoadBMP("res/player_1.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[0] = SDL_CreateTextureFromSurface(rr, surface);
	surface = SDL_LoadBMP("res/player_2.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[1] = SDL_CreateTextureFromSurface(rr, surface);
	surface = SDL_LoadBMP("res/player_1_left.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[2] = SDL_CreateTextureFromSurface(rr, surface);
	surface = SDL_LoadBMP("res/player_2_left.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[3] = SDL_CreateTextureFromSurface(rr, surface);
	surface = SDL_LoadBMP("res/player_1_up.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[4] = SDL_CreateTextureFromSurface(rr, surface);
	surface = SDL_LoadBMP("res/player_2_up.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[5] = SDL_CreateTextureFromSurface(rr, surface);
	surface = SDL_LoadBMP("res/player_1_right.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[6] = SDL_CreateTextureFromSurface(rr, surface);
	surface = SDL_LoadBMP("res/player_2_right.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[7] = SDL_CreateTextureFromSurface(rr, surface);
	surface = SDL_LoadBMP("res/rockets_front_1.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[8] = SDL_CreateTextureFromSurface(rr, surface);
	surface = SDL_LoadBMP("res/rockets_front_2.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[9] = SDL_CreateTextureFromSurface(rr, surface);
	surface = SDL_LoadBMP("res/rockets_side_1.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[10] = SDL_CreateTextureFromSurface(rr, surface);
	surface = SDL_LoadBMP("res/rockets_side_2.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[11] = SDL_CreateTextureFromSurface(rr, surface);
	
	
	l = false;
	r = false;
	u = false;
	d = false;
	flying = false;
	xVel = 0;
	yVel = 0;
	acc = 0.25;
}

void Player::changeViewPoint(vPoint viewPoint) {
	// Updates the character direction.
	if(vp != viewPoint) {
		if(vp == FROM_LEFT) {
			if(viewPoint == FROM_FRONT) {
				index += 2;
			}
			if(viewPoint == FROM_RIGHT) {
				index += 6;
			}
		}
		if(vp == FROM_FRONT) {
			if(viewPoint == FROM_LEFT) {
				index -= 2;
			}
			if(viewPoint == FROM_RIGHT) {
				index += 2;
			}
		}
		if(vp == FROM_RIGHT) {
			if(viewPoint == FROM_LEFT) {
				index += 4;
			}
			if(viewPoint == FROM_FRONT) {
				index += 6;
			}
		}
		if(index >= 8) {
			index = index - 8;
		} else if(index < 0) {
			index = 8 + index;
		}
	}
	vp = viewPoint;
}

void Player::setHorVel(double vel) {
	//Sets the horizontal velocity regardless of it being a component of x or y.
	if(vp == FROM_FRONT) {
		xVel = vel;
	}
	if(vp == FROM_LEFT) {
		yVel = vel;
	}
	if(vp == FROM_RIGHT) {
		yVel = -vel;
	}
}

double Player::getHorVel() {
	//Returns horizontal velocity regardless of whether it is x or y velocity.
	if(vp == FROM_FRONT) {
		return xVel;	
	}
	if(vp == FROM_LEFT) {
		return yVel;
	}
	if(vp == FROM_RIGHT) {
		return -yVel;
	}
}

void Player::setVertVel(double vel) {
	//Sets the vertical velocity regardless of it being a component of x or y.
	if(vp == FROM_FRONT) {
		yVel = vel;
	}
	if(vp == FROM_LEFT) {
		xVel = -vel;
	}
	if(vp == FROM_RIGHT) {
		xVel = vel;
	}
}

double Player::getVertVel() {
	//Returns vertical velocity regardless of whether it is x or y velocity.
	if(vp == FROM_FRONT) {
		return yVel;
	}
	if(vp == FROM_LEFT) {
		return -xVel;
	}
	if(vp == FROM_RIGHT) {
		return xVel;
	}
}

void Player::update() {
	ticks++;
	if(ticks % 15 == 0) {
		rocketsAnimIndex = !rocketsAnimIndex; // Changes four times a second.
	}
	if(ticks >= 60) {
		ticks = 0;
		animIndex = !animIndex;
	}
	
	if(l) { 
		index = 2;
		setHorVel(getHorVel() - (acc * flying));
		if(getHorVel() <= -1 * max_vel) {
			setHorVel(-1 * max_vel);
		}
	}
	if(r) {
		index = 6;
		setHorVel(getHorVel() + (acc * flying));
		if(getHorVel() >= max_vel) {
			setHorVel(max_vel);
		}
	}
	if(u) {
		index = 4;
		setVertVel(getVertVel() - (acc * flying));
		if(getVertVel() <= -1 * max_vel) {
			setVertVel(-1 * max_vel);
		}
	}
	if(d) {
		index = 0;
		setVertVel(getVertVel() + (acc * flying));
		if(getVertVel() >= max_vel) {
			setVertVel(max_vel);
		}
	}
	if(!flying) {
		xVel *= 0.9;
		yVel *= 0.9;	
	}
	xCoord += xVel;
	yCoord += yVel;
	collisionRect.h = rect.w; // Sets the collision box to be perfectly square.
	if(vp == FROM_LEFT) {
		rect.x = round(yCoord);
		rect.y = round((600.0 - xCoord) - rect.h);
		collisionRect.x = round(yCoord);
		collisionRect.y = round((600.0 - xCoord) - collisionRect.w);
	} else if (vp == FROM_FRONT) {
		rect.x = round(xCoord);
		rect.y = round(yCoord - (rect.h - collisionRect.h));
		collisionRect.x = round(xCoord);
		collisionRect.y = round(yCoord);
	} else if (vp == FROM_RIGHT) {
		rect.x = round((600.0 - yCoord) - rect.w);
		rect.y = round(xCoord - (rect.h - collisionRect.w));
		collisionRect.x = round((600.0 - yCoord) - rect.w);
		collisionRect.y = round(xCoord);
	}
}

void Player::render(SDL_Renderer* rr) {
	if(flying) {
		rect.y -= 20;
		SDL_Rect rocketsRect;
		rocketsRect.x = rect.x;
		rocketsRect.y = rect.y + rect.h;
		rocketsRect.w = 60;
		rocketsRect.h = 20;
		SDL_RenderCopy(rr, textures[8 + (2 * (index == 2 || index == 6)) + rocketsAnimIndex], NULL, &rocketsRect);
	}
	SDL_RenderCopy(rr, textures[index + animIndex], NULL, &rect);
}