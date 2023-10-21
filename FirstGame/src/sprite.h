#pragma once

#include "SDL3/SDL.h"
#include <iostream>

class sprite
{
public:
	sprite();
	~sprite();

	SDL_Surface* loadSprite(char const* path);
	void selectSprite();
	void updateSpritelocation();
	void handleEvents();

};



