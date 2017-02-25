#pragma once

#include "MessageSystem.h"

class SMachineLearning : public ISystem
{
public:
	SMachineLearning(MessageBus* msgbus, std::string name = "Machine Learning") : ISystem(msgbus, name) {}
	void HandleMessage(MessageBase* msg)
	{
		
	}
protected:

};