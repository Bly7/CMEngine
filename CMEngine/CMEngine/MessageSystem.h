#pragma once

#ifndef MESSAGESYSTEM_H_
#define MESSAGESYSTEM_H_

#include <vector>
#include <string>
#include <map>

#include "Message.h"

class MessageBus
{
private:
	std::vector<class ISystem *> systems;
	std::vector<MessageBase*> crnt_msgs;
	std::vector<MessageBase*> new_msgs;
public:
	MessageBus();

	void Attach(ISystem *sys);
	void AddMessage(MessageBase *msg);
	void AddImmediateMessage(MessageBase *msg);
	void Update();
};

class ISystem
{
protected:
	MessageBus* message_bus;
	std::string name_;

public:
	ISystem(MessageBus* msgbus, std::string name = "Unnamed");

	virtual void HandleMessage(MessageBase* msg) = 0;
};


#endif // MESSAGESYSTEM_H_