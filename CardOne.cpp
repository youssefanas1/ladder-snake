#include "CardOne.h"
#include<fstream>

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{
	
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* in = pGrid->GetInput();
	Output* out = pGrid->GetOutput();


	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	out->PrintMessage("New CardOne: Enter its wallet amount ");
	walletAmount=in->GetInteger(out);
	while (walletAmount < 0)
	{
		pGrid->PrintErrorMessage("New CardOne: Re-enter its wallet amount ( a value greater than 0 )...");
		walletAmount = in->GetInteger(out);
	}
	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action
//clearing stutus bar
	int x, y;
	in->GetPointClicked(x, y);
	out->ClearStatusBar();


}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne

	int newwalletamount = pPlayer->GetWallet() - walletAmount;
	pPlayer->SetWallet(newwalletamount);
	//Geting a Pointer to the Input / Output Interfaces from the Grid

	Output* out = pGrid->GetOutput();
	Input* in = pGrid->GetInput();
	//printing to a descriptive message to the user of the new wallet amount

	out->PrintMessage("Your total wallet amount has decreaced to " + to_string(pPlayer->GetWallet()) + " Coins.. Click to continue ..");
	//clearing status bar
	int x, y;
	in->GetPointClicked(x, y);
	out->ClearStatusBar();
}

void CardOne::Save(ofstream& OutFile, int type) {
	if (type == 2) {
		OutFile << cardNumber << " ";
		Card::Save(OutFile, 2);
		OutFile << walletAmount << endl;
	}
}
