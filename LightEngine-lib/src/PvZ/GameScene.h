#pragma once

#include "Scene.h"

class Plant;
class Zombie;
class Projectile;

class GameScene : public Scene
{
private :
	Plant* test;
	std::list<Zombie*> m_zombies;
	std::list<Projectile*> m_proj;
public :
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override {};
};

