#include "PlantState.h"

#include "Plant.h"

bool IdlePlantState::CanTransitionFrom(Plant* plant, int currentState)
{
	switch ((Plant::State)currentState)
	{
	case Plant::State::Idle: 
		return false;
	}

	return true;
}

void ShootingPlantState::Start(Plant* plant)
{
	m_timer = m_duration;
	plant->m_ammo--;
}

void ShootingPlantState::Update(Plant* plant, float dt)
{
	m_timer -= dt;

	if (m_timer > 0)
		return;

	plant->TryTransitionTo(Plant::State::Idle);
}

bool ShootingPlantState::CanTransitionFrom(Plant* plant, int currentState)
{
	switch ((Plant::State)currentState)
	{
	case Plant::State::Shooting:
		return false;
	case Plant::State::Reloading:
		return false;
	}

	if (plant->m_ammo <= 0)
		return false;

	return true;
}

void ReloadingPlantState::Start(Plant* plant)
{
	m_timer = m_duration;
}

void ReloadingPlantState::Update(Plant* plant, float dt)
{
	m_timer -= dt;

	if (m_timer > 0)
		return;

	plant->m_ammo = plant->m_capacity;

	plant->TryTransitionTo(Plant::State::Idle);
}

bool ReloadingPlantState::CanTransitionFrom(Plant* plant, int currentState)
{
	switch ((Plant::State)currentState)
	{
	case Plant::State::Shooting:
		return false;
	case Plant::State::Reloading:
		return false;
	}

	if (plant->m_ammo >= plant->m_capacity)
		return false;

	return true;
}
