#include "Cutscene.h"

Cutscene* Cutscene::create(std::function<void()> cutsceneCompleteCallback)
{
	Cutscene* instance = new Cutscene(cutsceneCompleteCallback);

	instance->autorelease();

	return instance;
}

Cutscene::Cutscene(std::function<void()> cutsceneCompleteCallback)
{
	this->activeClip = nullptr;
	this->cutsceneClips = new std::deque<CutsceneClip*>();
	this->onCutsceneCompleteCallback = cutsceneCompleteCallback;
}

Cutscene::~Cutscene()
{
	for (auto it = this->cutsceneClips->begin(); it != this->cutsceneClips->end(); it++)
	{
		(*it)->release();
	}

	delete(this->cutsceneClips);
}

void Cutscene::initializeListeners()
{
	FadeScene::initializeListeners();

	EventListenerKeyboard* keyboardListener = EventListenerKeyboard::create();

	keyboardListener->onKeyPressed = CC_CALLBACK_2(Cutscene::onKeyPressed, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

void Cutscene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		event->stopPropagation();
		this->endCutscene();
		break;
	default:
		break;
	}
}

void Cutscene::playCutscenes()
{
	this->playNextCutsceneClip();
}

void Cutscene::playNextCutsceneClip()
{
	if (this->activeClip != nullptr)
	{
		this->removeChild(this->activeClip);
	}

	if (this->cutsceneClips->size() <= 0)
	{
		this->activeClip = nullptr;
		this->endCutscene();
		return;
	}

	this->activeClip = this->cutsceneClips->front();
	this->cutsceneClips->pop_front();

	this->addChild(this->activeClip);
}

void Cutscene::endCutscene()
{
	if (this->onCutsceneCompleteCallback != nullptr)
	{
		this->onCutsceneCompleteCallback();
	}
}

void Cutscene::cutsceneClipCompleteCallback()
{
	this->playNextCutsceneClip();
}

void Cutscene::enqueueCutsceneClip(CutsceneClip* cutscene)
{
	cutscene->setCutsceneClipCompleteCallback(CC_CALLBACK_0(Cutscene::cutsceneClipCompleteCallback, this));
	cutscene->retain();
	this->cutsceneClips->push_back(cutscene);
}