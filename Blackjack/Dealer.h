#pragma once
#ifndef DEALER_H
#define DEALER_H
#include "Player.h"
#include "Gamer.h"

class Dealer : public Player
{
public:
	Dealer(Deck*);
	void showMyCard();
	void showMyCard(std::string);
	void askToGamer(Deck*, Gamer*);
	void dealerAction(Deck*);
	void checkGameResult(Gamer*);
	bool isDigit(std::string);
};

#endif
