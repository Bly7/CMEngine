#pragma once

#ifndef FRAMEWORK_MESSAGE_H_
#define FRAMEWORK_MESSAGE_H_

#include "Message.h"

#include "Framework.h"

#include <string>

struct MsgFramework : public MessageBase
{
	Framework* framework;
};

MessageBase* genFWMsg(std::string from,
	Framework* framework);

#endif // FRAMEWORK_MESSAGE_H_