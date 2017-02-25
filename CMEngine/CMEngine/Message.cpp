#include "Message.h"

void MessageBase::remove()
{
	delete(this);
}

MessageBase* genMessageBase(std::string from,
	std::string note,
	int type)
{
	MessageBase* msg = new MessageBase;

	msg->from = from;
	msg->type = type;
	msg->note = note;

	return msg;
}