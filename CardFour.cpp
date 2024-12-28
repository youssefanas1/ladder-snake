#include "CardFour.h"
#include <fstream>
CardFour::CardFour(const CellPosition& pos) :Card(pos) // set the cell position of the card with initializer list
{
	cardNumber = 4;
}

CardFour::~CardFour()
{
}

void CardFour::ReadCardParameters(Grid* pGrid)
{
	//Geting a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//printing to a descriptive message to the user
	pOut->PrintMessage("New CardFour. Click to continue");
	//clearing stutus bar
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void CardFour::Apply(Grid* pGrid, Player* CurrentPlayer)
{
	// Calling Apply() of the base class Card to print the message  you reached this card number
	Card::Apply(pGrid, CurrentPlayer);
	//Geting a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//printing to a descriptive message to the user
	pOut->PrintMessage("You are prevented from dice roll. Click to continue");
	//clearing stutus bar
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	CurrentPlayer->setdecrease(true);
	CurrentPlayer->setturncount(0);                                //setting decreaseroll to true
}
void CardFour::Save(ofstream& OutFile, int type) {
	if (type == 2) {
		OutFile << cardNumber << " ";
		Card::Save(OutFile, 2);
	}
}
