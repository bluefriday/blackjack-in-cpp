#include "pch.h"
#include "Dealer.h"

Dealer::Dealer(Deck* deck) : Player(deck)
{
	deck;
	this->playerType = "Dealer";
}

void Dealer::showMyCard() 
{
	int num = 0;
	std::string finalNum = "";
	std::list<Card>::iterator itr;

	std::cout << this->playerType + "'s Card :";

	for (itr = myHand.begin(); itr != myHand.end(); itr++)
	{
		Card card = *itr;
		num = card.number;

		if (itr == myHand.begin()) 
		{
			finalNum = "[?]";
		}
		else if (num == 11) { finalNum = "[J]"; }
		else if (num == 12) { finalNum = "[Q]"; }
		else if (num == 13) { finalNum = "[K]"; }
		else { finalNum = "[" + std::to_string(num) + "]"; }

		std::cout << finalNum + " ";
	}
	std::cout << std::endl;
}

void Dealer::showMyCard(std::string flag)
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



void Dealer::askToGamer(Deck* deck, Gamer* gamer)
{
	//Scanner input = new Scanner(new InputStreamReader(System.in));
	bool validation = true;
	int gamerChoice = 0;

	while (validation) 
	{
		std::cout << "Your's turn" << std::endl;
		std::cout << "(1) hit. draw an extra card. [input 1]" << std::endl;
		std::cout << "(2) stay. You will not take. [input 2]" << std::endl;
		std::cout << "Input : " ;
		std::cin >> gamerChoice;

		if (gamerChoice == 1 || gamerChoice == 2) 
		{
			validation = false;
		}
	}

	if (gamerChoice == 1) 
	{
		gamer->hit(deck);
	}
	else 
	{
		gamer->stay();
	}

}

void Dealer::dealerAction(Deck* deck)
{
	int totalValue = this->countMyScore();

	if (totalValue >= 17) {
		//17점 이상이면 딜러는 카드를 추가할 수 없음
		std::cout << "DEBUG!! dealer stay" << std::endl;
		this->stay();
	}
	else {
		//16점 이하면 항상 딜러는 카드를 추가해야 함
		this->hit(deck);
	}
}

void Dealer::checkGameResult(Gamer* gamer)
{
	int gamer_score = gamer->countMyScore();
	int dealer_score = this->countMyScore();

	std::cout << "---------------------------------------------" << std::endl;

	if (gamer_score > dealer_score) 
	{
		std::cout << "Congratulation!! 당신의 승리입니다." << std::endl;
	}
	else if (gamer_score < dealer_score) 
	{
		std::cout << "Oh.. Dealer win." << std::endl;
	}
	else 
	{
		std::cout << "This game is draw.." << std::endl;
	}
}
