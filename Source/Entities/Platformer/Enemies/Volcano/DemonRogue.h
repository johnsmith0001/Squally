#pragma once
#include "cocos2d.h"

#include "Entities/Platformer/PlatformerEnemy.h"
#include "Resources.h"

using namespace cocos2d;

class DemonRogue : public PlatformerEnemy
{
public:
	static DemonRogue * deserialize(ValueMap* initProperties);

	static const std::string KeyEnemyDemonRogue;

private:
	DemonRogue(ValueMap* initProperties);
	~DemonRogue();
};