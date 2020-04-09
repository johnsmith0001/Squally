#pragma once
#include <functional>

#include "Menus/Crafting/CraftingMenuBase.h"

namespace cocos2d
{
	class Sprite;
};

class Sound;

class AlchemyMenu : public CraftingMenuBase
{
public:
	static AlchemyMenu* create();

protected:
	AlchemyMenu();
	virtual ~AlchemyMenu();

	void initializePositions() override;
	void onCraftStart() override;
	void onCraftEnd(bool viaCancel) override;

private:
	typedef CraftingMenuBase super;

	cocos2d::Sprite* anvil;
	cocos2d::Sprite* icon;
	Sound* craftSound;
};
