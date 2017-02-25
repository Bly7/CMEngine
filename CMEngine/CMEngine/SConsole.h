#pragma once

#ifndef SCONSOLE_H_
#define SCONSOLE_H_

#include <iostream>
#include <vector>
#include <string>

#include "MessageSystem.h"
#include "SConsole_Message.h"

class SConsole : public ISystem
{
public:
	SConsole(MessageBus* msgbus, std::string name = "Console");

	void HandleMessage(MessageBase* msg);

protected:
	std::vector<std::string> Messages;

protected:
	void HandleModification(MessageBase* msg);

	void HandleModS(int type, std::string mod);
	void HandleModI(int type, int mod);
	
protected:
	void PrintMessage(MessageBase* msg);

protected:
	void AddIgnore(std::string newignore);
	void AddIgnore(int newignore);

	void RemoveIgnore(std::string oldignore);
	void RemoveIgnore(int oldignore);

	bool IsIgnore(MessageBase* msg);

	std::vector<std::string> Ignore;
	std::vector<int> IgnoreType;
};

#endif // SCONSOLE_H_