#pragma once

#include "Entity.h"
#include "StateMachine.h"

class Plant : Entity
{
private :
	int m_capacity = 6;
	int m_ammo;

public:
	enum class State
	{
		Idle,
		Shooting,
		Reloading,

		Count
	};

private:
	StateMachine<Plant> m_stateMachine;
public :

	void OnInitialize() override;

	void OnUpdate() override;

	void Shoot();

	void Reload();

	void TryTransitionTo(State state);

	friend class IdlePlantState;
	friend class ShootingPlantState;
	friend class ReloadingPlantState;
};

