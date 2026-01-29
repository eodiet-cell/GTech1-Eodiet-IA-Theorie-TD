#pragma once

#include "Entity.h"

class Zombie : public Entity
{
private :
	int m_hp;

public :
	void OnInitialize() override;

	void OnCollision(Entity* other) override;
};

