#include "StatePlayCard.h"

StatePlayCard* StatePlayCard::create()
{
	StatePlayCard* instance = new StatePlayCard();

	instance->autorelease();

	return instance;
}

StatePlayCard::StatePlayCard() : StateBase(GameState::StateType::PlayCard)
{
}

StatePlayCard::~StatePlayCard()
{
}

void StatePlayCard::onBeforeStateEnter(GameState* gameState)
{
	StateBase::onBeforeStateEnter(gameState);
}

void StatePlayCard::onStateEnter(GameState* gameState)
{
	StateBase::onStateEnter(gameState);

	if (gameState->selectedCard == nullptr)
	{
		this->passFromError(gameState);
		return;
	}

	CardRow* selfHand = nullptr;
	CardRow* selfBinaryRow = nullptr;
	CardRow* selfDecimalRow = nullptr;
	CardRow* selfHexRow = nullptr;
	Deck* selfGraveyard = nullptr;

	switch (gameState->turn)
	{
		case GameState::Turn::Player:
			selfHand = gameState->playerHand;
			selfBinaryRow = gameState->playerBinaryCards;
			selfDecimalRow = gameState->playerDecimalCards;
			selfHexRow = gameState->playerHexCards;
			selfGraveyard = gameState->playerGraveyard;
			break;
		case GameState::Turn::Enemy:
			selfHand = gameState->enemyHand;
			selfBinaryRow = gameState->enemyBinaryCards;
			selfDecimalRow = gameState->enemyDecimalCards;
			selfHexRow = gameState->enemyHexCards;
			selfGraveyard = gameState->enemyGraveyard;
			break;
		default:
			this->passFromError(gameState);
			return;
	}

	switch (gameState->selectedCard->cardData->cardType)
	{
		case CardData::CardType::Binary:
		case CardData::CardType::Decimal:
		case CardData::CardType::Hexidecimal:
		{
			if (gameState->selectedRow == nullptr)
			{
				this->passFromError(gameState);
				return;
			}

			selfHand->removeCard(gameState->selectedCard);
			gameState->selectedRow->insertCard(gameState->selectedCard, Config::insertDelay);
			SoundManager::playSoundResource(Resources::Sounds_Hexus_Card_Game_Movement_Deal_Single_Small_01);
			break;
		}
		case CardData::CardType::Special_SHL:
		case CardData::CardType::Special_SHR:
		case CardData::CardType::Special_FLIP1:
		case CardData::CardType::Special_FLIP2:
		case CardData::CardType::Special_FLIP3:
		case CardData::CardType::Special_FLIP4:
		case CardData::CardType::Special_INV:
		{
			if (gameState->selectedRow == nullptr)
			{
				this->passFromError(gameState);
				return;
			}

			selfHand->removeCard(gameState->selectedCard);
			selfGraveyard->insertCardTop(gameState->selectedCard, true, Config::insertDelay);

			Card::Operation operation = Card::toOperation(gameState->selectedCard->cardData->cardType, 0);

			for (auto it = gameState->selectedRow->rowCards.begin(); it != gameState->selectedRow->rowCards.end(); it++)
			{
				Card* card = *it;

				card->addOperation(operation);
			}

			// Decide which effect and sounds to play
			switch (gameState->selectedCard->cardData->cardType)
			{
				case CardData::CardType::Special_SHL:
				{
					gameState->selectedRow->runEffect(CardEffects::CardEffect::MeteorPurple);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_Card_Game_Abilities_Air_Glitter_01);
					break;
				}
				case CardData::CardType::Special_SHR:
				{
					gameState->selectedRow->runEffect(CardEffects::CardEffect::MeteorBlue);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_Card_Game_Abilities_Air_Glitter_01);
					break;
				}
				case CardData::CardType::Special_FLIP1:
				{
					gameState->selectedRow->runEffect(CardEffects::CardEffect::TargetPulse);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_Card_Game_Abilities_Air_Glitter_01);
					break;
				}
				case CardData::CardType::Special_FLIP2:
				{
					gameState->selectedRow->runEffect(CardEffects::CardEffect::FrostCirlce);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_Card_Game_Abilities_Air_Glitter_01);
					break;
				}
				case CardData::CardType::Special_FLIP3:
				{
					gameState->selectedRow->runEffect(CardEffects::CardEffect::RadialGalaxy);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_Card_Game_Abilities_Air_Glitter_01);
					break;
				}
				case CardData::CardType::Special_FLIP4:
				{
					gameState->selectedRow->runEffect(CardEffects::CardEffect::RadialFire);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_Card_Game_Abilities_Air_Glitter_01);
					break;
				}
				case CardData::CardType::Special_INV:
				{
					gameState->selectedRow->runEffect(CardEffects::CardEffect::Bite);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_Card_Game_Abilities_Air_Glitter_01);
					break;
				}
				default:
				{
					break;
				}
			}

			break;
		}
		case CardData::CardType::Special_MOV:
		case CardData::CardType::Special_AND:
		case CardData::CardType::Special_OR:
		case CardData::CardType::Special_XOR:
		case CardData::CardType::Special_ADD:
		case CardData::CardType::Special_SUB:
		{
			if (gameState->stagedCombineSourceCard == nullptr || gameState->stagedCombineTargetCard == nullptr)
			{
				this->passFromError(gameState);
				return;
			}

			selfHand->removeCard(gameState->selectedCard);
			selfGraveyard->insertCardTop(gameState->selectedCard, true, Config::insertDelay);

			Card::Operation operation = Card::toOperation(
				gameState->selectedCard->cardData->cardType,
				gameState->stagedCombineSourceCard->getAttack()
			);

			gameState->stagedCombineTargetCard->addOperation(operation);

			// Decide which effect and sounds to play
			switch (gameState->selectedCard->cardData->cardType)
			{
				case CardData::CardType::Special_MOV:
				{
					gameState->stagedCombineTargetCard->cardEffects->runEffect(CardEffects::CardEffect::DustPoof);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_05_Acid_Spell);
					break;
				}
				case CardData::CardType::Special_AND:
				{
					gameState->stagedCombineTargetCard->cardEffects->runEffect(CardEffects::CardEffect::FireBlast);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_05_Acid_Spell);
					break;
				}
				case CardData::CardType::Special_OR:
				{
					gameState->stagedCombineTargetCard->cardEffects->runEffect(CardEffects::CardEffect::Lightning);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_05_Acid_Spell);
					break;
				}
				case CardData::CardType::Special_XOR:
				{
					gameState->stagedCombineTargetCard->cardEffects->runEffect(CardEffects::CardEffect::RadialStorm);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_05_Acid_Spell);
					break;
				}
				case CardData::CardType::Special_ADD:
				{
					gameState->stagedCombineTargetCard->cardEffects->runEffect(CardEffects::CardEffect::MagicBurst);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_05_Acid_Spell);
					break;
				}
				case CardData::CardType::Special_SUB:
				{
					gameState->stagedCombineTargetCard->cardEffects->runEffect(CardEffects::CardEffect::StarHit);
					SoundManager::playSoundResource(Resources::Sounds_Hexus_Attacks_05_Acid_Spell);
					break;
				}
				default:
				{
					break;
				}
			}

			break;
		}
		default:
			this->passFromError(gameState);
			return;
	}

	gameState->playableCardsThisTurn--;
	gameState->selectedCard = nullptr;
	CallFunc* stateTransition = nullptr;

	if (gameState->turn == GameState::Turn::Player)
	{
		if (gameState->playerHand->getCardCount() <= 0)
		{
			stateTransition = CallFunc::create([=]()
			{
				GameState::updateState(gameState, GameState::StateType::Pass);
			});
		}
		else
		{
			if (gameState->playableCardsThisTurn <= 0)
			{
				stateTransition = CallFunc::create([=]()
				{
					GameState::updateState(gameState, GameState::StateType::TurnEnd);
				});
			}
			else
			{
				stateTransition = CallFunc::create([=]()
				{
					GameState::updateState(gameState, GameState::StateType::Neutral);
				});
			}
		}
	}
	else
	{
		if (gameState->enemyHand->getCardCount() <= 0)
		{
			stateTransition = CallFunc::create([=]()
			{
				GameState::updateState(gameState, GameState::StateType::Pass);
			});
		}
		else
		{
			if (gameState->playableCardsThisTurn <= 0)
			{
				stateTransition = CallFunc::create([=]()
				{
					GameState::updateState(gameState, GameState::StateType::TurnEnd);
				});
			}
			else
			{
				stateTransition = CallFunc::create([=]()
				{
					GameState::updateState(gameState, GameState::StateType::AIDecidePass);
				});
			}
		}
	}

	this->runAction(Sequence::create(
		DelayTime::create(0.5f),
		stateTransition,
		nullptr
	));
}

void StatePlayCard::onStateReload(GameState* gameState)
{
	StateBase::onStateReload(gameState);
}

void StatePlayCard::onStateExit(GameState* gameState)
{
	StateBase::onStateExit(gameState);

	gameState->stagedCombineSourceCard = nullptr;
	gameState->stagedCombineTargetCard = nullptr;
}

void StatePlayCard::passFromError(GameState* gameState)
{
	this->runAction(Sequence::create(
		DelayTime::create(0.5f),
		CallFunc::create([=]()
		{
			GameState::updateState(gameState, GameState::StateType::Pass);
		}),
		nullptr
	));
}