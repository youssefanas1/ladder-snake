#include "CardTwo.h"
#include<fstream>

CardTwo::CardTwo(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2;
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Ladder* target;
     target = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());
	if (target!= NULL) {
		int num=(target->GetPosition().GetCellNum())-(pPlayer->GetCell()->GetCellPosition().GetCellNum());    //to calc the num of dice to pass to function move
		pPlayer->Move(pGrid,num);
	}
	return;
}

void CardTwo::Save(ofstream& OutFile, int type) {
	if (type == 2) {
		OutFile << cardNumber << " ";
		Card::Save(OutFile, 2);
	}
}

CardTwo::~CardTwo()
{
}
