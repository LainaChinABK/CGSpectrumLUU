#include "Enemy.h"

Enemy::Enemy()
	: Character()
{
	SetWeapon(rand() % 3);
	SetArmor(rand() % 3);
}

Enemy::~Enemy()
{

}