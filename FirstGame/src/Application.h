#pragma once

#include "SDL3/SDL.h"
#include <iostream>
#include "renderer.h"

class Application
{
public:
	Application();
	~Application();

	void loop();
	void update();
	void draw();

private:
	SDL_Window* m_window;
	SDL_Event m_event;

	renderer render = {m_window};
};

