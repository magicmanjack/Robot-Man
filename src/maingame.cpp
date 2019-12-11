#include "maingame.h"
#include <cmath>
#include <iostream>
#include "player.h"

std::list<SDL_Event> MainGame::eventsQueued;
SDL_Renderer* MainGame::rr;

Player* p;
int offsetX, offsetY;
SDL_Rect mapRect;

void MainGame::init(SDL_Renderer* rr) {
	MainGame::rr = rr;
	p = new Player(rr);
	offsetX = 0;
	offsetY = -40;
	//
	mapRect.x = 0;
	mapRect.y = 0;
	mapRect.w = 600;
	mapRect.h = 600;
	//defining shape and size of map
}

void MainGame::update() {
	while(!eventsQueued.empty()) {
		SDL_Event e = *(eventsQueued.begin());
			if(e.type == SDL_KEYDOWN) {
				if(e.key.keysym.sym == SDLK_a) {
					p->l = true;
				}
				if(e.key.keysym.sym == SDLK_d) {
					p->r = true;
				}
				if(e.key.keysym.sym == SDLK_w) {
					p->u = true;
				}
				if(e.key.keysym.sym == SDLK_s) {
					p->d = true;
				}
				if(e.key.keysym.sym == SDLK_SPACE) {
					p->flying = true;
				}
				if(e.key.keysym.sym == SDLK_1) {
					p->vp = Player::FROM_LEFT;
					offsetY = 0;
					offsetX = 0;
				}
				if(e.key.keysym.sym == SDLK_2) {
					p->vp = Player::FROM_FRONT;
					offsetX = 0;
					offsetY = -40;
				}
				if(e.key.keysym.sym == SDLK_3) {
					p->vp = Player::FROM_RIGHT;
					offsetY = 0;
					offsetX = 0;
				}
			}
			if(e.type == SDL_KEYUP) {
				if(e.key.keysym.sym == SDLK_a) {
					p->l = false;
				}
				if(e.key.keysym.sym == SDLK_d) {
					p->r = false;
				}
				if(e.key.keysym.sym == SDLK_w) {
					p->u = false;
				}
				if(e.key.keysym.sym == SDLK_s) {
					p->d = false;
				}
				if(e.key.keysym.sym == SDLK_SPACE) {
					p->flying = false;
				}
			}
		eventsQueued.pop_front();
	}
	p->update();
	p->rect.x -= offsetX;
	p->rect.y -= offsetY;
	p->collisionRect.x -= offsetX;
	p->collisionRect.y -= offsetY;
	mapRect.x = 0 - offsetX;
	mapRect.y = 0 - offsetY;
}

void MainGame::render() {
	SDL_SetRenderDrawColor(rr, 0x00, 0x9F, 0x00, 0x00);
	SDL_RenderFillRect(rr, &mapRect);
	p->render(rr);
}