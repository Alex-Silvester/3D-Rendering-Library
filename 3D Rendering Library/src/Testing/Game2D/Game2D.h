#pragma once

#include "../../Engine/Game.h"

class Game2D : public Game
{
private:

	void gameInit()      override;
	void update(float dt)override;
	void preRender()     override;
	void postRender()    override;

};