#include <algorithm>

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

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			/*minotaur.enemy[10 * j + i].x = i * 100.0;
			minotaur.enemy[10 * j + i].y = j * 100.0;
			minotaur.enemy[10 * j + i].h = 200.0;
			minotaur.enemy[]*/
			/*m_enemyLocation[10 * j + i].x = i * 100.0;
			m_enemyLocation[10 * j + i].y = j * 100.0;
			m_enemyLocation[10 * j + i].h = 200.0;
			m_enemyLocation[10 * j + i].w = 200.0;*/
			m_enemyLocation.x = i * 100.0;
			m_enemyLocation.y = j * 100.0;
			m_enemyLocation.h = 200.0;
			m_enemyLocation.w = 200.0;

			minotaur.enemy.push_back(m_enemyLocation);
		}
	}
	
	/*m_projectile.x = m_imageTransform.x + 32 + 20;
	m_projectile.y = m_imageTransform.y;
	m_projectile.h = 10;
	m_projectile.w = 10;*/

	/*m_enemyLocation[0].x = 0;
	m_enemyLocation[0].y = 0;
	m_enemyLocation[0].h = 200;
	m_enemyLocation[0].w = 200;

	m_enemyLocation[1].x = 60;
	m_enemyLocation[1].y = 0;
	m_enemyLocation[1].h = 200;
	m_enemyLocation[1].w = 200;

	m_enemyLocation[2].x = 120;
	m_enemyLocation[2].y = 0;
	m_enemyLocation[2].h = 200;
	m_enemyLocation[2].w = 200;

	m_enemyLocation[3].x = 180;
	m_enemyLocation[3].y = 0;
	m_enemyLocation[3].h = 200;
	m_enemyLocation[3].w = 200;

	m_enemyLocation[4].x = 240;
	m_enemyLocation[4].y = 0;
	m_enemyLocation[4].h = 200;
	m_enemyLocation[4].w = 200;

	m_enemyLocation[5].x = 300;
	m_enemyLocation[5].y = 0;
	m_enemyLocation[5].h = 200;
	m_enemyLocation[5].w = 200;

	m_enemyLocation[6].x = 360;
	m_enemyLocation[6].y = 0;
	m_enemyLocation[6].h = 200;
	m_enemyLocation[6].w = 200;

	m_enemyLocation[7].x = 420;
	m_enemyLocation[7].y = 0;
	m_enemyLocation[7].h = 200;
	m_enemyLocation[7].w = 200;

	m_enemyLocation[8].x = 480;
	m_enemyLocation[8].y = 0;
	m_enemyLocation[8].h = 200;
	m_enemyLocation[8].w = 200;

	m_enemyLocation[9].x = 540;
	m_enemyLocation[9].y = 0;
	m_enemyLocation[9].h = 200;
	m_enemyLocation[9].w = 200;*/
	
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
	
	

	//if (projectile.isShooting())
	//{
	//	//std::cout << "car" << std::endl;
	//	SDL_SetRenderDrawColor(m_windowRenderer, 0, 0, 0, 255);
	//	SDL_RenderFillRect(m_windowRenderer, &m_projectile);
	//}

	/*for (int i = 0; i < 30; i++)
	{
		SDL_RenderTexture(m_windowRenderer, m_textureEnemy, &m_selectedSprite, &minotaur.enemy[i]);
	}*/

	for (auto& b : minotaur.enemy)
	{
		SDL_RenderTexture(m_windowRenderer, m_textureEnemy, &m_selectedSprite, &b);
	}
	//std::cout << "min" << std::endl;
	/*SDL_RenderTexture(m_windowRenderer, m_textureEnemy, &m_selectedSprite, &m_enemyLocation[0]);
	SDL_RenderTexture(m_windowRenderer, m_textureEnemy, &m_selectedSprite, &m_enemyLocation[1]);
	SDL_RenderTexture(m_windowRenderer, m_textureEnemy, &m_selectedSprite, &m_enemyLocation[2]);
	SDL_RenderTexture(m_windowRenderer, m_textureEnemy, &m_selectedSprite, &m_enemyLocation[3]);
	SDL_RenderTexture(m_windowRenderer, m_textureEnemy, &m_selectedSprite, &m_enemyLocation[4]);
	SDL_RenderTexture(m_windowRenderer, m_textureEnemy, &m_selectedSprite, &m_enemyLocation[5]);
	SDL_RenderTexture(m_windowRenderer, m_textureEnemy, &m_selectedSprite, &m_enemyLocation[6]);
	SDL_RenderTexture(m_windowRenderer, m_textureEnemy, &m_selectedSprite, &m_enemyLocation[7]);
	SDL_RenderTexture(m_windowRenderer, m_textureEnemy, &m_selectedSprite, &m_enemyLocation[8]);
	SDL_RenderTexture(m_windowRenderer, m_textureEnemy, &m_selectedSprite, &m_enemyLocation[9]);*/
	

	for (auto &b : projectile.bullets)
	{
		std::cout << b.x << " " << b.y << std::endl;
		if(bulletHitCheck(&b))
		{
			std::cout << "HIT!" << std::endl;
			destroyBullet(&b);
		}
		renderBullets(b);
	}
	SDL_RenderPresent(m_windowRenderer);
}

void renderer::renderBullets(SDL_FRect coods)
{
	
	SDL_SetRenderDrawColor(m_windowRenderer, 0, 0, 0, 255);
	SDL_RenderFillRect(m_windowRenderer, &coods);
}

bool renderer::bulletHitCheck(const SDL_FRect *coods)
{
	/*for (int i = 0; i < 30; i++)
	{
		if (coods->y > minotaur.enemy[i].y && coods->y <= (minotaur.enemy[i].y + minotaur.enemy[i].h - 20))
		{
			if (coods->x > (minotaur.enemy[i].x + 35) && coods->x < (minotaur.enemy[i].x + minotaur.enemy[i].w - 35))
			{
				minotaur.enemy[i].h = 0;
				minotaur.enemy[i].w = 0;
				return true;
			}
		}
	}*/

	for (auto& e : minotaur.enemy)
	{
		if (coods->y > e.y && coods->y <= (e.y + e.h - 20))
		{
			if (coods->x > (e.x + 35) && coods->x < (e.x + e.w - 35))
			{
				destroyEnemy(&e);
				return true;
			}
		}
	}

	return false;
}

void renderer::destroyBullet(const SDL_FRect *coods)
{
	//projectile.bullets.erase(std::find(projectile.bullets.begin(), projectile.bullets.end(), coods));
	auto i = std::remove_if(projectile.bullets.begin(), projectile.bullets.end(), 
		[&](SDL_FRect s) {return (s.x == coods->x && s.y == coods->y); });
	if (i != projectile.bullets.end())
	{
		projectile.bullets.erase(i);
	}
	//projectile.bullets.erase(std::remove(projectile.bullets.begin(), projectile.bullets.end(), coods), projectile.bullets.end());
}

void renderer::destroyEnemy(const SDL_FRect *enemy)
{
	auto i = std::remove_if(minotaur.enemy.begin(), minotaur.enemy.end(),
		[&](SDL_FRect s) {return (s.x == enemy->x && s.y == enemy->y); });
	if (i != minotaur.enemy.end())
	{
		minotaur.enemy.erase(i);
	}
}

void renderer::handleEvents(SDL_Event const& event)
{
	spaceship.handleEvents(event);
	projectile.handleEvents(event, &m_imageTransform);
}

void renderer::update(double deltaTime)
{
	m_imageTransform.x = spaceship.updateSpritelocation(deltaTime);

	m_selectedSprite.x = column * m_selectedSprite.w;
	
	/*if (projectile.isShooting())
	{
		m_projectile.y -= 6;
	}*/

	for (auto& b : projectile.bullets)
	{
		b.y -= 6.0;
	}

	for (auto& e : minotaur.enemy)
	{
		e.y += 6;
	}

	/*for (int i = 0; i < 30; i++)
	{
		minotaur.enemy[i].y += 6;
	}*/

	

	/*m_enemyLocation[0].y += 6;
	m_enemyLocation[1].y += 6;
	m_enemyLocation[2].y += 6;
	m_enemyLocation[3].y += 6;
	m_enemyLocation[4].y += 6;
	m_enemyLocation[5].y += 6;
	m_enemyLocation[6].y += 6;
	m_enemyLocation[7].y += 6;
	m_enemyLocation[8].y += 6;
	m_enemyLocation[9].y += 6;*/

	column++;

	if (column > 8)
		column = 1;
	
}

