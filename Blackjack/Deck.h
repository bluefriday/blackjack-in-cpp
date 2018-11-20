#pragma once

#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>

class Deck
{
public:
	std::vector<Card> cardSet;
	Deck();
	Card pickOneCard();
};

#endif
