#pragma once
#include "cocos2d.h"

#include "Engine/Dialogue/Dialogue.h"
#include "Engine/Input/InputManager.h"
#include "Engine/Rendering/Components/InfiniteParallaxNode.h"
#include "Engine/Utils/GameUtils.h"
#include "Resources.h"
#include "Scenes/Cutscenes/Cutscene.h"

using namespace cocos2d;

class City : public Cutscene
{
public:
	static City* create();

protected:
	City();
	~City();

private:
	void onEnter() override;
	void update(float) override;
	void initializePositions();
	void initializeListeners();

	void cutscenePan();
	void endCutscene();

	LayerGradient* sky;
	LayerColor* darkFilter;
	InfiniteParallaxNode* cityBackground;
	InfiniteParallaxNode* cityMidground;
	Sprite* vaporCorp;
	InfiniteParallaxNode* cityForeground;

	LayerColor* dialoguePlate;
	Dialogue* dialogue;
	Label* escapeLabel;

	static const float vaporCorpOffset;
};