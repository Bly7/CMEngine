#pragma once

#include <vector>
#include <string>
#include <map>

#include <glm/vec2.hpp>

enum MsgType
{
	// Default
	NOTYPE,

	// Console Types
	CON_ENUM_START,

	CON_ADDIGNORE,
	CON_REMOVEIGNORE,

	CON_ENUM_END,


	// Render Types
	REN_ENUM_START,

	REN_WINDOWCREATE,
	REN_WINDOWCLOSE,
	REN_WINDOWUPDATE,

	REN_ENUM_END,

	//  Framework Types
	FW_SET
};

struct MessageBase
{
	std::string from;
	int type;
	std::string note;

	void remove();

protected:
	virtual ~MessageBase() {}
};

MessageBase* genMessageBase(std::string from = "",
							std::string note = "",
							int type = NOTYPE);