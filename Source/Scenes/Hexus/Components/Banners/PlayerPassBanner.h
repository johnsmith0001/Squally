#pragma once
#include "cocos2d.h"

#include "Engine/Localization/Localization.h"
#include "Resources.h"
#include "Scenes/Hexus/Components/Banners/BannerBase.h"

using namespace cocos2d;

class PlayerPassBanner : public BannerBase
{
public:
	static PlayerPassBanner * create();

protected:
	void onBeforeStateChange(GameState* eventCustom) override;
	void onAnyStateChange(GameState* eventCustom) override;

private:
	PlayerPassBanner();
	~PlayerPassBanner();

	void initializePositions() override;

	Sprite* playerPassBanner1;
	Sprite* playerPassBanner2;
};