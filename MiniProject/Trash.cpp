#include "Trash.h"
#include "InputHandler.h"

Trash::Trash(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Trash::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Trash::update()
{
	m_velocity.setX(0);
	m_velocity.setY(1);

	handleInput();	// add our function

	m_currentFrame = 0;


	SDLGameObject::update();
}

void Trash::clean()
{
}

void Trash::handleInput() {
}

void Trash::setRect() {

	m_rect.x = m_position.getX();
	m_rect.y = m_position.getY();
	m_rect.w = m_width;
	m_rect.h = m_height;
}