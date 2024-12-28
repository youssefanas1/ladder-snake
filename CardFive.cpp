#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos): Card(pos) //initalizer list for inherted class
{
	cardNumber =5;
}


CardFive::~CardFive()
{
}

void CardFive::ReadCardParameters(Grid* pGrid)
{
	//Geting a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//printing to a descriptive message to the user
	pOut->PrintMessage("New CardFive. Click to continue...");
	//clearing stutus bar
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();

}

void CardFive::Apply(Grid* pGrid, Player* CurrentPlayer)
{
	// Calling Apply() of the base class Card to print the message  you reached this card number
	Card::Apply(pGrid, CurrentPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//printing to a descriptive message to the user
	pOut->PrintMessage("Move backward the same number of steps that you just rolled. Click to continue...");
	//clearing stutus bar
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	// moving the player forward the same number of steps previously rolled
	CurrentPlayer->Move(pGrid, (CurrentPlayer->getjustrolldice()) * -1);
	//if player landed on any game object ( snake, ladder, card) apply its effect
	if (CurrentPlayer->GetCell()->GetGameObject())
	{
		CurrentPlayer->GetCell()->GetGameObject()->Apply(pGrid, CurrentPlayer);
	}
}

void CardFive::Save(ofstream& OutFile, int type) {
	if (type == 2) {
		OutFile << cardNumber << " ";
		Card::Save(OutFile, 2);
	}
}
