#pragma once
#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

using namespace cocos2d;

class HexusOpponentIceGolem : public HexusOpponentData
{
public:
	static HexusOpponentIceGolem* getInstance();

private:
	HexusOpponentIceGolem();
	~HexusOpponentIceGolem();

	static const std::string StringKeyOpponentName;
	static HexusOpponentIceGolem* instance;
};