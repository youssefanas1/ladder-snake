#include "CardTwelve.h"

#include "Grid.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"


CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos) // set the cell position of the card

{
	cardNumber = 12; // set the inherited cardNumber data member with the card number
}
void CardTwelve::ReadCardParameters(Grid* pGrid)
{

}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{ 
	Card::Apply(pGrid, pPlayer);

	int lowest = 10000;

	Player* currentplayer = pGrid->GetCurrentPlayer();

	Player* poorplayer;

	for (int i = 0; i < 4; i++)
	{
		if (pGrid->GetCurrentPlayer()->GetWallet()<lowest)//gets the wallet for every player and when the lowest one comes it advance inside the condition
		{
			lowest = pGrid->GetCurrentPlayer()->GetWallet();//sets the lowest wallet

			poorplayer = pGrid->GetCurrentPlayer();//gets the player with the least money
		}
		pGrid->AdvanceCurrentPlayer();//advances to the next player
	}

	CardNine* cardnine = nullptr;

	CardTen* cardten = nullptr;

	CardEleven* cardeleven = nullptr;

	if (cardnine->GetLandprice() > cardten->GetLandprice() && cardnine->GetLandprice() > cardeleven->Getlandprice())
	{
		cardnine->setownership(poorplayer);//sees if the land price of card 9 is the most expensive and gives it to the poorest
	}
	else if (cardten->GetLandprice() > cardnine->GetLandprice() && cardten->GetLandprice() > cardeleven->Getlandprice())
	{
		cardten->setownership(poorplayer);//sees if the land price of card 10 is the most expensive and gives it to the poorest
	}
	else if (cardeleven->Getlandprice() > cardnine->GetLandprice() && cardeleven->Getlandprice() > cardten->GetLandprice())
	{
		cardeleven->setownership(poorplayer);//sees if the land price of card 11 is the most expensive and gives it to the poorest
	}
	pGrid->PrintErrorMessage("Congrats the poorest player now have the most expensive land  click to continue....");
}

void CardTwelve::Save(ofstream& outFile, int type) {
	if (type == 2)
	{
		Card::Save(outFile, 2);
	}
}

CardTwelve::~CardTwelve()
{
}
