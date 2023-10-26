#pragma once

#include "SDL3/SDL.h"
#include "SDL3/SDL_image.h"
#include <iostream>

class sprite
{
public:
	sprite();
	~sprite();

	SDL_Surface* loadSprite(int bmpCheck, char const* path);
	void selectSprite(int x, int y);
	double updateSpritelocation(double deltaTime);
	void handleEvents(SDL_Event const &event);
	bool isShooting();

	enum class direction
	{
		NONE,
		UP,
		DOWN,
		RIGHT,
		LEFT,
		SHOOT
	};

private:
	direction m_direction;

	int flags;
	int initializedFlags;

	double imageX;
	double imageY;

	bool shooting;
};



