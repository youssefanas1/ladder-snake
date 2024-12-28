#pragma once
#include "Card.h"
class CardThree :public Card
{
public:
	CardThree(const CellPosition& pos); //constructor
	virtual ~CardThree();
	virtual void ReadCardParameters(Grid* pGrid); // no parameters 
	virtual void Apply(Grid* pGrid, Player* CurrentPlayer); // moves the player forward the same number of steps previously rolled
	void  Save(ofstream& OutFile, int type);

};

