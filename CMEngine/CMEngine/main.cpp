
#include <conio.h>

#include "MessageSystem.h"
#include "SConsole.h"
#include "SRender.h"
#include "SSettings.h"

#include "Framework.h"

#include <SDL/SDL.h>


int main(int argc, char* argv[])
{

	MessageBus mb;
	SSettings set(&mb);
	SConsole con(&mb);
	SRender ren(&mb);

	Framework fw;
	mb.AddMessage(genFWMsg("Game Loop", &fw));
	mb.AddMessage(genMRWC("Game Loop", "Test Window", 0));
	
	mb.AddMessage(genMCMI("Game Loop", CON_ADDIGNORE, REN_WINDOWUPDATE));

	int frames = 0;

	bool running = true;

	//Event handler
	SDL_Event e;

	while (running)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				running = false;

				mb.AddMessage(genMRWClose("Game Loop", 0));
			}
		}

		
		mb.Update();

		fw.Update();

		frames++;
	}

	mb.Update();

	fw.Cleanup();

	return 0;
}