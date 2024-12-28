#include "CardSeven.h"
#include<fstream>

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card

{
	cardNumber = 7; // set the inherited cardNumber data member with the card number
}
void CardSeven::ReadCardParameters(Grid* pGrid)
{

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	Player* nearestplayer = pGrid->GetNearestPlayer(pPlayer);//gets the nearest player 

	CellPosition pos(8, 0);

	if (nearestplayer != pPlayer)
	{
		pGrid->UpdatePlayerCell(nearestplayer, pos);//resets the nearest player position to the begininng

		nearestplayer->setstepCount(0);
	}
}

void CardSeven::Save(ofstream& OutFile, int type) {
	if (type == 2) {
		OutFile << cardNumber << " ";
		Card::Save(OutFile, 2);
	}
}

CardSeven::~CardSeven()
{
}
