#pragma once

#include "Objects/Platformer/Breakables/CagedAnimals/CagedAnimal.h"

namespace cocos2d
{
	class Sprite;
};

class CagedBunny : public CagedAnimal
{
public:
	static CagedBunny* create(cocos2d::ValueMap& initProperties);

	static const std::string MapKeyCagedBunny;

protected:
	CagedBunny(cocos2d::ValueMap& initProperties);
	virtual ~CagedBunny();

	void initializePositions() override;

private:
	typedef CagedAnimal super;

	cocos2d::Sprite* animalSprite;
};