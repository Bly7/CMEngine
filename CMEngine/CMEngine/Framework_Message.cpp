#include "Framework_Message.h"

MessageBase* genFWMsg(std::string from,
	Framework* framework)
{
	MsgFramework* newmsg = new MsgFramework;

	newmsg->from = from;
	newmsg->framework = framework;
	newmsg->type = FW_SET;
	newmsg->note = "Set Framework.";

	return newmsg;
}