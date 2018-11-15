#include "Bonus.h"
#include "InputHandler.h"

Bonus::Bonus(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Bonus::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Bonus::update()
{

	m_velocity.setX(0);
	m_velocity.setY(1);


	handleInput();	// add our function

	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));

	SDLGameObject::update();
}

void Bonus::clean()
{
}

void Bonus::handleInput() {
}

void Bonus::setRect() {

	m_rect.x = m_position.getX();
	m_rect.y = m_position.getY();
	m_rect.w = m_width;
	m_rect.h = m_height;
}