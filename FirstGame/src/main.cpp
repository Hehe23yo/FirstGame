#include <iostream>
#include "SDL3/SDL.h"

int main()
{
	SDL_Window* m_window = SDL_CreateWindow("yo", 800, 400, 0);
	if (!m_window)
		std::cout << "Failed to create window!" << std::endl;
	else
		std::cout << "Successful!" << std::endl;
}