
#pragma once

#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include <list>
class Player
{
public:
	std::string playerType;
	std::string playerStatus;
	std::list<Card> myHand;
	Player(Deck);
	void hit(Deck);
	void stay();
	void showMyCard();
};

#endif
