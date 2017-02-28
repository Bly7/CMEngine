#pragma once

#ifndef SRENDER_H_
#define SRENDER_H_

#include <string>

#include "MessageSystem.h"

#include "Window.h"

#include "SRender_Message.h"

#include "Framework.h"
#include "Framework_Message.h"

class SRender : public ISystem
{
public:
	SRender(MessageBus* msgbus, std::string name = "Render");

	void HandleMessage(MessageBase* msg);

protected:
	Window* window_;

protected:
	void HandleRender(MessageBase* msg);

protected:
	void WindowCreate(MessageBase* msg);

	void WindowClose(MessageBase* msg);

protected:
	Framework* framework;
};

#endif // SRENDER_H_