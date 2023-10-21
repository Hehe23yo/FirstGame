#include "sprite.h"


sprite::sprite()
{

}

sprite::~sprite()
{

}

SDL_Surface* sprite::loadSprite(char const* path)
{
	SDL_Surface* optImage = nullptr;

	SDL_Surface* image = SDL_LoadBMP(path);
	if(!image)
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


