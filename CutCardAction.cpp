#include "CutCardAction.h"
#include"ApplicationManager.h"
#include "Input.h"
#include "Output.h"
#include "Action.h"


CutCardAction::CutCardAction(ApplicationManager* pApp) :Action(pApp)
{

}

void CutCardAction::ReadActionParameters() {
	pGrid = (pManager->GetGrid());
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("to Cut any Card = click on its cell");
	pCellPosition = pIn->GetCellClicked();
	if (pCellPosition.IsValidCell() != true)
	{
		pGrid->PrintErrorMessage("Invalid cell! Click anywhere to continue");
		pOut->ClearStatusBar();
		return;
	}
	pOut->ClearStatusBar();
}

void CutCardAction::Execute() {
	ReadActionParameters();
	pGrid = (pManager->GetGrid());
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	CellPosition target = pCellPosition;
	TargetCard = pGrid->GetCard(target);
	pGrid->SetClipboard(TargetCard);
	pGrid->RemoveObjectFromCell(target);
	pGrid->PrintErrorMessage("cutted...!");
}

CutCardAction::~CutCardAction() {

}


