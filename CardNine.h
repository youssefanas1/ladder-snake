#pragma once
#include"Card.h"
#include"Player.h"
class CardNine:public Card
{private:
	static int landprice;
	static int stationfair;
	static Player* ownership;
public:
	CardNine(const CellPosition& pos);
	int GetLandprice();
	void setownership(Player* pp);
	Player* getownership();

	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void  Save(ofstream& OutFile, int type);

	virtual ~CardNine();
};

