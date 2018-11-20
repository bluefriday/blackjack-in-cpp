
#pragma once

#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include <vector>
class Player
{
public:
	std::string playerType;
	std::string playerStatus;
	std::vector<Card> myHand;
	Player(Deck);
	void hit(Deck);
	void stay();
	void showMyCard();
};

#endif
