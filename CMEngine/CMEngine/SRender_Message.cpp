#include "SRender_Message.h"

MessageBase* genMRWC(std::string from, std::string title, int num, int width, int height,
	std::string note)
{
	MsgRenWinConstruct* msg = new MsgRenWinConstruct;

	msg->from = from;
	msg->type = REN_WINDOWCREATE;
	
	msg->title = title;
	msg->width = width;
	msg->height = height;
	msg->num = num;

	msg->note = note;

	if (note != "")
		return msg;


	msg->note = "Create New Window : " + title + " N: " + std::to_string(num) +
		+ " W: " + std::to_string(width) + " H: " + std::to_string(height);

	return msg;
}

MessageBase* genMRWClose(std::string from, int num,
	std::string note)
{
	MsgRenWinClose* msg = new MsgRenWinClose;

	msg->type = REN_WINDOWCLOSE;
	msg->from = from;
	msg->num = num;

	msg->note = note;

	if (note != "")
		return msg;

	msg->note = "Window " + std::to_string(num) + " Close.";

	return msg;
}