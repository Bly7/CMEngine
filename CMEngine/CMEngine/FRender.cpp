#include "FRender.h"

FRender::FRender()
{
	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);
}

void FRender::Update()
{
	// For each Window
	for (int i = 0; i < window_list.size(); i++)
	{
		// Clear the window
		window_list[i]->Clear();

		// Draw what you want in window

		// Display Content
		window_list[i]->Update();
	}
}

void FRender::Cleanup()
{
	for (int i = 0; i < window_list.size(); i++)
	{
		window_list[i]->close();
		delete window_list[i];
	}

	window_list.clear();

	//Quit SDL subsystems
	SDL_Quit();
}

bool FRender::CreateWindow(std::string Title,
	int Width, int Height, int WinNumber)
{
	for (int i = 0; i < window_list.size(); i++)
	{
		if (window_list[i]->window_number_ == WinNumber)
			return false;
	}

	Window* nWindow = new Window;
	nWindow->init(Width, Height, Title);
	nWindow->window_number_ = WinNumber;
	window_list.push_back(nWindow);

	return true;
}

bool FRender::CloseWindow(int WinNumber)
{
	for (int i = 0; i < window_list.size(); i++)
	{
		if (window_list[i]->window_number_ == WinNumber)
		{
			window_list[i]->close();
			window_list.erase(window_list.begin() + i);
			return true;
		}
	}

	return false;
}