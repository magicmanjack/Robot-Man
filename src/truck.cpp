#include "truck.h"
#include "view.h"
#include <cmath>

Truck::Truck(SDL_Renderer* rr) {
	xPos = 0;
	yPos = 0;
	w = 60;
	h = 60;
	
	rect.x = xPos;
	rect.y = yPos;
	rect.w = w;
	rect.h = h;
	
} 

void Truck::update() {
	xPos += xVel;
	yPos += yVel;
	if(vp == FROM_LEFT) {
		rect.x = round(yPos);
		rect.y = round((600.0 - xPos) - w);
		rect.w = h;
		rect.h = w;
	} else if(vp == FROM_FRONT) {
		rect.x = round(xPos);
		rect.y = round(yPos);
		rect.w = w;
		rect.h = h;
	} else if(vp == FROM_RIGHT) {
		rect.x = round((600.0 - yPos) - h);
		rect.y = round(xPos);
		rect.w = h;
		rect.h = w;
	}
}

void Truck::render(SDL_Renderer* rr) {
	SDL_SetRenderDrawColor(rr, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderFillRect(rr, &rect);
}