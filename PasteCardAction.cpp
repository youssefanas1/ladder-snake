#include "PasteCardAction.h"
#include"ApplicationManager.h"
#include "Input.h"
#include "Output.h"
#include "Action.h"


PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp)
{

}

void PasteCardAction::ReadActionParameters() {
	pGrid = (pManager->GetGrid());
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("to paste the Card = click on its cell");
	pCellPosition = pIn->GetCellClicked();
	if (pCellPosition.IsValidCell() != true)
	{
		pGrid->PrintErrorMessage("Invalid cell! Click anywhere to continue...");
		pOut->ClearStatusBar();
		return;
	}
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();

	Card* pCard = pGrid->GetClipboard();

	if (pCard)
	{
		pCard->SetPosition(pCellPosition);
		pGrid->AddObjectToCell(pCard);
		pGrid->UpdateInterface();
	}
	else
	{
		pGrid->PrintErrorMessage("Error:: No card has been cut or copied, click to continue");
	}

}

PasteCardAction::~PasteCardAction()
{
}


