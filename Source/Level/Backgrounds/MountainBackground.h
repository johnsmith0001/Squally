#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "Level/LevelCamera.h"
#include "GUI/Components/InfiniteParallaxNode.h"

using namespace cocos2d;

class MountainBackground : public Layer
{
public:
	static MountainBackground * create();

	void update(float) override;

protected:
	MountainBackground();
	~MountainBackground();

	Sprite * background;

private:
	InfiniteParallaxNode * clouds;
	ParallaxNode * mountains;
	ParallaxNode * mountains2;
	ParallaxNode * trees1;
	ParallaxNode * trees2;
	ParallaxNode * trees3;
};
