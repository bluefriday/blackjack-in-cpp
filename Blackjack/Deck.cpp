#include "pch.h"
#include "Deck.h"

Deck::Deck()
{

	bool isNotNumber = false;
	for (int i = 1; i <= 13; i++) {
		//11 �̻��� ��� ���ڰ� �ƴ��� ǥ��
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
	//���Ƿ� �� ���� ī�带 ����
	//���������� �����ϱ� ���� ���� ��ü�� shuffle ��� ���
	//������ ī��� ������ ����
	//������ ī�带 ��ȯ
	return pickedCard;
	}
	else {
		return new Card(0);
	}
	*/

}
