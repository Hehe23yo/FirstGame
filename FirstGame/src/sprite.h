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
	double updateSpritelocation(double deltaTime);
	void handleEvents(SDL_Event const &event);

	enum class direction
	{
		NONE,
		UP,
		DOWN,
		RIGHT,
		LEFT
	};

private:
	direction m_direction;

	double imageX = 515;
	double imageY = 640;
};



