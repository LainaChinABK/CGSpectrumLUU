#include "Enemy.h"
#include <iostream>
#include <time.h>

Enemy::Enemy()
	: Character()
{
	srand(time(NULL));
	SetWeapon(rand() % 4);
	SetArmor(rand() % 4);
}

Enemy::~Enemy()
{

}