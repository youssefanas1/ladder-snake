#include "CardEleven.h"
#include<fstream>

int CardEleven::landprice = 0;
int CardEleven::stationfair = 0;
Player* CardEleven::ownership = NULL;
CardEleven::CardEleven(const CellPosition& pos) :Card(pos)
{
	cardNumber = 11;

}
int CardEleven::Getlandprice()
{
	return landprice;
}
void CardEleven::setownership(Player* pp)
{
	ownership = pp;
}

Player* CardEleven::getownership()
{
	return ownership;
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{
	if (landprice == 0 && stationfair == 0) {
		Input* pin = pGrid->GetInput();
		Output* pout = pGrid->GetOutput();
		pout->PrintMessage("Card Eleven(Land): Enter the land price =");
		landprice = pin->GetInteger(pout);
		pout->ClearStatusBar();
		pout->PrintMessage("Card Eleven(Land): Enter the pass fair =");
		stationfair = pin->GetInteger(pout);
		pout->ClearStatusBar();
		return;
	}
	pGrid->PrintErrorMessage("click to continue...! ");
}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Input* pin = pGrid->GetInput();
	Output* pout = pGrid->GetOutput();
	Card::Apply(pGrid, pPlayer);
	if (getownership() == NULL) {
		pout->PrintMessage("Card Eleven(Land):if you want to buy it enter (1)");
		int ans = pin->GetInteger(pout);
		if (ans == 1)
		{
			pGrid->PrintErrorMessage("congralation...!:you bought the land 11");
			int ze = pPlayer->GetWallet() - landprice;
			pPlayer->SetWallet(ze);
			pPlayer->setowner11(true);
			setownership(pPlayer);
		}
		else {
			pGrid->PrintErrorMessage("good evening:click to continue..!");
			return;
		}
	}
	if (pPlayer == ownership) {
		return;
	}
	else {
		pGrid->PrintErrorMessage("OPS...!!,you have to pay the station fair");
		int ne = pPlayer->GetWallet() - stationfair;
		pPlayer->SetWallet(ne);
		int no = ownership->GetWallet() + stationfair;
		ownership->SetWallet(no);
	}

}

void CardEleven::Save(ofstream& OutFile, int type) {
	if (type == 2) {
		OutFile << cardNumber << " ";
		Card::Save(OutFile, 2);
		OutFile << landprice << stationfair << endl;
	}
}

CardEleven::~CardEleven()
{
}