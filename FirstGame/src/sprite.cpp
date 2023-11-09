#include "sprite.h"


sprite::sprite()
{
	imageX = 500;
	imageY = 640;
}

sprite::~sprite()
{

}

SDL_Surface* sprite::loadSprite(int bmpCheck, char const* path)
{
	if(bmpCheck == 1)
	{
		SDL_Surface* optImage = nullptr;

		SDL_Surface* image = SDL_LoadBMP(path);
		if (!image)
		{
			std::cout << "Failed to load image!" << std::endl;
			std::cout << "SDL Error : " << SDL_GetError() << std::endl;
		}

		optImage = SDL_ConvertSurface(image, image->format);
		if (!optImage)
		{
			std::cout << "Failed to load optimized image!" << std::endl;
			std::cout << "SDL Error : " << SDL_GetError() << std::endl;
		}

		SDL_DestroySurface(image);

		return optImage;
	}
	else
	{
		flags = IMG_INIT_JPG | IMG_INIT_PNG;
		initializedFlags = IMG_Init(flags);

		if ((flags & initializedFlags) != flags)
		{
			std::cout << "Failed to initialize image flags!" << std::endl;
			std::cout << "SDL Error :" << SDL_GetError() << std::endl;
		}

		SDL_Surface* image = IMG_Load(path);
		
		return image;
	}

}

void sprite::handleEvents(SDL_Event const& event)
{
	Uint8 const* key;
	switch (event.type)
	{
	case SDL_EVENT_KEY_DOWN:
		key = SDL_GetKeyboardState(nullptr);

		if (key[SDL_SCANCODE_W] == 1)
			m_direction = direction::UP;
		else if (key[SDL_SCANCODE_S] == 1)
			m_direction = direction::DOWN;
		else if (key[SDL_SCANCODE_A] == 1)
			m_direction = direction::LEFT;
		else if (key[SDL_SCANCODE_D] == 1)
			m_direction = direction::RIGHT;
		break;
	case SDL_EVENT_KEY_UP:
		m_direction = direction::NONE;
	}
}

void sprite::handleEvents(SDL_Event const& event, const SDL_FRect *imageTransform)
{
	Uint8 const* key;
	switch (event.type)
	{
	case SDL_EVENT_KEY_DOWN:
		key = SDL_GetKeyboardState(nullptr);

		if (key[SDL_SCANCODE_SPACE] == 1)
		{
			SDL_FRect bullet;
			bullet.x = imageTransform->x + (imageTransform->w / 2.0) - 10;
			bullet.y = imageTransform->y;
			bullet.h = 20.0;
			bullet.w = 20.0;

			bullets.push_back(bullet);
		}
		break;
	}
	
}

double sprite::updateSpritelocation(double deltaTime)
{
	switch (m_direction)
	{
	case direction::NONE:
		imageX += 0.0;
		imageY += 0.0;
		break;
	case direction::RIGHT:
		if(imageX < 850)
			imageX += 4000 * deltaTime;
		break;
	case direction::LEFT:
		if(imageX > 50)
			imageX -= 4000 * deltaTime;
		break;
	/*case direction::SHOOT:
		shooting = true;
		std::cout << shooting << std::endl;
		break;*/
	}

	return imageX;
}

bool sprite::isShooting()
{
	return shooting;
}

void sprite::setShooting(bool value)
{
	shooting = value;
}
