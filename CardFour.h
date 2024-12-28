#pragma once
#include "Card.h"
class CardFour :public Card
{
public:
	CardFour(const CellPosition& pos); //constructor
	virtual ~CardFour();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* CurrentPlayer); //  prevents the player to roll dice 
	void  Save(ofstream& OutFile, int type);

};

