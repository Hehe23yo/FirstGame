#include "Application.h"

Application::Application()
{
	//m_window = SDL_CreateWindow("Chicken Invaders", 1100, 800, 0);
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
			render.handleEvents(m_event);
			switch (m_event.type)
			{
			case SDL_EVENT_QUIT:
				keepWindowOpen = false;
				break;
			}
		}
		update(1 / 60.0);
		draw();
	}
}

void Application::update(double deltaTime)
{
	render.update(deltaTime);
}

void Application::draw()
{
	render.renderSprite();
}