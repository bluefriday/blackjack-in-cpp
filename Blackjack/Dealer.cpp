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

	std::cout << this->playerType + "�� ī�� :";

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

	std::cout << this->playerType + "�� ī�� :";

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
		std::cout << "����� �����Դϴ�." << std::endl;
		std::cout << "(1) ī�带 �� �̽��ϴ�.(hit) [input 1]" << std::endl;
		std::cout << "(2) ī�带 ���̻� ���� �ʽ��ϴ�.(stay) [input 2]" << std::endl;
		std::cout << "Input : " ;

		try  //���� �Է¿� ���ڿ� ���� üũ�� ���Ͽ� ó������ ���ڿ��� �ް� �˻�
		{
			std::cin >> unCheckInput;

			if ( !(this->isDigit(unCheckInput)) ) //���ڰ� �ƴϸ� ���ڿ� Ÿ������ ���� throw
			{
				throw unCheckInput;
			}
			else  //���� �Է��� ������, �ش� ���ڿ��� ���ڷ� ��ȯ�Ͽ� ������ �������� üũ
			{
				gamerChoice = std::stoi(unCheckInput);
				if (gamerChoice != 1 && gamerChoice != 2)
				{
					throw gamerChoice;
				}
			}
			validation = false; //try ������ ���� �����ϸ� ���ܰ� �����Ƿ� ���� flag ����
		}
		catch (std::string errorInput)
		{
			std::cout << "WARN : ���ڸ� �Է��� ���� �����ϴ�." << std::endl;
		}
		catch (int errorInput)
		{
			std::cout << "WARN : 1, 2 �̿��� �Է��� ���� �����ϴ�." << std::endl;
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
		//17�� �̻��̸� ������ ī�带 �߰��� �� ����
		this->stay();
	}
	else {
		//16�� ���ϸ� �׻� ������ ī�带 �߰��ؾ� ��
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
		std::cout << "�����մϴ�!! ����� �¸��Դϴ�." << std::endl;
	}
	else if (gamer_score < dealer_score) 
	{
		std::cout << "������ �¸��Դϴ�." << std::endl;
	}
	else 
	{
		std::cout << "�̹� ������ ���º��Դϴ�." << std::endl;
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