#pragma once

#include "../../Dependencies.h"

#include "../Window/Window.h"

class Debugger
{
public:

	Debugger() = default;
	Debugger(const std::string &name = "");
	~Debugger();

	void init(Window &window);

	void startFrame();
	void renderFrame();

	template<typename... Args>
	void addText(const std::string &format, Args... args);


private:

	std::string m_name = "";

};
