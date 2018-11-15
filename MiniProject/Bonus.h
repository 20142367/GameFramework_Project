#pragma once
#include "SDLGameObject.h"

class Bonus : public SDLGameObject
{
public:

	Bonus(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void setRect();

	SDL_Rect brect;

private:
	void handleInput();


};
