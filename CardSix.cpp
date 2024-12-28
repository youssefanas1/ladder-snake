#include "CardSix.h"
#include "Ladder.h"
#include "Snake.h"
#include<fstream>

CardSix::CardSix(const CellPosition& pos) : Card(pos)
{
	cardNumber = 6;
}

CardSix::~CardSix()
{
}

void CardSix::ReadCardParameters(Grid* pGrid)
{
	//  Geting a Pointer to the Input / Output Interfaces from the Grid
	Output* out = pGrid->GetOutput();
	Input* in = pGrid->GetInput();
	out->PrintMessage("New CardSix: Enter a special Cell for the player to move to ...");
	// read the special cell from the user
	CellToMoveTo = in->GetCellClicked();
	out->ClearStatusBar();
	//creating a while loop to re enter if CellToMoveTo is not valid
	while (CellToMoveTo.IsValidCell() == false || CellToMoveTo.GetCellNum() == 99)
	{
		if (CellToMoveTo.IsValidCell() == false)
		{
			out->PrintMessage("New CardSix: Re-enter a valid special Cell to move to ...");
			CellToMoveTo = in->GetCellClicked();
			out->ClearStatusBar();
		}
		else
		{
			out->PrintMessage("Cell-to-move-to can't be the last cell, Re-enter a valid special Cell to move to ...");
			CellToMoveTo = in->GetCellClicked();

			out->ClearStatusBar();
		}
	}
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	//identifying an element in class cellposition to check position of current player
	CellPosition checkCrurrentPlayerCEll = pPlayer->GetCell()->GetCellPosition();
	//  Calling Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	//  Geting a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//if current position of player not equal to the demanded cell to move to apply celltomoveto
	if (checkCrurrentPlayerCEll.GetCellNum() != CellToMoveTo.GetCellNum())
	{
		string msg = " Go to cell " + to_string(CellToMoveTo.GetCellNum()) + ". Click to continue ... ";
		pOut->PrintMessage(msg);
		//clearing status bar
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		//updating the changes to excute action
		pGrid->UpdatePlayerCell(pPlayer, CellToMoveTo);
	}
	
	//if player landed on any game object ( snake, ladder, card) apply its effect
	if (pPlayer->GetCell()->GetGameObject())
	{
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
	}
}

void CardSix::Save(ofstream& OutFile, int type) {
	if (type == 2) {
		OutFile << cardNumber << " ";
		Card::Save(OutFile, 2);
	}
}