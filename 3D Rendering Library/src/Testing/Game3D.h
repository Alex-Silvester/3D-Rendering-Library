#pragma once

#include "../Engine/Game.h"

class Game3D : public Game
{
private:

	void gameInit()      override;
	void update(float dt)override;
	void preRender()     override;
	void postRender()    override;

private:

	Object *test_object = nullptr;
	Object *transparent_object = nullptr;
	Object *textured_object = nullptr;
	Object *model_mesh_test = nullptr;

	std::shared_ptr<Light> light = std::make_shared<Light>();

	Model test_model;

	Skybox skybox;
};