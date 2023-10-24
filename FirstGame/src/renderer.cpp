#include "renderer.h"

renderer::renderer(SDL_Window* window)
{
	m_windowRenderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);
	if (!m_windowRenderer)
	{
		std::cout << "Failed to create Renderer object!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
	}
	m_spaceship = spaceship.loadSprite(1, "../Sprites/BMP/fighter_plane1.bmp");
	m_minotaur = minotaur.loadSprite(0, "../Sprites/Other/Minotaur.png");
	
	m_textureChar = SDL_CreateTextureFromSurface(m_windowRenderer, m_spaceship);
	m_textureEnemy = SDL_CreateTextureFromSurface(m_windowRenderer, m_minotaur);

	if (!m_textureChar || !m_textureEnemy)
	{
		std::cout << "Failed to create texture!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
	}

	m_imageTransform.h = 70;
	m_imageTransform.w = 100;
	m_imageTransform.x = 515;
	m_imageTransform.y = 670;

	column = 1;

	m_selectedSprite.h = m_minotaur->h / 11;
	m_selectedSprite.w = m_minotaur->w / 9;
	m_selectedSprite.x = 1 * m_selectedSprite.w;
	m_selectedSprite.y = 4 * m_selectedSprite.h;

	/*std::cout << m_selectedSprite.h << std::endl;
	std::cout << m_selectedSprite.w << std::endl;
	std::cout << m_selectedSprite.x << std::endl;
	std::cout << m_selectedSprite.y << std::endl;
	SDL_Delay(1000000);*/

	m_enemyLocation.x = 0;
	m_enemyLocation.y = 0;
	m_enemyLocation.h = 200;
	m_enemyLocation.w = 200;
	
}

renderer::~renderer()
{
	SDL_DestroySurface(m_spaceship);
	SDL_DestroyTexture(m_textureChar);
}

void renderer::renderSprite()
{
	SDL_SetRenderDrawColor(m_windowRenderer, 255, 255, 255, 255);
	SDL_RenderClear(m_windowRenderer);
	SDL_RenderTexture(m_windowRenderer, m_textureChar, NULL, &m_imageTransform);
	SDL_RenderTexture(m_windowRenderer, m_textureEnemy, &m_selectedSprite, &m_enemyLocation);
	SDL_RenderPresent(m_windowRenderer);
}

void renderer::handleEvents(SDL_Event const& event)
{
	spaceship.handleEvents(event);
}

void renderer::update(double deltaTime)
{
	m_imageTransform.x = spaceship.updateSpritelocation(deltaTime);

	m_selectedSprite.x = column * m_selectedSprite.w;
	m_enemyLocation.y += 6;
	column++;

	if (column > 8)
		column = 1;

	
}

