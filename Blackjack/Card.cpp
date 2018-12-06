#include "pch.h"
#include "Card.h"

/*
Card::Card(int number)
{
	this->number = number;
}
*/

Card::Card(int number, bool isNotNumber, std::string type)
{
	this->number = number;
	this->isNotNumber = isNotNumber;
	this->type = type;
}