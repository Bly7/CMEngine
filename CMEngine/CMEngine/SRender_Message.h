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
	int num = 0;
};

struct MsgRenWinClose : public MessageBase
{
	int num = 0;
};

MessageBase* genMRWC(std::string from,
	std::string title = "Default Window", int num = 0,
	int width = 800, int height = 600,
	std::string note = "");

MessageBase* genMRWClose(std::string from, int num,
	std::string note = "");

#endif // SRENDER_MESSAGE_H_