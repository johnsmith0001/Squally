#pragma once
#include "cocos2d.h"

#include "Entities/Platformer/PlatformerEnemy.h"
#include "Resources.h"

using namespace cocos2d;

class SkeletonKnight : public PlatformerEnemy
{
public:
	static SkeletonKnight * deserialize(ValueMap* initProperties);

	static const std::string KeyEnemySkeletonKnight;

private:
	SkeletonKnight(ValueMap* initProperties);
	~SkeletonKnight();
};