#pragma once
#include"Card.h"
#include"CellPosition.h"
#include"Player.h"
#include"ApplicationManager.h"
class CardEight:public Card
{
private:
	int fair;
public:
	CardEight(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void  Save(ofstream& OutFile, int type);

	virtual ~CardEight();
};

