#include "renderer.h"

renderer::renderer(SDL_Window* window)
{
	m_windowRenderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);
	if (!m_windowRenderer)
	{
		std::cout << "Failed to create Renderer object!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
	}
	m_image = spaceship.loadSprite("../Sprites/BMP/fighter_plane1.bmp");
	
	m_texture = SDL_CreateTextureFromSurface(m_windowRenderer, m_image);
	if (!m_texture)
	{
		std::cout << "Failed to create texture!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
	}

	m_imageTransform.h = 70;
	m_imageTransform.w = 100;
	m_imageTransform.x = 515;
	m_imageTransform.y = 670;
}

renderer::~renderer()
{
	SDL_DestroySurface(m_image);
	SDL_DestroyTexture(m_texture);
}

void renderer::renderSprite()
{
	SDL_RenderClear(m_windowRenderer);
	SDL_RenderTexture(m_windowRenderer, m_texture, NULL, &m_imageTransform);
	SDL_RenderPresent(m_windowRenderer);
}

void renderer::handleEvents(SDL_Event const& event)
{
	spaceship.handleEvents(event);
}

void renderer::update(double deltaTime)
{
	m_imageTransform.x = spaceship.updateSpritelocation(deltaTime);
}

