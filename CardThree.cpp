#include "CardThree.h"
#include<fstream>
CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card with initializer list
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number
}


CardThree::~CardThree()
{
}

void CardThree::ReadCardParameters(Grid* pGrid)
{
	//Geting a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//printing to a descriptive message to the user
	pOut->PrintMessage("New CardThree. Click to continue");
	//clearing stutus bar
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();

}

void CardThree::Apply(Grid* pGrid, Player* CurrentPlayer)
{
	// Calling Apply() of the base class Card to print the message  you reached this card number
	Card::Apply(pGrid, CurrentPlayer);
	//Geting a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//printing to a descriptive message to the user
	pOut->PrintMessage("You are given another dice roll. Click to continue");
	//clearing stutus bar
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	CurrentPlayer->setextra(true); //setting extraroll to true
}

void CardThree::Save(ofstream& OutFile, int type) {
	if (type == 2) {
		OutFile << cardNumber << " ";
		Card::Save(OutFile, 2);
	}
}