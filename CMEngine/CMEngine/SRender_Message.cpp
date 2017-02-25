#include "SRender_Message.h"

MessageBase* genMRWC(std::string from, std::string title, int width, int height,
	std::string note)
{
	MsgRenWinConstruct* msg = new MsgRenWinConstruct;

	msg->from = from;
	msg->type = REN_WINDOWCREATE;
	
	msg->title = title;
	msg->width = width;
	msg->height = height;

	msg->note = note;

	if (note != "")
		return msg;


	msg->note = "Create New Window : " + title
		+ " W: " + std::to_string(width) + " H: " + std::to_string(height);

	return msg;
}