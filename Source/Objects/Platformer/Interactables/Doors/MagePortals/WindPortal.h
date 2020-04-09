#pragma once
#include <set>

#include "Objects/Platformer/Interactables/Doors/MagePortals/MagePortal.h"

namespace cocos2d
{
	class DrawNode;
	class ParticleSystem;
}

class WindPortal : public MagePortal
{
public:
	static WindPortal* create(cocos2d::ValueMap& properties);

	void closePortal(bool instant) override;
	void openPortal(bool instant) override;

	static const std::string MapKey;

protected:
	WindPortal(cocos2d::ValueMap& properties);
	virtual ~WindPortal();
	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;

private:
	typedef MagePortal super;

	cocos2d::DrawNode* background;
	SmartParticles* portalParticles;
	cocos2d::DrawNode* edge;
	SmartParticles* edgeParticles;
};
