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
			WindowClose();
			break;
		}
		case REN_WINDOWUPDATE:
		{
			WindowUpdate();
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

	if (window_ == NULL)
	{
		window_ = new Window;
		window_->init(mrwc->width,
					  mrwc->height,
					  mrwc->title);

		message_bus->AddMessage(genMessageBase(name_, "Window \"" + mrwc->title + "\" Created."));
	}
	else
	{
		message_bus->AddMessage(genMessageBase(name_, "Window Already Exists."));
	}
}

void SRender::WindowClose()
{
	if (window_ != NULL)
	{
		window_->close();
		message_bus->AddMessage(genMessageBase(name_, "Window Closed."));
	}
	else
	{
		message_bus->AddMessage(genMessageBase(name_, "No Window To Close."));
	}
}

void SRender::WindowUpdate()
{
	if (window_ != NULL)
		window_->update();
}