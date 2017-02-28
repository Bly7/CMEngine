#pragma once

#ifndef FRENDERING_H_
#define FRENDERING_H_

#include <string>
#include <vector>

#include "Window.h"

class FRender
{
public:
	FRender();

	void Update();

	void Cleanup();

public:
	bool CreateWindow(std::string Title,
		int Width, int Height, int WinNumber);

	bool CloseWindow(int WinNumber);

protected:
	std::vector<Window*> window_list;
};

#endif // FRENDERING_H_