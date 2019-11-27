#include <sdl.h>

#ifndef _MAP_H_INCLUDED_
#define _MAP_H_INCLUDED_

class Map {
	public:
		enum viewAngle {FromLeft, FromFront, FromRight};
		viewAngle vw;
		
		Map() {
			vw = FromFront;	
		}
		
		void Render(SDL_Renderer * r);
		
		
};

#endif