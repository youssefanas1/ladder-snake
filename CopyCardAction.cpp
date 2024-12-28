#include "CopyCardAction.h"
#include"ApplicationManager.h"
#include "Input.h"
#include "Output.h"
#include "Action.h"


CopyCardAction::CopyCardAction(ApplicationManager* pApp) :Action(pApp)
{

}

void CopyCardAction::ReadActionParameters() {
	pGrid = (pManager->GetGrid());
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	
	pOut->PrintMessage("to Copy any Card = click on its cell");
	pCellPosition = pIn->GetCellClicked();
	if (pCellPosition.IsValidCell() != true)
	{
		pGrid->PrintErrorMessage("Invalid cell! Click anywhere to continue");
		pOut->ClearStatusBar();
		return;
	}
	pOut->ClearStatusBar();
}

void CopyCardAction::Execute() {
	ReadActionParameters();
	pGrid = (pManager->GetGrid());
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	CellPosition target = pCellPosition;
	TargetCard = pGrid->GetCard(target);
	pGrid->SetClipboard(TargetCard);
	pGrid->PrintErrorMessage("copied...!!");
}

CopyCardAction::~CopyCardAction() {

}