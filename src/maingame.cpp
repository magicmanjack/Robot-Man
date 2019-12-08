#include "maingame.h"
#include <cmath>
#include <iostream>
#include "player.h"

std::list<SDL_Event> MainGame::eventsQueued;
SDL_Renderer* MainGame::rr;

enum ViewAngle {FROM_LEFT_SIDE, FROM_FRONT, FROM_RIGHT_SIDE};
ViewAngle vAngle;

Player* p;

void MainGame::init(SDL_Renderer* rr) {
	MainGame::rr = rr;
	p = new Player(rr);
	vAngle = FROM_FRONT;
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
}

void MainGame::render() {
	p->render(rr);
}