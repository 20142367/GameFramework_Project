#include "Drop.h"
#include "InputHandler.h"

Drop::Drop(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Drop::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Drop::update()
{
	if (Drop::Level == 1)
	{
		m_velocity.setX(0);
		m_velocity.setY(1);
	}
	else if (Drop::Level == 2)
	{
		m_velocity.setX(0);
		m_velocity.setY(3);
	}
	else if (Drop::Level == 3)
	{
		m_velocity.setX(0);
		m_velocity.setY(6);
	}

	handleInput();	// add our function

	m_currentFrame = 0;


	SDLGameObject::update();
}

void Drop::clean()
{
}

void Drop::handleInput() {
}

void Drop::setRect() {

	m_rect.x = m_position.getX();
	m_rect.y = m_position.getY();
	m_rect.w = m_width;
	m_rect.h = m_height;
}