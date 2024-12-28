#pragma once
#include "ApplicationManager.h"
#include"Card.h"
#include"Grid.h"
#include"Action.h"
class PasteCardAction : public Action
{
private:
	Card* TargetCard;
	Grid* pGrid;
	CellPosition pCellPosition;
public:

	PasteCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~PasteCardAction();
};