#include "Window.h"

Window::Window()
{
	sdl_window_ = NULL;
	sdl_surface_screen_ = NULL;
}

bool Window::init(int width, int height, std::string title)
{
	bool success = true;
	width_ = width;
	height_ = height;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		success = false;
	}
	else
	{
		sdl_window_ = SDL_CreateWindow(title.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width_,
			height_,
			SDL_WINDOW_SHOWN);

		if (sdl_window_ == NULL)
			success = false;
		else
			sdl_surface_screen_ = SDL_GetWindowSurface(sdl_window_);
	}

	return success;
}

void Window::close()
{
	//Deallocate surface
	SDL_FreeSurface(sdl_surface_screen_);
	sdl_surface_screen_ = NULL;

	//Destroy window
	SDL_DestroyWindow(sdl_window_);
	sdl_window_ = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void Window::update()
{
	SDL_UpdateWindowSurface(sdl_window_);
}