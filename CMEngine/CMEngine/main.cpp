
#include <conio.h>

#include "MessageSystem.h"
#include "SConsole.h"
#include "SRender.h"
#include "SSettings.h"

#include <SDL/SDL.h>


int main(int argc, char* argv[])
{

	MessageBus mb;
	SSettings set(&mb);
	SConsole con(&mb);
	SRender ren(&mb);

	mb.AddMessage(genMRWC("Game Loop", "Test Window"));
		
	mb.AddMessage(genMCMI("Game Loop", CON_ADDIGNORE, REN_WINDOWUPDATE));

	int frames = 0;

	bool running = true;

	while (running)
	{
		if ((SDL_GetTicks() / 1000) >= 5)
		{
			running = false;

			mb.AddMessage(genMessageBase("Game Loop", "Close Window.", REN_WINDOWCLOSE));
		}

		
		mb.AddMessage(genMessageBase("Game Loop", "Update Window.", REN_WINDOWUPDATE));

		mb.Update();
		frames++;
	}



	mb.Update();

	_getch();

	return 0;
}