#pragma once

#ifndef SCONSOLE_MESSAGE_H_
#define SCONSOLE_MESSAGE_H_

#include "Message.h"

struct MsgConModS : public MessageBase
{
	std::string data = "";
};

struct MsgConModI : public MessageBase
{
	int data = -1;
};

MessageBase* genMCMS(std::string from, int type,
					 std::string data, std::string note = "");

MessageBase* genMCMI(std::string from, int type,
					 int data, std::string note = "");

#endif // SCONOSLE_MESSAGE_H_