#include "Enemy.h"
#include <stdlib.h>

Enemy::Enemy()
	: Character(rand() % 4, rand() % 4)
{

}

Enemy::~Enemy()
{

}