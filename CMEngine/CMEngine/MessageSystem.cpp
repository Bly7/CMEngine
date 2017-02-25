#include "MessageSystem.h"

MessageBus::MessageBus()
{
	AddMessage(genMessageBase("Message Bus", "Message Bus Created."));
}

void MessageBus::Attach(ISystem *sys)
{
	systems.push_back(sys);
}

void MessageBus::AddMessage(MessageBase *msg)
{
	new_msgs.push_back(msg);
}

ISystem::ISystem(MessageBus* msgbus, std::string name)
{
	message_bus = msgbus;
	message_bus->Attach(this);

	message_bus->AddMessage(genMessageBase(name, name + " System Connected"));

	name_ = name;
}

void MessageBus::Update()
{
	// Add new messages to current pool
	for (int i = 0; i < new_msgs.size(); i++)
	{
		crnt_msgs.push_back(new_msgs[i]);
	}

	// Clear new messages
	new_msgs.clear();

	// Go through each system and handle the messages
	for (int sysnum = 0; sysnum < int(systems.size()); sysnum++)
	{
		for (int msgnum = 0; msgnum < int(crnt_msgs.size()); msgnum++)
		{
			systems[sysnum]->HandleMessage(crnt_msgs[msgnum]);
		}
	}

	// Have all current messages remove themselves
	for (int msgnum = 0; msgnum < int(crnt_msgs.size()); msgnum++)
	{
		crnt_msgs[msgnum]->remove();
	}

	// Clear current messages
	crnt_msgs.clear();

}

void MessageBus::AddImmediateMessage(MessageBase *msg)
{
	// Go through each system and handle the message
	for (int sysnum = 0; sysnum < int(systems.size()); sysnum++)
	{
		systems[sysnum]->HandleMessage(msg);
	}

	msg->remove();
}