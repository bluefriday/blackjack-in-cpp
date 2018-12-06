#include "pch.h"
#include "Deck.h"
#include <random>

Deck::Deck()
{
	bool isNotNumber = false;

	//스페이드 카드 추가
	for (int i = 1; i <= 13; i++) {
		if (i > 10) { isNotNumber = true; }
		else { isNotNumber = false; }

		Card card(i, isNotNumber, "♠");
		this->cardSet.push_back(card);
	}

	//다이아 카드 추가
	for (int i = 1; i <= 13; i++) {
		if (i > 10) { isNotNumber = true; }
		else { isNotNumber = false; }

		Card card(i, isNotNumber, "◆");
		this->cardSet.push_back(card);
	}

	//하트 카드 추가
	for (int i = 1; i <= 13; i++) {
		if (i > 10) { isNotNumber = true; }
		else { isNotNumber = false; }

		Card card(i, isNotNumber, "♥");
		this->cardSet.push_back(card);
	}

	//클로버 카드 추가
	for (int i = 1; i <= 13; i++) {
		if (i > 10) { isNotNumber = true; }
		else { isNotNumber = false; }

		Card card(i, isNotNumber, "♣");
		this->cardSet.push_back(card);
	}


}

Card Deck::pickOneCard()
{
	//한 장의 카드를 뽑는 함수.
	//(to do)수학적으로 존재할 수 없는 경우이나, 프로그래밍 적으로 카드가 한 장도 없는 경우에 대한 예외처리 필요

	if (cardSet.size() == 0) {
		Card no_card(0,false, "");
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

	Card ret_card(itr->number,itr->isNotNumber, itr->type);
	cardSet.remove(*itr);

	//std::cout << "now card size is : " + std::to_string(cardSet.size()) << std::endl;

	return ret_card;
}
