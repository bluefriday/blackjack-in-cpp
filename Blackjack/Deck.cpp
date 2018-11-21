#include "pch.h"
#include "Deck.h"
#include <random>

Deck::Deck()
{
	bool isNotNumber = false;
	for (int i = 1; i <= 13; i++) {
		if (i == 11) { isNotNumber = true; }
		else { isNotNumber = false; }

		Card card(i);
		this->cardSet.push_back(card);
	}
}

Card Deck::pickOneCard()
{
	if (cardSet.size() == 0) {
		Card no_card(0);
		return no_card;
	}

	//std::cout << "now card size is : " + std::to_string(cardSet.size()) << std::endl;

	std::list<Card>::iterator itr;
	itr = cardSet.begin();
	
	std::random_device rd; 
	std::mt19937 mersenne(rd()); // Create a mersenne twister, seeded using the random device // Create a reusable random number generator that generates uniform numbers between 1 and 6 
	std::uniform_int_distribution<> die(0, cardSet.size()-1);

	int random_index = die(mersenne);

	//std::cout << random_index;
	std::advance(itr, random_index);

	Card ret_card(itr->number);
	cardSet.remove(*itr);

	//std::cout << "now card size is : " + std::to_string(cardSet.size()) << std::endl;

	return ret_card;
}
