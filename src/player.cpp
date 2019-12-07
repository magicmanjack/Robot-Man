#include "player.h"
#include <iostream>

int index = 0;
int animIndex = 0;

double ticks;

Player::Player(SDL_Renderer* rr) {
	rect.x = 250;
	rect.y = 0;
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
	surface = SDL_LoadBMP("res/player_1_right.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[4] = SDL_CreateTextureFromSurface(rr, surface);
	surface = SDL_LoadBMP("res/player_2_right.bmp");
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textures[5] = SDL_CreateTextureFromSurface(rr, surface);
	l = false;
	r = false;
	u = false;
	d = false;
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
		xVel -= xAcc;
		if(xVel <= -1 * max_x_vel) {
			xVel = -1 * max_x_vel;
		}
	}
	if(r) {
		index = 4;
		xVel += xAcc;
		if(xVel >= max_x_vel) {
			xVel = max_x_vel;
		}
	}
	if(u) {
		index = 0;
		yVel -= yAcc;
		if(yVel <= -1 * max_y_vel) {
			yVel = -1 * max_y_vel;
		}
	}
	if(d) {
		index = 0;
		yVel += yAcc;
		if(yVel >= max_y_vel) {
			yVel = max_y_vel;
		}
	}
	//continue with adding velocity to rectangles position.
	rect.x += xVel;
	rect.y += yVel;
}

void Player::render(SDL_Renderer* rr) {
	SDL_SetRenderDrawColor(rr, 0x00, 0x9F, 0x00, 0x00);
	SDL_RenderFillRect(rr, NULL);
	SDL_RenderCopy(rr, textures[index + animIndex], NULL, &rect);
}