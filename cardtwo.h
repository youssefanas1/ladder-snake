#pragma once

#include "Card.h"
#include"Ladder.h"

class CardTwo:public Card
{
public:
	CardTwo(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);  
	
	void Save(ofstream& outFile, int type);

	virtual ~CardTwo();
};

