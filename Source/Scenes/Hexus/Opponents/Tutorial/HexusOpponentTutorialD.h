#pragma once
#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

using namespace cocos2d;

class HexusOpponentTutorialD : public HexusOpponentData
{
public:
	static HexusOpponentTutorialD* getInstance();

private:
	HexusOpponentTutorialD();
	~HexusOpponentTutorialD();

	static const std::string StringKeyOpponentName;
	static HexusOpponentTutorialD* instance;
};