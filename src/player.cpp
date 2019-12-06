#include "player.h"
#include <iostream>

int index = 0;
int animIndex = 0;

double millisPassed = 0.0;

Player::Player(SDL_Renderer* rr) {
	rect.x = 250;
	rect.y = 0;
	rect.w = 60;
	rect.h = 100;
	textures[0] = SDL_CreateTextureFromSurface(rr, SDL_LoadBMP("res/player_1.bmp"));
	textures[1] = SDL_CreateTextureFromSurface(rr, SDL_LoadBMP("res/player_2.bmp"));
	textures[2] = SDL_CreateTextureFromSurface(rr, SDL_LoadBMP("res/player_1_left.bmp"));
	textures[3] = SDL_CreateTextureFromSurface(rr, SDL_LoadBMP("res/player_2_left.bmp"));
	textures[4] = SDL_CreateTextureFromSurface(rr, SDL_LoadBMP("res/player_1_right.bmp"));
	textures[5] = SDL_CreateTextureFromSurface(rr, SDL_LoadBMP("res/player_2_right.bmp"));
}

void Player::update() {
	millisPassed += (1000.0 / 60.0);
	
}

void Player::render(SDL_Renderer* rr) {
	SDL_RenderCopy(rr, textures[index + animIndex], NULL, &rect);
}