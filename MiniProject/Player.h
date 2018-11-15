#pragma once
#include "SDLGameObject.h"
#include "Game.h"

class Player : public SDLGameObject
{
public :

	Player(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void setRect();

	SDL_Rect prect;


private :
	void handleInput();
	bool checkCollision(SDL_Rect a, SDL_Rect b);

};