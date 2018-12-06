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

	std::cout << this->playerType + "의 카드 :";

	for (itr = myHand.begin(); itr != myHand.end(); itr++)
	{
		Card card = *itr;
		num = card.number;

		if (itr == myHand.begin()) 
		{
			std::cout << "[?  ?]";
		}
		else 
		{
			if (num == 11) { finalNum = "J"; }
			else if (num == 12) { finalNum = "Q"; }
			else if (num == 13) { finalNum = "K"; }
			else { finalNum = std::to_string(num); }

			std::cout << "[" + card.type + " " + finalNum + "]";
		}
	}
	std::cout << std::endl;
}

void Dealer::showMyCard(std::string flag)
{
	int num = 0;
	std::string finalNum = "";
	std::list<Card>::iterator itr;

	std::cout << this->playerType + "의 카드 :";

	for (itr = myHand.begin(); itr != myHand.end(); itr++)
	{
		Card card = *itr;
		num = card.number;

		if (num == 11) { finalNum = "J"; }
		else if (num == 12) { finalNum = "Q"; }
		else if (num == 13) { finalNum = "K"; }
		else { finalNum = std::to_string(num); }

		std::cout << "[" + card.type + " " + finalNum + "]";
	}
	std::cout << std::endl;
}



void Dealer::askToGamer(Deck* deck, Gamer* gamer)
{
	bool validation = true;
	std::string unCheckInput = "";
	int gamerChoice = 0;

	while (validation) 
	{
		std::cout << "당신의 차례입니다." << std::endl;
		std::cout << "(1) 카드를 더 뽑습니다.(hit) [input 1]" << std::endl;
		std::cout << "(2) 카드를 더이상 뽑지 않습니다.(stay) [input 2]" << std::endl;
		std::cout << "Input : " ;

		try  //숫자 입력에 문자열 예외 체크를 위하여 처음부터 문자열로 받고 검사
		{
			std::cin >> unCheckInput;

			if ( !(this->isDigit(unCheckInput)) ) //숫자가 아니면 문자열 타입으로 예외 throw
			{
				throw unCheckInput;
			}
			else  //숫자 입력이 맞으면, 해당 문자열을 숫자로 반환하여 적절한 숫자인지 체크
			{
				gamerChoice = std::stoi(unCheckInput);
				if (gamerChoice != 1 && gamerChoice != 2)
				{
					throw gamerChoice;
				}
			}
			validation = false; //try 구문의 끝에 도달하면 예외가 없으므로 종료 flag 설정
		}
		catch (std::string errorInput)
		{
			std::cout << "WARN : 문자를 입력할 수는 없습니다." << std::endl;
		}
		catch (int errorInput)
		{
			std::cout << "WARN : 1, 2 이외의 입력할 수는 없습니다." << std::endl;
		}

	}
	system("CLS");

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
		std::cout << "축하합니다!! 당신의 승리입니다." << std::endl;
	}
	else if (gamer_score < dealer_score) 
	{
		std::cout << "딜러의 승리입니다." << std::endl;
	}
	else 
	{
		std::cout << "이번 게임은 무승부입니다." << std::endl;
	}
}

bool Dealer::isDigit(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str.at(i) < '0' || str.at(i) > '9')
			return false;
	}
	return true;
}