#include "Window.h"

Window::Window()
{
	sdl_window_ = NULL;
	sdl_surface_screen_ = NULL;
	window_number_ = -1;

	readytoclose = false;
}

bool Window::init(int width, int height, std::string title)
{
	bool success = true;
	width_ = width;
	height_ = height;

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
}

void Window::Clear()
{

}

void Window::Update()
{
	SDL_UpdateWindowSurface(sdl_window_);
}

void Window::HandleEvents()
{
	// Get window ID
	int WindowID = SDL_GetWindowID(sdl_window_);

	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_WINDOWEVENT && e.window.windowID == WindowID)
		{
			switch (e.window.event)
			{
				// Window Appeared
			case SDL_WINDOWEVENT_SHOWN:
				break;
				// Window Disappeared
			case SDL_WINDOWEVENT_HIDDEN:
				break;
				// Get new dimensions and repaint
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				break;
				// Repaint on expose
			case SDL_WINDOWEVENT_EXPOSED:
				break;
				// Mouse enter
			case SDL_WINDOWEVENT_ENTER:
				break;
				// Mouse exit
			case SDL_WINDOWEVENT_LEAVE:
				break;
				// Keyboard focus gained
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				break;
				// Keyboard focus lost
			case SDL_WINDOWEVENT_FOCUS_LOST:
				break;
				// Window minimized
			case SDL_WINDOWEVENT_MINIMIZED:
				break;
				// Window maximized
			case SDL_WINDOWEVENT_MAXIMIZED:
				break;
				// Window restored
			case SDL_WINDOWEVENT_RESTORED:
				break;
				// Window close
			case SDL_WINDOWEVENT_CLOSE:
				readytoclose = true;
				break;
			}
		}
	}
}

bool Window::IsReadyToClose()
{
	return readytoclose;
}