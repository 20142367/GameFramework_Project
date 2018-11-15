#include "Player.h"
#include "Drop.h"
#include "Trash.h"
#include "Bonus.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);

	handleInput();	// add our function

	m_currentFrame = 0;

	if (checkCollision(Player::m_rect, Drop::m_rect)) {			// drop과 충돌 시 +10점
		TheGame::Instance()->score += 10;
	}

	else if (checkCollision(Player::m_rect, Trash::m_rect)) {	// trash와 충돌 시 -10점
		TheGame::Instance()->score -= 10;
	}

	else if (checkCollision(Player::m_rect, Bonus::m_rect)) {	// bonus와 충돌 시 +20점
		TheGame::Instance()->score += 20;
	}

	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) && m_position.getX() < 540)		// 화면밖으로 이동 불가
	{
		m_velocity.setX(5);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && m_position.getX() > 0)			// 화면밖으로 이동 불가
	{
		m_velocity.setX(-5);
	}
}

void Player::setRect() {

	m_rect.x = m_position.getX();
	m_rect.y = m_position.getY();
	m_rect.w = m_width;
	m_rect.h = m_height;
}

bool Player::checkCollision(SDL_Rect a, SDL_Rect b) {

	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}