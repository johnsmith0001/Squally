#pragma once
#include <functional>
#include <vector>

#include "Engine/SmartNode.h"
#include "Scenes/Hexus/CardEffects.h"

class Card;
class ClickableNode;

class CardRow : public SmartNode
{
public:
	static CardRow * create(bool isPlayerRow);

	void insertCards(std::vector<Card*> cards, float cardInsertDelay, float indexDelay = 0.0f);
	void insertCard(Card* card, float cardInsertDelay);
	Card* removeCard(Card* card);
	int getCardCount();
	int getRowAttack();
	bool isPlayerRow();
	bool isEnemyRow();
	bool isEmpty();
	void setCardScale(float scale, float scaleSpeed);
	float getCardScale();
	void runEffect(CardEffects::CardEffect effect, std::vector<Card*> ignoreList = std::vector<Card*>());
	void clearEffects();
	void enableRowSelection(std::function<void(CardRow*)> callback);
	void enableRowCardSelection(std::function<void(Card*)> callback);
	void disableRowSelection();
	void disableRowCardSelection();
	void setMouseOverCallback(std::function<void(Card*)> callback);
	void setMouseClickCallback(std::function<void(Card*)> callback);
	void enableRowCardInteraction();
	void disableRowCardInteraction();
	int simulateCardEffect(Card* card);
	void setRowWidth(float newRowWidth, float duration);
	void shuffle();
	void clear();

	std::vector<Card*> rowCards;

private:
	typedef SmartNode super;
	CardRow(bool isPlayerRow);
	~CardRow();

	void onEnter() override;
	void initializeListeners() override;
	void setCardPositions(float cardRepositionDelay, float indexDelay = 0.0f);
	void onRowSelectClick(ClickableNode* menuSprite);

	float rowWidth;
	float cardScale;
	bool belongsToPlayer;
	ClickableNode* rowSelectSprite;
	std::function<void(CardRow*)> rowSelectCallback;
};
