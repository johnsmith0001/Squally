#pragma once

#include "Engine/Hackables/HackableObject.h"

namespace cocos2d
{
	class Sprite;
}

class LocalizedLabel;
class LocalizedString;

class RegisterCrystal : public HackableObject
{
protected:
	RegisterCrystal(cocos2d::ValueMap& initProperties);
	~RegisterCrystal();

	void onEnter() override;
	void initializePositions() override;
	void buildMovString(LocalizedString* registerString);
	void buildMovPtrString(LocalizedString* registerString);
	int getValue();
	int getOffset();

	static const std::string MapKeyRegisterOffset;
	static const std::string MapKeyRegisterValue;

	cocos2d::Node* crystalNode;
	LocalizedString* assemblyString;

private:
	typedef HackableObject super;

	int value;
	int offset;

	cocos2d::Sprite* shadow;
	LocalizedLabel* assemblyLabel;
};
