#pragma once
#include "cocos2d.h"
#include "../Entities/Player.h"

using namespace cocos2d;

class Level : public Scene
{
public:
	Level();
	~Level();

protected:
	Player * player;
	Sprite* backGround;

private:
	void InitializeListeners();
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
};

