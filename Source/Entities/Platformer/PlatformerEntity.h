#pragma once

#include "cocos/math/CCGeometry.h"

#include "Engine/Hackables/HackableObject.h"

namespace cocos2d
{
	class Sprite;
}

class CollisionObject;
class ClickableNode;
class CurrencyInventory;
class EquipmentInventory;
class HackablePreview;
class HexusOpponentData;
class Inventory;
class PlatformerAttack;
class SmartAnimationNode;
class SpeechBubble;

class PlatformerEntity : public HackableObject
{
public:
	enum class ControlState
	{
		Normal,
		Swimming,
	};

	std::string getEntityName();
	void disablePlatformerControls();
	bool getIsPlatformerDisabled();
	virtual float getFloatHeight();

	std::vector<PlatformerAttack*> getAttacks();
	std::vector<PlatformerAttack*> getAvailableAttacks();
	std::vector<PlatformerAttack*> cloneAttacks();
	Inventory* getInventory();
	EquipmentInventory* getEquipmentInventory();
	CurrencyInventory* getCurrencyInventory();
	float getScale();
	std::string getAnimationResource();
	std::string getEmblemResource();
	SmartAnimationNode* getAnimations();
	cocos2d::Size getEntitySize();
	HexusOpponentData* getHexusOpponentData();
	virtual cocos2d::Vec2 getAvatarFrameOffset() = 0;

	SpeechBubble* speechBubble;
	SmartAnimationNode* animationNode;

protected:
	PlatformerEntity(
		cocos2d::ValueMap& properties,
		std::string scmlResource,
		std::string emblemResource,
		cocos2d::Size size,
		float scale,
		cocos2d::Vec2 collisionOffset,
		float hoverHeight = 0.0f,
		std::string inventorySaveKey = "",
		std::string equipmentSaveKey = "",
		std::string currencySaveKey = "");
	~PlatformerEntity();

	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;
	cocos2d::Vec2 getButtonOffset() override;
	HackablePreview* createDefaultPreview() override;
	void registerAttack(PlatformerAttack* attack);
	virtual void performSwimAnimation();
	virtual void performJumpAnimation();
	void doOutOfCombatAttack();

	CollisionObject* entityCollision;
	HexusOpponentData* hexusOpponentData;
	Inventory* inventory;
	EquipmentInventory* equipmentInventory;
	CurrencyInventory* currencyInventory;
	cocos2d::Vec2 spawnCoords;
	
	bool isCinimaticHijacked;
	bool isPlatformerDisabled;
	std::string state;

	float entityScale;
	cocos2d::Vec2 entityCollisionOffset;
	cocos2d::Size entitySize;
	cocos2d::Size movementSize;
	ControlState controlState;

	static const std::string MapKeyPropertyState;

private:
	typedef HackableObject super;
	friend class EntityCollisionBehaviorGroup;
	friend class EntityDebugBehavior;
	friend class EntityGroundCollisionBehavior;
	friend class EntityMovementBehavior;
	friend class EntityOutOfCombatAttackBehavior;
	friend class EntityMovementCollisionBehavior;
	friend class EntitySelectionBehavior;
	friend class EntityHealthBehavior;
	friend class EntityMovementCollisionBehavior;
	friend class EntityCollisionBehavior;

	float hoverHeight;
	float scale;
	std::string entityName;
	std::string animationResource;
	std::string emblemResource;
	std::vector<PlatformerAttack*> attacks;
	cocos2d::Vec2 hackButtonOffset;
};
