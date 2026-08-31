#include "Game2D.h"

void Game2D::gameInit()
{
	m_camera.toggleMovement(false);

	m_sprite_factory.addCopyObject(Object(Transform({0.f, 0.f, -10.f}), default_square, Material(default_shader)));
	m_sprite_factory.addObjectList(m_object_list);

	default_shader->init("Data/shaders/vertex/sprite.vert", "Data/shaders/fragment/default_lit.frag");
	default_shader->setProjection(m_window->getProjection());

	test_sprite = &m_sprite_factory.create();
}

void Game2D::update(float dt)
{
	debug_window.addText("Sprite Position: %.1f %.1f", test_sprite->transform.position);

	if (Key<GLFW_KEY_A>::pressed())
	{
		test_sprite->transform.Move(1.0f, 0.f, 0.f);
	}
}

void Game2D::preRender()
{

}

void Game2D::postRender()
{

}

void Game2D::addKeys()
{
	Key<GLFW_KEY_A>::addWindow(m_window);
}
