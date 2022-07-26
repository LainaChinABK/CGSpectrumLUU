#include "Enemy.h"
#include <time.h>

Enemy::Enemy()
	: Character()
{
	m_minDamage = 4;
	m_maxDamage = 7;

	srand(time(NULL));
	SetWeapon(rand() % 3);
	SetArmor(rand() % 3);
}

Enemy::~Enemy()
{

}