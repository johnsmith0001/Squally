#pragma once

#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/CardData/CardData.h"

using namespace cocos2d;

class Decimal12 : public CardData
{
public:
	Decimal12();
	~Decimal12();

private:
	static const std::string StringKeyCardName;
};
