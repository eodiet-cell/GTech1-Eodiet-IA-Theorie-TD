#include "main.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"

#include <cstdlib>
#include <crtdbg.h>
#include "GameScene.h"

int main()
{
	GameManager* pInstance = GameManager::Get();

	pInstance->CreateWindow(1280, 720, "Game", 60, sf::Color::Black);

	pInstance->LaunchScene<GameScene>();

	return 0;
}