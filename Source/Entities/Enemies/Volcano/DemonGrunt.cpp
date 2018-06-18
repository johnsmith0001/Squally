#include "DemonGrunt.h"

const std::string DemonGrunt::KeyEnemyDemonGrunt = "demon_grunt";

DemonGrunt* DemonGrunt::deserialize(ValueMap* initProperties)
{
	DemonGrunt* instance = new DemonGrunt(initProperties);

	instance->autorelease();

	return instance;
}

DemonGrunt::DemonGrunt(ValueMap* initProperties) : Enemy(initProperties,
	Resources::Entities_Environment_Volcano_DemonGrunt_Animations,
	false,
	Size(312.0f, 372.0f),
	0.7f,
	Vec2(0.0f, 0.0f))
{
}

DemonGrunt::~DemonGrunt()
{
}
