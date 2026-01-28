#include "Plant.h"
#include "PlantState.h"

void Plant::OnInitialize()
{
	m_ammo = m_capacity;

	m_stateMachine.Add(new IdlePlantState());
	m_stateMachine.Add(new ShootingPlantState());
	m_stateMachine.Add(new ReloadingPlantState());
}

void Plant::OnUpdate()
{
	m_stateMachine.Update(this, GetDeltaTime());
}

void Plant::Shoot()
{
	TryTransitionTo(State::Shooting);
}

void Plant::Reload()
{
	TryTransitionTo(State::Reloading);
}

void Plant::TryTransitionTo(State state)
{
	m_stateMachine.TryTransitionTo(this, (int)state);
}
