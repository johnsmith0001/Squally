#pragma once

#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/CardData/CardData.h"

using namespace cocos2d;

class EnvironmentHexStorm : public CardData
{
public:
	EnvironmentHexStorm();
	~EnvironmentHexStorm();

private:
	static const std::string StringKeyCardName;
};
