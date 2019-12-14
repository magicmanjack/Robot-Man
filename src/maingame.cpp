#include "maingame.h"
#include <cmath>
#include <iostream>
#include "player.h"
#include "view.h"
#include "map.h"

std::list<SDL_Event> MainGame::eventsQueued;
SDL_Renderer* MainGame::rr;

vPoint vp = FROM_FRONT;

Player* p;
Map* gameMap;
double vScaleFactor; // The scale factor of the map vertically.
int offsetX, offsetY;

bool enableDevInfo;

void MainGame::init(SDL_Renderer* rr) {
	MainGame::rr = rr;
	p = new Player(rr);
	gameMap = new Map(rr);
	offsetX = 0;
	offsetY = -40;
	vScaleFactor = 1; // The map will be scaled to the normal height.
	enableDevInfo = false; // Enable to show useful developer information.
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
					vp = FROM_LEFT;
					offsetX = 0;
					offsetY = -200;
					vScaleFactor = 400.0 / gameMap->h;
				}
				if(e.key.keysym.sym == SDLK_2) {
					vp = FROM_FRONT;
					offsetX = 0;
					offsetY = -40;
					vScaleFactor = 1;
					
				}
				if(e.key.keysym.sym == SDLK_3) {
					vp = FROM_RIGHT;
					offsetX = 0;
					offsetY = -200;
					vScaleFactor = 400.0 / gameMap->h;
				}
				if(e.key.keysym.sym == SDLK_BACKQUOTE) {
					enableDevInfo = !enableDevInfo; // Toggles on and off.
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
	if(vp == FROM_LEFT || vp == FROM_RIGHT) {
		p->collisionRect.y = (p->collisionRect.y) * vScaleFactor;
		p->collisionRect.h = (p->collisionRect.h) * vScaleFactor;
		p->rect.y = (p->collisionRect.y) - ((p->rect.h) - (p->collisionRect.h));
	}
	p->rect.x -= offsetX;
	p->rect.y -= offsetY;
	p->collisionRect.x -= offsetX;
	p->collisionRect.y -= offsetY;
	gameMap->mapRect.x = (gameMap->x) - offsetX;
	gameMap->mapRect.y = (gameMap->y) - offsetY;
	gameMap->mapRect.w = (gameMap->w);
	gameMap->mapRect.h = (gameMap->h) * vScaleFactor;
}

void MainGame::render() {
	gameMap->render(rr);
	if(enableDevInfo) {
		SDL_SetRenderDrawColor(rr, 0xFF, 0x00, 0x00, 0x00);
		SDL_RenderDrawRect(rr, &(p->collisionRect));
	}
	p->render(rr);
}