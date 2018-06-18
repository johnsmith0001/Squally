#pragma once
#include "cocos2d.h"

#include "Entities/Enemy.h"
#include "Resources.h"

using namespace cocos2d;

class EntMage : public Enemy
{
public:
	static EntMage * deserialize(ValueMap* initProperties);

	static const std::string KeyEnemyEntMage;

private:
	EntMage(ValueMap* initProperties);
	~EntMage();
};
