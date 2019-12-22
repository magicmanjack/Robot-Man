#include <SDL.h>

class Truck {
	public:
		double xPos;
		double yPos;
		int w;
		int h;
		//^^ Information about the position and dimensions of the truck.
		
		double xVel;
		double yVel;
		
		SDL_Rect rect; // Rect that is used for drawing.
		
		SDL_Texture* textures[8]; // Textures of the truck. (Left, right, up, down + extra animation textures).
		
		Truck(SDL_Renderer* rr);
		
		void update();
		void render(SDL_Renderer* rr);
};