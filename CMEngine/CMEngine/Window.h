#pragma once

#ifndef WINDOW_H_
#define WINDOW_H_

#include <string>

#include <SDL/SDL.h>

class Window
{
public:
	Window();
	bool init(int width, int height, std::string title);
	void close();

	void Clear();
	void Update();

public:
	int window_number_;
protected:
	SDL_Window* sdl_window_;

	SDL_Surface* sdl_surface_screen_;

	int width_;
	int height_;
};

#endif