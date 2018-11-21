#include "pch.h"
#include "Player.h"

Player::Player(Deck* deck)
{
	this->playerStatus = "hit";
	myHand.push_back(deck->pickOneCard());
	myHand.push_back(deck->pickOneCard());
}

void Player::hit(Deck* deck)
{
	Card givenCard = deck->pickOneCard();

	myHand.push_back(givenCard);

	if (this->countMyScore() > 21) {
		this->playerStatus = "burst";
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << this->playerType + " lose. (burst!!) " << std::endl;
	}
	else {
		this->playerStatus = "hit";
	}
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

	std::cout << this->playerType + "'s Card :";

	for (itr = myHand.begin(); itr != myHand.end(); itr++)
	{
		Card card = *itr;
		num = card.number;

		if (num == 11) { finalNum = "[J]"; }
		else if (num == 12) { finalNum = "[Q]"; }
		else if (num == 13) { finalNum = "[K]"; }
		else { finalNum = "[" + std::to_string(num) + "]"; }

		std::cout << finalNum + " ";
	}
	std::cout << std::endl;
}

int Player::countMyScore() {
	int score = 0;
	int num = 0;
	std::list<Card>::iterator itr;

	for (itr = myHand.begin(); itr != myHand.end(); itr++)
	{
		Card card = *itr;
		num = card.number;

		if (num > 10) {
			num = 10;
		}

		score += num;
	}
	return score;
}
