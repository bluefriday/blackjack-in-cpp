#include "pch.h"
#include "Deck.h"

Deck::Deck()
{

	bool isNotNumber = false;
	for (int i = 1; i <= 13; i++) {
		//11 이상일 경우 숫자가 아님을 표시
		if (i == 11) { isNotNumber = true; }
		else { isNotNumber = false; }

		Card card(i);
		this->cardSet.push_back(card);
	}
}

Card Deck::pickOneCard()
{
	std::list<Card>::iterator itr;
	itr = cardSet.begin();

	return *itr;
	/*
	//임의로 한 개의 카드를 추출
	//무작위성을 보장하기 위해 상위 객체의 shuffle 기능 사용
	//추출한 카드는 덱에서 삭제
	//추출한 카드를 반환
	return pickedCard;
	}
	else {
		return new Card(0);
	}
	*/

}
