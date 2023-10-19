#pragma once
#include <SDL.h>
#include "Constants.h"
#include "CalculateNext.h"


class Window
{
public:
	Window(std::array<std::array<bool, width>, height>& prev);
	~Window();
private:
	void Render(std::array<std::array<bool, width>, height>& rend);
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Event e;
	bool exit = false, buttondown = false;
	int mouseX = 0, mouseY = 0;
	uint64_t timer = 0, prevTimer = 0;
	uint32_t deltaTime = 0, counter = 0;

};

