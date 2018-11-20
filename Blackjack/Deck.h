#pragma once

#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <list>

class Deck
{
public:
	std::list<Card> cardSet;
	Deck();
	Card pickOneCard();
};

#endif
