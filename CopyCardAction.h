#pragma once
#include "ApplicationManager.h"
#include"Card.h"
#include"Grid.h"
#include"Action.h"
class CopyCardAction : public Action
{
private:
	Card* TargetCard;
	Grid* pGrid;
	CellPosition pCellPosition;
public:

	CopyCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CopyCardAction();
};



