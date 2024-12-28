#pragma once
#include "Card.h"
#include <fstream>
// moves the player forward the same number of steps previously rolled
class CardFive :public Card
{
public:
	CardFive(const CellPosition& pos);
	virtual ~CardFive();
	virtual void ReadCardParameters(Grid* pGrid); // Parameters: rolled dice value
	virtual void Apply(Grid* pGrid, Player* pPlayer); // moves the player forward the same number of steps previously rolled
	void  Save(ofstream& OutFile, int type);

};