﻿// Blackjack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "Gamer.h"
#include "Deck.h"

int main()
{
	Deck deck;
	Gamer gamer(deck);
	//std::cout << gamer.playerType + "\n" << std::endl;
	gamer.showMyCard();
}
