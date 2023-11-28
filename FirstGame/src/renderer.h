#pragma once

// Clip Rendering - https://lazyfoo.net/tutorials/SDL/11_clip_rendering_and_sprite_sheets/index.php

#include "sprite.h"

class renderer
{
public:
	renderer(SDL_Window* window);
	~renderer();

	void renderSprite();
	void selectSprite();
	void handleEvents(SDL_Event const &event);
	void update(double deltaTime);
	void renderBullets(SDL_FRect coods);
	bool bulletHitCheck(const SDL_FRect *coods);
	void destroyBullet(const SDL_FRect *coods);
	void destroyEnemy(const SDL_FRect* enemy);

private:
	sprite spaceship;
	sprite minotaur;
	sprite projectile;

	SDL_Renderer* m_windowRenderer;

	SDL_Surface* m_spaceship;
	SDL_Surface* m_minotaur;

	SDL_Texture* m_textureChar;
	SDL_Texture* m_textureEnemy;

	SDL_FRect m_imageTransform;
	SDL_FRect m_enemyLocation;
	SDL_FRect m_selectedSpriteEnemy;

	int columnEnemy;
	double dt;
	int count;
	int c;
	std::vector<SDL_FRect> m_magic;
};

