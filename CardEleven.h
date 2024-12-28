#pragma once
#include "Card.h"
#include"Player.h"
class CardEleven : public Card
{
private:
	static int landprice;
	static int stationfair;
	static Player* ownership;
public:
	CardEleven(const CellPosition& pos);
	int Getlandprice();
	void setownership(Player* pp);
	Player* getownership();

	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void  Save(ofstream& OutFile, int type);

	virtual ~CardEleven();
};

