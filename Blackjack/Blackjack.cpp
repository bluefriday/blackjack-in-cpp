// Blackjack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "Gamer.h"
#include "Dealer.h"
#include "Deck.h"

int main()
{
	Deck deck;
	Deck* p_deck = &deck;
	//여기서 deck 포인터를 안주면 call by value 에 의해서 객체를 복사해줌. 즉 동일 deck 아니게 되버림

	bool isGameGo = true;
	int gamerChoice = 0;

	Gamer gamer(p_deck);
	Dealer dealer(p_deck);

	//게이머는 자신의 차례에서 딜러와 게이머의 카드를 모두 확인할 수 있음(auto print mode)
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "게임을 시작합니다." << std::endl;
/*
	while (isGameGo)
	{
		std::cout << "필드의 카드를 확인해 주세요." << std::endl << std::endl ;
		gamer.showMyCard();
		dealer.showMyCard();

		//딜러는 게임 진행 여부를 플레이어에게 물어봄
		//게이머의 턴
		dealer.askToGamer(deck, gamer);
		if ("burst".equals(gamer.status)) {
			//gamer 가 bursting 이 되면 그 즉시 게임 종료
			//딜러와 게이머가 모두 버스팅이면 딜러의 승리이므로, 게이머의 로직을 먼저 체크함
			break;
		}
		//딜러의 턴
		dealer.dealerAction(deck);
		if ("burst".equals(dealer.status)) {
			//dealer 가 bursting 이 되면 그 즉시 게임 종료
			break;
		}

		//게이머와 딜러의 턴이 모두 끝나면 둘다 stay인지 확인
		if ("stay".equals(gamer.status) && "stay".equals(dealer.status)) {
			isGameGo = false;
		}
	}
*/
}
