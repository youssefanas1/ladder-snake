#pragma once
#include "Card.h"
#include "Player.h"
class CardTwelve : public Card
{
public:

	CardTwelve(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void Save(ofstream& outFile, int type);

	virtual ~CardTwelve();
};

