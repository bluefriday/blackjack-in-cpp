

#include "pch.h"
#include <iostream>
#include "Gamer.h"
#include "Dealer.h"
#include "Deck.h"

int main()
{
	Deck deck;
	Deck* p_deck = &deck;

	bool isGameGo = true;
	int gamerChoice = 0;

	Gamer gamer(p_deck);
	Dealer dealer(p_deck);

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "���� ������ �����մϴ�." << std::endl;


	while (isGameGo)
	{
		std::cout << "�ʵ� ���� ī�带 Ȯ���� �ּ���." << std::endl << std::endl ;
		gamer.showMyCard();
		dealer.showMyCard();

		dealer.askToGamer(p_deck, &gamer);
		if (gamer.playerStatus=="burst") {
			break;
		}

		dealer.dealerAction(p_deck);
		if (dealer.playerStatus=="burst") {
			break;
		}

		if (gamer.playerStatus=="stay" && dealer.playerStatus=="stay") {
			isGameGo = false;
		}
	}

	if ((gamer.playerStatus!="burst") && (dealer.playerStatus!="burst"))
	{
		dealer.checkGameResult(&gamer);
	}

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "������ ����Ǿ����ϴ�." << std::endl;
	gamer.showMyCard();
	dealer.showMyCard("End of Game");
	std::cout << "---------------------------------------------" << std::endl;


}
