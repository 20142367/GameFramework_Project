#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"
#include "Enemy.h"
#include "Drop.h"
#include "Trash.h"
#include "Bonus.h"
#include <vector>

using namespace std;

class Game
{
	
public:
	vector<GameObject*> m_gameObjects;
	vector<Drop*> m_drop;

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	bool running() { return m_bRunning; }

	int score = 0;

	static Game* Instance();

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	void DropItem(int xpos, int ypos);

private:
	Game() {};

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_RendererFlip* m_pRendererFlip;

	int m_currentFrame;
	TextureManager* m_textureManager;

	bool m_bRunning;

	// create the s_pInstance member variable
	static Game* s_pInstance;

	float coolTime = 2000.0f;
	Uint32 start = 0;
	Uint32 current = 0;

	int a = 0;
	int k = m_gameObjects.size() - a;
};
// create the typedef
typedef Game TheGame;