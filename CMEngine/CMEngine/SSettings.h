#pragma once

#ifndef SSETTINGS_H_
#define SSETTINGS_H_

#include "MessageSystem.h"

class SSettings : public ISystem
{
public:
	SSettings(MessageBus* msgbus, std::string name = "Settings");

	void HandleMessage(MessageBase* msg);

protected:

};

#endif