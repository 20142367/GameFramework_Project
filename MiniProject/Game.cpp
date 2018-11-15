#include "Game.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {


	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, false);

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true;

		// load 부분 대치
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}

		if (!TheTextureManager::Instance()->load("assets/player.png", "player", m_pRenderer)) {

			return false;
		}

		if (!TheTextureManager::Instance()->load("assets/back.png", "background", m_pRenderer)) {

			return false;
		}

		if (!TheTextureManager::Instance()->load("assets/drop.png", "drop", m_pRenderer)) {		// 기본 오브젝트

			return false;
		}

		if (!TheTextureManager::Instance()->load("assets/trash.png", "trash", m_pRenderer)) {	// 마이너스 오브젝트

			return false;
		}

		if (!TheTextureManager::Instance()->load("assets/bonus.png", "bonus", m_pRenderer)) {	// 보너스 오브젝트

			return false;
		}

		m_gameObjects.push_back(new Player(new LoaderParams(200, 340, 100, 100, "player")));

		m_gameObjects.push_back(new Drop(new LoaderParams(100, -100, 32, 32, "drop")));
		m_gameObjects.push_back(new Trash(new LoaderParams(179, -100, 32, 32, "trash")));
		m_gameObjects.push_back(new Bonus(new LoaderParams(463, -100, 32, 32, "bonus")));
		//m_gameObjects.push_back(new Drop(new LoaderParams(45, -100, 32, 32, "drop")));
		//m_gameObjects.push_back(new Drop(new LoaderParams(187, -100, 32, 32, "drop")));
		//m_gameObjects.push_back(new Drop(new LoaderParams(88, -100, 32, 32, "drop")));
		//m_gameObjects.push_back(new Drop(new LoaderParams(0, -100, 32, 32, "drop")));
		//m_gameObjects.push_back(new Drop(new LoaderParams(478, -100, 32, 32, "drop")));
		//m_gameObjects.push_back(new Drop(new LoaderParams(167, -100, 32, 32, "drop")));
		//m_gameObjects.push_back(new Drop(new LoaderParams(100, -100, 32, 32, "drop")));
		//m_gameObjects.push_back(new Drop(new LoaderParams(200, -100, 32, 32, "drop")));
		//m_gameObjects.push_back(new Drop(new LoaderParams(123, -100, 32, 32, "drop")));
		//m_gameObjects.push_back(new Drop(new LoaderParams(300, -100, 32, 32, "drop")));
		//m_gameObjects.push_back(new Drop(new LoaderParams(500, -100, 32, 32, "drop")));
/*
		start = SDL_GetTicks();

		if (start - current < coolTime)
		{
			TheGame::DropItem(100, -100);
			current = SDL_GetTicks();
		}*/

		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	}
	else
	{
		return false;
	}

	return true;
}

void Game::render() {

	// draw color로 render 지우기
	SDL_RenderClear(m_pRenderer);

	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	//if (current - start < coolTime)
	//{
	//	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	//	{
	//		m_gameObjects[i]->draw();

	//	}
	//	current = SDL_GetTicks();
	//}
/*
	if (start - current < coolTime)
	{
		for (vector<Drop*>::size_type i = 0; i != m_gameObjects.size(); i++)
		{
			m_drop[i]->draw();
		}
		current = SDL_GetTicks();
	}*/

	// 화면 제시
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {

	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		m_gameObjects[i]->update();
}

void Game::clean() {
	
	cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents() {

	TheInputHandler::Instance()->update();
}

Game *Game::Instance() {

	if (s_pInstance == 0) {

		s_pInstance = new Game();
		return s_pInstance;
	}
	return s_pInstance;
}

void Game::quit()
{
	m_bRunning = false;
}

void Game::DropItem(int xpos, int ypos) {

	m_gameObjects.push_back(new Drop(new LoaderParams(xpos, ypos, 32, 32, "drop")));
}