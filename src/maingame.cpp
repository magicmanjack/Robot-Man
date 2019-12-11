#include "maingame.h"
#include <cmath>
#include <iostream>
#include "player.h"

std::list<SDL_Event> MainGame::eventsQueued;
SDL_Renderer* MainGame::rr;

Player* p;
int mapOffsetX, mapOffsetY;
SDL_Rect mapRect;

void MainGame::init(SDL_Renderer* rr) {
	MainGame::rr = rr;
	p = new Player(rr);
	mapOffsetX = 0;
	mapOffsetY = -40;
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
					
				}
				if(e.key.keysym.sym == SDLK_2) {
					
				}
				if(e.key.keysym.sym == SDLK_3) {
					
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
	p->rect.x -= mapOffsetX;
	p->rect.y -= mapOffsetY;
	
	mapRect.x = 0 - mapOffsetX;
	mapRect.y = 0 - mapOffsetY;
}

void MainGame::render() {
	SDL_SetRenderDrawColor(rr, 0x00, 0x9F, 0x00, 0x00);
	SDL_RenderFillRect(rr, &mapRect);
	p->render(rr);
}