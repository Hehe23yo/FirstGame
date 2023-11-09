#pragma once

#include "SDL3/SDL.h"
#include "SDL3/SDL_image.h"
#include <iostream>
#include <vector>

class sprite
{
public:
	sprite();
	~sprite();

	SDL_Surface* loadSprite(int bmpCheck, char const* path);
	double updateSpritelocation(double deltaTime);
	
	void handleEvents(SDL_Event const &event);
	void handleEvents(SDL_Event const& event, const SDL_FRect *imageTransform);

	bool isShooting();
	void setShooting(bool value);
	

	enum class direction
	{
		NONE,
		UP,
		DOWN,
		RIGHT,
		LEFT,
		SHOOT
	};

	std::vector<SDL_FRect> bullets;

private:
	direction m_direction;

	int flags;
	int initializedFlags;

	double imageX;
	double imageY;

	bool shooting;

	
};



