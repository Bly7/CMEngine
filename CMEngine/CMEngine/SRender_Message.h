#pragma once

#ifndef SRENDER_MESSAGE_H_
#define SRENDER_MESSAGE_H_

#include "Message.h"

#include <string>
#include <iostream>

struct MsgRenWinConstruct : public MessageBase
{
	std::string title = "Default Window";
	int width = 800;
	int height = 600;
};

MessageBase* genMRWC(std::string from,
	std::string title = "Default Window",
	int width = 800, int height = 600,
	std::string note = "");

#endif // SRENDER_MESSAGE_H_