#include "Framework.h"

Framework::Framework()
{
	render = new FRender;
}

void Framework::Update()
{
	render->Update();
}

void Framework::Cleanup()
{
	render->Cleanup();
	delete render;
}

FRender* Framework::GetRender()
{
	return render;
}