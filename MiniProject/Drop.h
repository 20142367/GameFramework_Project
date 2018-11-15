#pragma once
#include "SDLGameObject.h"

class Drop : public SDLGameObject
{
public:

	Drop(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void setRect();

	int Level = 1;

	static SDL_Rect drect;


private:
	void handleInput();

};
