#pragma once
#include "ApplicationManager.h"
#include"Card.h"
#include"Grid.h"
#include"Action.h"
class CutCardAction : public Action
{
private:
	Card* TargetCard;
	Grid* pGrid;
	CellPosition pCellPosition;
public:

	CutCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CutCardAction();
};