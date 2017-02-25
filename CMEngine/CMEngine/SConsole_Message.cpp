#include "SConsole_Message.h"

MessageBase* genMCMS(std::string from, int type,
					 std::string data, std::string note)
{
	MsgConModS* msg = new MsgConModS;
	msg->from = from;
	msg->type = type;
	msg->data = data;

	msg->note = note;

	if (note != "")
		return msg;

	if (type == CON_ADDIGNORE)
		msg->note += "Console Add Ignore : " + data;

	if (type == CON_REMOVEIGNORE)
		msg->note += "Console Remove Ignore : " + data;

	return msg;
}

MessageBase* genMCMI(std::string from, int type,
					 int data, std::string note)
{
	MsgConModI* msg = new MsgConModI;
	msg->from = from;
	msg->type = type;
	msg->data = data;

	msg->note = note;

	if (note != "")
		return msg;

	if (type == CON_ADDIGNORE)
		msg->note += "Console Add Ignore : " + std::to_string(data);

	if (type == CON_REMOVEIGNORE)
		msg->note += "Console Remove Ignore : " + std::to_string(data);

	return msg;
}