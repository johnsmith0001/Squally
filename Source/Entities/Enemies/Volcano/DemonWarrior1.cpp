#include "DemonWarrior1.h"

DemonWarrior1* DemonWarrior1::create()
{
	DemonWarrior1* instance = new DemonWarrior1();

	instance->autorelease();

	return instance;
}

DemonWarrior1::DemonWarrior1() : Enemy::Enemy(
	Resources::Entities_Environment_Lava_BossDemonKing_Animations,
	"BossDemonKing",
	false)
{
}

DemonWarrior1::~DemonWarrior1()
{
}
