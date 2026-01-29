#include "Zombie.h"
#include "Projectile.h"

void Zombie::OnInitialize()
{
	m_hp = 6;
	
	SetDirection(-1.f, 0.f, 10);
}

void Zombie::OnCollision(Entity* other)
{
	if (Projectile* proj = dynamic_cast<Projectile*>(other)) {
		m_hp--;
		proj->Destroy();
		if (m_hp <= 0) {
			Destroy();
		}
	}
}
