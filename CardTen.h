#pragma once
#include "Card.h"
#include"Player.h"
class CardTen : public Card
{
private:
	static int landprice;
	static int stationfair;
	static Player* ownership;
public:
		CardTen(const CellPosition & pos);
		int GetLandprice();
		void setownership(Player * pp);
		Player* getownership();

		virtual void ReadCardParameters(Grid * pGrid);
		virtual void Apply(Grid * pGrid, Player * pPlayer);
		virtual void Save(ofstream& OutFile, int type);

		virtual ~CardTen();
	
};

