#include "CardEight.h"
#include<fstream>

CardEight::CardEight(const CellPosition& pos) :Card(pos)
{
	cardNumber = 8;
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	
	Input* pin = pGrid->GetInput();
	Output* pout = pGrid->GetOutput();
	pout->PrintMessage("Card Eight(prison): Enter the fair amount:");
	fair = pin->GetInteger(pout);
	if (fair <= 0)
	{
		pGrid->PrintErrorMessage("error ,renter the fair amount(postive integer please):");   //for read fair that free you from prison
		fair = pin->GetInteger(pout);
	}                                                                                          
	pGrid->PrintErrorMessage("click any where to continue :");
	pout->ClearStatusBar();

}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Input* pin = pGrid->GetInput();
	Output* pout = pGrid->GetOutput();
	bool check = pPlayer->checkability(fair);
	if (check == false)
	{
		pout->PrintMessage("you don't have enough money to pay fair ,so you will be arrested for next 3 turns");        
		pPlayer->setprisonned(true);
	}
	pout->PrintMessage("you have an offer !! :if you want to pay the fair and to be free enter (1) and if not enter (2)");
	int play = pin->GetInteger(pout);
	pGrid->PrintErrorMessage("click any where to continue :");
	if (play == 1)
	{
		pGrid->PrintErrorMessage("now you are free...");
		pPlayer->setprisonned(false);
		int newwallet=pPlayer->GetWallet() - fair;                                 // if player choose to pay fair and setted free
		pPlayer->SetWallet(newwallet);
	}
	else if (play == 2) {
		pGrid->PrintErrorMessage("now you got arrested...!");
		pPlayer->setturncount(0);                                      // if palyer refused to pay fair and got arrested
		pPlayer->setprisonned(true);
	}
	else
	{
		pGrid->PrintErrorMessage(" error:click to continue...! ");            // if user enter wrong answer
		                                  
	}
	pout->ClearStatusBar();
}

void CardEight::Save(ofstream& OutFile, int type) {
	if (type == 2) {
		OutFile << cardNumber << " ";
		Card::Save(OutFile, 2);
		OutFile << fair;
	}
}

CardEight::~CardEight()
{
}
