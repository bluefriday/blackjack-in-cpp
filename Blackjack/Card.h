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
	Card(int, bool, std::string);

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

