#pragma once

#include "Scene.h"

class Plant;

class GameScene : public Scene
{
private :
	Plant* test;
public :
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override {};
};

