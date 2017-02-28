#include "SRender.h"

SRender::SRender(MessageBus* msgbus, std::string name)
	: ISystem(msgbus, name)
{
	window_ = NULL;
}

void SRender::HandleMessage(MessageBase* msg)
{
	if (msg->type >= REN_ENUM_START && msg->type <= REN_ENUM_END)
		HandleRender(msg);

	if (msg->type == FW_SET)
	{
		MsgFramework* fwmsg = dynamic_cast<MsgFramework*>(msg);
		if (fwmsg)
		{
			framework = fwmsg->framework;
		}
	}



}

void SRender::HandleRender(MessageBase* msg)
{
	switch (msg->type)
	{
		case REN_WINDOWCREATE:
		{
			WindowCreate(msg);
			break;
		}
		case REN_WINDOWCLOSE:
		{
			WindowClose(msg);
			break;
		}
		case REN_WINDOWUPDATE:
		{
			break;
		}
		default:
			break;
	}
}

void SRender::WindowCreate(MessageBase* msg)
{
	MsgRenWinConstruct* mrwc = dynamic_cast<MsgRenWinConstruct*>(msg);

	if (!mrwc)
	{
		message_bus->AddMessage(genMessageBase(name_, "Invalid Window Create Message."));
		mrwc = NULL;
		return;
	}

	bool success = framework->
		GetRender()->CreateWindow(mrwc->title,
			mrwc->width, mrwc->height, mrwc->num);

	if (success)
	{
		message_bus->AddMessage(genMessageBase(name_, "Window " + std::to_string(mrwc->num) + " Created."));
	}
	else
	{
		message_bus->AddMessage(genMessageBase(name_, "Window Number Already Exists."));
	}
}

void SRender::WindowClose(MessageBase* msg)
{
	MsgRenWinClose* mrwc = dynamic_cast<MsgRenWinClose*>(msg);

	if (!mrwc)
	{
		message_bus->AddMessage(genMessageBase(name_, "Invalid Window Close Message."));
		mrwc = NULL;
		return;
	}

	bool success = framework->GetRender()->CloseWindow(mrwc->num);
	if (success)
	{
		message_bus->AddMessage(genMessageBase(name_, "Window " + std::to_string(mrwc->num) + " Closed."));
	}
	else
	{
		message_bus->AddMessage(genMessageBase(name_, "No Window To Close."));
	}
}