#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "MiniGames/Hexium/Components/ComponentBase.h"
#include "GUI/Components/MenuSprite.h"
#include "Utils/StrUtils.h"

using namespace cocos2d;

class ScoreTotal : public ComponentBase
{
public:
	static ScoreTotal * create();

protected:
	void onStateChange(GameState* eventCustom) override;

private:
	ScoreTotal();
	~ScoreTotal();

	void onEnter() override;
	void initializePositions();
	void initializeListeners();
	void updateTotals(GameState* gameState);

	Sprite* playerTotalFrame;
	Label* playerTotal;
	Sprite* playerLeaderEmblem;

	Sprite* enemyTotalFrame;
	Label* enemyTotal;
	Sprite* enemyLeaderEmblem;
};