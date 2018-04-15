#include "OrcWarrior.h"

OrcWarrior* OrcWarrior::create()
{
	OrcWarrior* instance = new OrcWarrior();

	instance->autorelease();

	return instance;
}

OrcWarrior::OrcWarrior() : Enemy::Enemy(
	Resources::Entities_Environment_Lava_BossDemonKing_Animations,
	"BossDemonKing",
	false)
{
}

OrcWarrior::~OrcWarrior()
{
}
