#include "GameScene.h"

#include "Plant.h"
#include "Zombie.h"
#include"Projectile.h"

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
		Projectile* tmp = CreateEntity<Projectile>(10, sf::Color::Blue);
		tmp->SetPosition(test->GetPosition(1.f, 0.5f).x, test->GetPosition(1.f, 0.5f).y);
	}
	if (event.mouseButton.button == sf::Mouse::Button::Right) {
		Zombie* tmp = CreateEntity<Zombie>(50, sf::Color::Red);
		tmp->SetPosition(event.mouseButton.x, event.mouseButton.y);
		m_zombies.push_back(tmp);
	}

	if (event.mouseButton.button == sf::Keyboard::R)
	{
		test->Reload();
	}
}
