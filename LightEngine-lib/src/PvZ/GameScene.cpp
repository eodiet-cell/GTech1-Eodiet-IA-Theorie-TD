#include "GameScene.h"

#include "Plant.h"

void GameScene::OnInitialize()
{
	test = CreateEntity<Plant>(50, sf::Color::Cyan);
	test->SetPosition(100, 100);
}

void GameScene::OnEvent(const sf::Event& event)
{
	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		test->Shoot();
	}

	if (event.mouseButton.button == sf::Keyboard::R)
	{
		test->Reload();
	}
}
