#pragma once
#include <string>
#include <vector>

#include "cocos/base/ccTypes.h"

#include "Engine/UI/Controls/Text/TextWindow.h"

namespace cocos2d
{
	namespace ui
	{
		class UICCTextField;
		class RichText;
		class RichElement;
	}
}

class LocalizedLabel;
class LocalizedString;

class EditableTextWindow : public TextWindow
{
public:
	static EditableTextWindow* create(LocalizedString* windowTitle, LocalizedLabel* referenceContentLabel, cocos2d::Size initWindowSize, cocos2d::Color3B initFontColor);
	
	struct token
	{
		LocalizedString* tokenStr;
		cocos2d::Color3B color;

		token(LocalizedString* tokenStr, cocos2d::Color3B color) :
			tokenStr(tokenStr), color(color)
		{
		}
	};

	void setTokenizationCallback(std::function<void(std::string text, std::vector<EditableTextWindow::token>&)> newTokenizationCallback);
	void setOnEditCallback(std::function<void(std::string text)> newOnEditCallback);
	std::string getText();
	void setText(std::string text);
	void insertNewline() override;
	void clearText() override;
	void focus();

private:
	typedef TextWindow super;
	EditableTextWindow(LocalizedString* windowTitle, LocalizedLabel* referenceContentLabel, cocos2d::Size initWindowSize, cocos2d::Color3B initFontColor);
	virtual ~EditableTextWindow();

	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;
	void update(float) override;
	void constructTokenizedText(std::string currentText);

	cocos2d::ui::UICCTextField* editableText;
	cocos2d::ui::RichText* lineNumbers;

	int currentLineNumber;
	cocos2d::Color3B fontColor;
	cocos2d::Size windowSize;
	std::string previousText;

	std::vector<cocos2d::ui::RichElement*> lineNumberElements;
	std::function<void(std::string text, std::vector<EditableTextWindow::token>&)> tokenizationCallback;
	std::function<void(std::string text)> onEditCallback;

	static const cocos2d::Color3B lineNumberColor;
	static const std::string StringKeyClickToEdit;
};