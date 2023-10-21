#pragma once

// Clip Rendering - https://lazyfoo.net/tutorials/SDL/11_clip_rendering_and_sprite_sheets/index.php

#include "sprite.h"

class renderer
{
public:
	renderer(SDL_Window* window);
	~renderer();

	void renderSprite();
private:
	sprite spaceship;

	SDL_Renderer* m_windowRenderer;
	SDL_Surface* m_image;
	SDL_Texture* m_texture;
	SDL_Rect m_imageRect;
};

