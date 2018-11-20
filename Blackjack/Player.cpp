
#include "pch.h"
#include "Player.h"

Player::Player(Deck deck)
{
	this->playerStatus = "hit";
	myHand.push_back(&deck.pickOneCard);
	//myHand.push_back(&deck.pickOneCard);
}

void Player::hit(Deck deck) 
{
	this->playerStatus = "hit";
}

void Player::stay()
{
	this->playerStatus = "stay";
}

void Player::showMyCard()
{
	int num = 0;
	std::string finalNum = "";
	std::list<Card>::iterator itr;

	std::cout << this->playerType + "ÀÇ Ä«µå :" << std::endl;

	for (itr=myHand.begin() ; itr != myHand.end() ; itr++)
	{
		Card card = *itr;
		num = card.number;

		if (num == 11)		{	finalNum = "[J]";		}
		else if (num == 12) {	finalNum = "[Q]";		}
		else if (num == 13) {	finalNum = "[K]";		}
		else { finalNum = "[" + std::to_string(num) + "]"; }

		std::cout << finalNum + " ";
	}
	std::cout << std::endl;
}