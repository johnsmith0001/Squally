#pragma once
#include "cocos/base/CCEvent.h"
#include "cocos/base/CCEventKeyboard.h"

#include "Engine/GlobalScene.h"

class ClickableNode;
class ClickableTextNode;
class LocalizedString;
class ScrollPane;

class MinigamesMenu : public GlobalScene
{
public:
	static MinigamesMenu* getInstance();

protected:
	MinigamesMenu();
	~MinigamesMenu();

private:
	typedef GlobalScene super;
	void onEnter() override;
	void initializeListeners() override;
	void initializePositions() override;

	ClickableTextNode* createButton(LocalizedString* text, std::string iconResource);
	ClickableTextNode* createComingSoonButton();

	cocos2d::Node* backgroundNode;
	ScrollPane* scrollPane;
	ClickableTextNode* hexusButton;
	ClickableTextNode* hexusPuzzlesButton;
	ClickableTextNode* cipherButton;
	ClickableTextNode* pointerTraceButton;
	ClickableTextNode* stacksButton;
	ClickableTextNode* towerDefenseButton;
	ClickableTextNode* spaceForceButton;
	ClickableTextNode* backButton;

	static MinigamesMenu* instance;
};
