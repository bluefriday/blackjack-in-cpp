#pragma once

#ifndef CARD_H
#define CARD_H
class Card
{
public:
	int number;
	bool isNotNumber;
	std::string type;
	Card(int );

	//remove는 ==, != 로 매칭을 하는데, custom object 에는 그게 없음
	//overriding 해서 만들어줘야함.
	bool operator == (const Card& card) const 
	{ 
		return number == card.number && isNotNumber == card.isNotNumber && type == card.type;
	}
	bool operator != (const Card& card) const
	{
		return !(operator==(card));
	}

};

#endif

