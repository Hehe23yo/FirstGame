#include "renderer.h"

renderer::renderer(SDL_Window* window)
{
	m_windowRenderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);
	m_image = spaceship.loadSprite("../Sprites/BMP/fighter_plane1.bmp");
	
	m_texture = SDL_CreateTextureFromSurface(m_windowRenderer, m_image);
	if (!m_texture)
	{
		std::cout << "Failed to create texture!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
	}
}

renderer::~renderer()
{
	SDL_DestroySurface(m_image);
	SDL_DestroyTexture(m_texture);
}

void renderer::renderSprite()
{
	SDL_RenderClear(m_windowRenderer);
	SDL_RenderTexture(m_windowRenderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_windowRenderer);
}

