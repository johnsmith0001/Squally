#pragma once

#include "Engine/SmartNode.h"
#include "Engine/Localization/LocalizedString.h"

namespace cocos2d
{
	class Node;
	class Sprite;
}

class ConstantString;
class ClickableNode;
class HackableCode;
class LocalizedLabel;

class ScriptEntry : public SmartNode
{
public:
	static ScriptEntry* create(LocalizedString* scriptName, std::string script, bool isReadOnly, std::function<void(ScriptEntry*)> onScriptEntryClick, std::function<void(ScriptEntry*)> onCopyClick, std::function<void(ScriptEntry*)> onDeleteClick);

	void toggleSelected(bool isSelected);
	void deleteScript();
	void copyScript();
	LocalizedString* getName();
	std::string getScript();
	void setScript(std::string script);
	void setName(std::string name);

	bool isReadOnly;

private:
	typedef SmartNode super;
	ScriptEntry(LocalizedString* scriptName, std::string script, bool isReadOnly, std::function<void(ScriptEntry*)> onScriptEntryClick, std::function<void(ScriptEntry*)> onCopyClick, std::function<void(ScriptEntry*)> onDeleteClick);
	~ScriptEntry() = default;

	void initializePositions() override;
	void initializeListeners() override;

	ClickableNode* backPlate;
	cocos2d::Sprite* selectedSprite;
	LocalizedLabel* label;
	ClickableNode* copyButton;
	ClickableNode* deleteButton;

	LocalizedString* scriptName;
	std::string script;
	std::function<void(ScriptEntry*)> onScriptEntryClick;
	std::function<void(ScriptEntry*)> onCopyClick;
	std::function<void(ScriptEntry*)> onDeleteClick;
};
