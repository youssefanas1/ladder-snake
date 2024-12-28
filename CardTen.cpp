#include "CardTen.h"
#include<fstream>
int CardTen::landprice = 0;
int CardTen::stationfair = 0;
Player* CardTen::ownership = NULL;
CardTen::CardTen(const CellPosition& pos) :Card(pos)
{
	cardNumber = 10;

}
int CardTen::GetLandprice()
	{
	return landprice;
	}


void CardTen::setownership(Player* pp)
{
	ownership = pp;
}

Player* CardTen::getownership()
{
	return ownership;
}

void CardTen::ReadCardParameters(Grid* pGrid)
{
	if (landprice == 0 && stationfair == 0) {
		Input* pin = pGrid->GetInput();
		Output* pout = pGrid->GetOutput();
		pout->PrintMessage("Card Ten(Land): Enter the land price =");
		landprice = pin->GetInteger(pout);
		pout->ClearStatusBar();
		pout->PrintMessage("Card Ten(Land): Enter the pass fair =");
		stationfair = pin->GetInteger(pout);
		pout->ClearStatusBar();
		return;
	}
	pGrid->PrintErrorMessage("click to continue...! ");
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Input* pin = pGrid->GetInput();
	Output* pout = pGrid->GetOutput();
	Card::Apply(pGrid, pPlayer);
	if (getownership() == NULL) {
		pout->PrintMessage("Card Ten(Land):if you want to buy it enter (1)");
		int ans = pin->GetInteger(pout);
		if (ans == 1)
		{
			pGrid->PrintErrorMessage("congralations...!:you bought the land 10");
			int ze = pPlayer->GetWallet() - landprice;
			pPlayer->SetWallet(ze);
			pPlayer->setowner10(true);
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

void CardTen::Save(ofstream& OutFile, int type) {
	if (type == 2) {
		OutFile << cardNumber << " ";
		Card::Save(OutFile, 2);
		OutFile << landprice << stationfair << endl;
	}
}

CardTen::~CardTen()
{
}
