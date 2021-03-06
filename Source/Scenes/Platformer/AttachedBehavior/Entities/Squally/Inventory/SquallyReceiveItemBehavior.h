#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class Squally;

class SquallyReceiveItemBehavior : public AttachedBehavior
{
public:
	static SquallyReceiveItemBehavior* create(GameObject* owner);

	static const std::string MapKey;

protected:
	SquallyReceiveItemBehavior(GameObject* owner);
	virtual ~SquallyReceiveItemBehavior();

	void onLoad() override;
	void onDisable() override;

private:
	typedef AttachedBehavior super;

	Squally* squally;
};
