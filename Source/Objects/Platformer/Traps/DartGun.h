#pragma once

#include "Engine/Hackables/HackableObject.h"

namespace cocos2d
{
	class Sprite;
}

class HackableData;
class SmartAnimationNode;

class DartGun : public HackableObject
{
public:
	static DartGun* create(cocos2d::ValueMap* initProperties);

	static const std::string MapKeyDartGun;

protected:
	DartGun(cocos2d::ValueMap* initProperties);
	~DartGun();

	cocos2d::Vec2 getButtonOffset() override;

private:
	typedef HackableObject super;
	void registerHackables();
	void onEnter() override;
	void initializePositions() override;
	void update(float) override;
	void shoot(float angle);

	SmartAnimationNode* dartGunAnimations;
};