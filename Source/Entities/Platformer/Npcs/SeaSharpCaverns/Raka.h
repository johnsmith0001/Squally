#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class HexusOpponentData;
class LocalizedString;

class Raka : public PlatformerFriendly
{
public:
	static Raka* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKey;

protected:
	Raka(cocos2d::ValueMap& properties);
	virtual ~Raka();

private:
	typedef PlatformerFriendly super;

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
