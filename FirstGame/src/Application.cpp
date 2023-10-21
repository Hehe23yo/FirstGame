#include "Application.h"

Application::Application()
{
	m_window = SDL_CreateWindow("Chicken Invaders", 1900, 1000, 0);
	if (!m_window)
	{
		std::cout << "Failed to create a window!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
	}
}

Application::~Application()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Application::loop()
{
	bool keepWindowOpen = true;
	while (keepWindowOpen)
	{
		while (SDL_PollEvent(&m_event) > 0)
		{

			switch (m_event.type)
			{
			case SDL_EVENT_QUIT:
				keepWindowOpen = false;
				break;
			}
		}
		draw();
	}
}

void Application::draw()
{
	render.renderSprite();
}