#include "CardNine.h"
int CardNine::landprice = 0;
int CardNine::stationfair = 0;
Player* CardNine :: ownership = NULL;
#include<fstream>

CardNine::CardNine(const CellPosition& pos):Card(pos)
{
	cardNumber = 9;
	
}
int CardNine::GetLandprice()
{
	return landprice;
}

void CardNine::setownership(Player* pp)
{
	ownership = pp;
}

Player* CardNine::getownership()
{
	return ownership;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	if (landprice == 0 && stationfair == 0) {
		Input* pin = pGrid->GetInput();
		Output* pout = pGrid->GetOutput();
		pout->PrintMessage("Card Nine(Land): Enter the land price =");
		landprice = pin->GetInteger(pout);
		pGrid->PrintErrorMessage("click anywhere to continue...");                   // for taking parameter of card like its price and fair 
		pout->ClearStatusBar();
		pout->PrintMessage("Card Nine(Land): Enter the pass fair =");
		stationfair = pin->GetInteger(pout);
		pGrid->PrintErrorMessage("click any where to continue");
		pout->ClearStatusBar();
		return;
	}
	pGrid->PrintErrorMessage("click to continue...! ");
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Input* pin = pGrid->GetInput();
	Output* pout = pGrid->GetOutput();
	Card::Apply(pGrid, pPlayer);
	if (getownership() == NULL) {
		pout->PrintMessage("Card Nine(Land):if you want to buy it enter (1)");
		int ans =pin->GetInteger(pout);
		if (ans==1)
		{
			pGrid->PrintErrorMessage("congralation...!:you bought the land 9");
			int ze = pPlayer->GetWallet() - landprice;
			pPlayer->SetWallet(ze);                                               //enter these loop if player buy the land
			pPlayer->setowner9(true);
			setownership(pPlayer);
		}
		else {
			pGrid->PrintErrorMessage("good evening:click to continue..!");
			return;                                                              //if not he pass safely if there is no owner for the land
		}
}
	if (pPlayer == ownership) {
		return;                                       //if the land is belong to current player
	}
	else {
		pGrid->PrintErrorMessage("OPS...!!,you have to pay the station fair");
		int ne = pPlayer->GetWallet()-stationfair;
		pPlayer->SetWallet(ne);                                              // how fair been taken from current player and sent to owner
		int no = ownership->GetWallet() + stationfair;
		ownership->SetWallet(no);
	}

}

void CardNine::Save(ofstream& OutFile, int type) {
	if (type == 2) {
		OutFile << cardNumber << " ";
		Card::Save(OutFile, 2);
	}
}

CardNine::~CardNine()
{
}
