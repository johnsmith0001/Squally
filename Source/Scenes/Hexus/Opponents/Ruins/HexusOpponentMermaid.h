#pragma once
#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

using namespace cocos2d;

class HexusOpponentMermaid : public HexusOpponentData
{
public:
	static HexusOpponentMermaid* getInstance();

private:
	HexusOpponentMermaid();
	~HexusOpponentMermaid();

	static const std::string OpponentSaveKey;
	static HexusOpponentMermaid* instance;
};