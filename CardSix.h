#pragma once

#include "Card.h"
#include <fstream>
//  Instructs the player to go to a specific cell. This specific cell is specified during grid design

class CardSix : public Card
{
	// CardSix Parameters:
	CellPosition CellToMoveTo; // the specified Cell to move to
public:
	CardSix(const CellPosition& pos);  // A Constructor takes card position

	virtual ~CardSix(); // A Virtual Destructor

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card six which is: CellToMoveTo

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSix on the passed Player
	// by moving the player to the specified Cell " CellToMoveTo "

	void  Save(ofstream& OutFile, int type);

};