#include "player.h"
#include <cmath>

double ticks;
int rotOffset;

Player::Player(SDL_Renderer* rr) {
	index = 0;
	animIndex = 0;
	xCoord = 250;
	yCoord = 0;
	collisionRect.w = 60;
	collisionRect.h = 60;
	rect.x = xCoord;
	rect.y = yCoord;
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
	l = false;
	r = false;
	u = false;
	d = false;
	flying = false;
	xVel = 0;
	yVel = 0;
	xAcc = 0.25;
	yAcc = 0.25;
}

void Player::update() {
	ticks++;
	if(ticks >= 60) {
		ticks = 0;
		animIndex = !animIndex;
	}
	if(l) { 
		index = 2;
		xVel -= xAcc * flying;
		if(xVel <= -1 * max_x_vel) {
			xVel = -1 * max_x_vel;
		}
	}
	if(r) {
		index = 6;
		xVel += xAcc * flying;
		if(xVel >= max_x_vel) {
			xVel = max_x_vel;
		}
	}
	if(u) {
		index = 4;
		yVel -= yAcc * flying;
		if(yVel <= -1 * max_y_vel) {
			yVel = -1 * max_y_vel;
		}
	}
	if(d) {
		index = 0;
		yVel += yAcc * flying;
		if(yVel >= max_y_vel) {
			yVel = max_y_vel;
		}
	}
	if(!flying) {
		xVel *= 0.9;
		yVel *= 0.9;	
	}
	xCoord += xVel;
	yCoord += yVel;
	if(vp == FROM_LEFT) {
		rect.x = round(yCoord);
		rect.y = round((600.0 - xCoord) - rect.h);
		collisionRect.x = round(yCoord);
		collisionRect.y = round((600.0 - xCoord) - collisionRect.w);
	} else if (vp == FROM_FRONT) {
		rect.x = round(xCoord - (rect.w - collisionRect.w));
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
	SDL_SetRenderDrawColor(rr, 0xFF, 0x00, 0x00, 0x00);
	SDL_RenderDrawRect(rr, &collisionRect);
	SDL_RenderCopy(rr, textures[index + animIndex], NULL, &rect);
}