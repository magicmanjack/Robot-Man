#include "maingame.h"
#include <cmath>
#include <iostream>
#include "player.h"

std::list<SDL_Event> MainGame::eventsQueued;
SDL_Renderer* MainGame::rr;

enum ViewAngle {FROM_LEFT_SIDE, FROM_FRONT, FROM_RIGHT_SIDE};
ViewAngle vAngle;

Player* p;
bool l, r, u, d;

void MainGame::init(SDL_Renderer* rr) {
	MainGame::rr = rr;
	p = new Player(rr);
	l = false;
	r = false;
	u = false;
	d = false;
	vAngle = FROM_FRONT;
}

void MainGame::update() {
	while(!eventsQueued.empty()) {
		SDL_Event e = *(eventsQueued.begin());
			if(e.type == SDL_KEYDOWN) {
				if(e.key.keysym.sym == SDLK_a) {
					l = true;
				}
				if(e.key.keysym.sym == SDLK_d) {
					r = true;
				}
				if(e.key.keysym.sym == SDLK_w) {
					u = true;
				}
				if(e.key.keysym.sym == SDLK_s) {
					d = true;
				}
			}
			if(e.type == SDL_KEYUP) {
				if(e.key.keysym.sym == SDLK_a) {
					l = false;
				}
				if(e.key.keysym.sym == SDLK_d) {
					r = false;
				}
				if(e.key.keysym.sym == SDLK_w) {
					u = false;
				}
				if(e.key.keysym.sym == SDLK_s) {
					d = false;
				}
			}
		eventsQueued.pop_front();
	}
	p->update();
}

void MainGame::render() {
	p->render(rr);
}