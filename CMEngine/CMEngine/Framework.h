#pragma once

#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#include "FRender.h"

#include "MessageSystem.h"

class Framework
{
public:
	Framework();

	void Update();

	void Cleanup();

public:
	FRender* GetRender();
protected:
	FRender* render;
};

#endif