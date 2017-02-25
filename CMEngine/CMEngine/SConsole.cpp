#include "SConsole.h"

SConsole::SConsole(MessageBus* msgbus,
	std::string name) 
	: ISystem(msgbus, name)
{
	
}

void SConsole::HandleMessage(MessageBase* msg)
{
	// If this message is not on the ignore list
	if (!IsIgnore(msg))
	{
		// Print Message
		PrintMessage(msg);
	}

	// Handle Modification if the message type pertains to the console
	if (msg->type >= CON_ENUM_START && msg->type <= CON_ENUM_END)
		HandleModification(msg);
}

void SConsole::HandleModification(MessageBase* msg)
{
	// Try to cast to mcms
	MsgConModS* mcms = dynamic_cast<MsgConModS*>(msg);
	if (mcms)
	{
		HandleModS(mcms->type, mcms->data);
		mcms = NULL;
		return;
	}

	// If it wasn't that try to cast to mcmi
	MsgConModI* mcmi = dynamic_cast<MsgConModI*>(msg);
	if (mcmi)
	{
		HandleModI(mcmi->type, mcmi->data);
		mcmi = NULL;
		return;
	}
}

void SConsole::HandleModS(int type, std::string mod)
{
	switch (type)
	{
	case CON_ADDIGNORE:
		AddIgnore(mod);
		break;
	case CON_REMOVEIGNORE:
		RemoveIgnore(mod);
		break;
	}
}

void SConsole::HandleModI(int type, int mod)
{
	switch (type)
	{
	case CON_ADDIGNORE:
		AddIgnore(mod);
		break;
	case CON_REMOVEIGNORE:
		RemoveIgnore(mod);
		break;
	}
}

void SConsole::PrintMessage(MessageBase* msg)
{
	// Create Message From - note
	std::string consoleprint = "";

	if (msg->from != "")
		consoleprint += msg->from;

	if (msg->from == "")
		consoleprint += "Unkown";

	if (!msg->note.empty())
		consoleprint += " - " + msg->note;

	// Print Message
	std::cout << consoleprint << std::endl;

	// Save Message in array
	Messages.push_back(consoleprint);
}

void SConsole::AddIgnore(std::string newignore)
{
	for (int i = 0; i < Ignore.size(); i++)
	{
		if (Ignore[i] == newignore)
		{
			message_bus->AddMessage(genMessageBase(name_,
				"Ignore \"" + newignore + "\" Exists."));

			return;
		}
	}

	Ignore.push_back(newignore);
	message_bus->AddMessage(genMessageBase(name_,
		"Ignore \"" + newignore + "\" Added."));
}

void SConsole::AddIgnore(int newignore)
{
	for (int i = 0; i < IgnoreType.size(); i++)
	{
		if (IgnoreType[i] == newignore)
		{
			message_bus->AddMessage(genMessageBase(name_,
				"Ignore \"" + std::to_string(newignore) + "\" Exists."));

			return;
		}
	}

	IgnoreType.push_back(newignore);

	message_bus->AddMessage(genMessageBase(name_,
		"Ignore \"" + std::to_string(newignore) + "\" Added."));
}

void SConsole::RemoveIgnore(std::string oldignore)
{
	for (int i = 0; i < Ignore.size(); i++)
	{
		if (Ignore[i] == oldignore)
		{
			Ignore.erase(Ignore.begin() + i);

			message_bus->AddMessage(genMessageBase(name_,
				"Ignore \"" + oldignore + "\" Removed."));

			return;
		}
	}

	message_bus->AddMessage(genMessageBase(name_,
		"Ignore \"" + oldignore + "\" Not Found."));
}

void SConsole::RemoveIgnore(int oldignore)
{
	for (int i = 0; i < IgnoreType.size(); i++)
	{
		if (IgnoreType[i] == oldignore)
		{
			IgnoreType.erase(IgnoreType.begin() + i);

			message_bus->AddMessage(genMessageBase(name_,
				"Ignore \"" + std::to_string(oldignore) + "\" Removed."));

			return;
		}
	}

	message_bus->AddMessage(genMessageBase(name_,
		"Ignore \"" + std::to_string(oldignore) + "\" Not Found."));
}

bool SConsole::IsIgnore(MessageBase* msg)
{
	for (int i = 0; i < Ignore.size(); i++)
	{
		if (msg->from == Ignore[i])
			return true;
	}

	for (int i = 0; i < IgnoreType.size(); i++)
	{
		if (msg->type == IgnoreType[i])
			return true;
	}

	return false;
}