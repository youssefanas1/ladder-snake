#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardSeven.h"
#include "CardTwelve.h"
#include"CardEight.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardNine.h"
#include "CardSix.h"
#include "CardTen.h"
#include "CardEleven.h"


AddCardAction::AddCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid(); // Grid initializes input and output with pManager

	Input* pIn = pGrid->GetInput(); // pIn to get functions from class input

	Output* pOut = pGrid->GetOutput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces

	int number;

	// 2- Read the "cardNumber" parameter and set its data member

	pOut->PrintMessage("Enter card number :");

	number = pIn->GetInteger(pOut);

	// 3- Read the "cardPosition" parameter (its cell position) and set its data member

	pOut->PrintMessage("Click on the cell");

	  CellPosition position = pIn->GetCellClicked();
	
	// 4- Make the needed validations on the read parameters
	{
		if (number <= 12 && number >= 1)//to get only the cards between 1 - 12
		{
			cardNumber = number;
		}
		else
		{
			pGrid->PrintErrorMessage("Invalid card number Click to continue....");	
		}
	}
	{	
		if (position.IsValidCell())//to see if you clicked inside the grid
		{
			cardPosition = position;
		}
		else
		{
			pGrid->PrintErrorMessage("Invalid position click to continue....");
		}
	}
	pOut->ClearStatusBar(); 
}

void AddCardAction::Execute()
{
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first

	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card* pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	case 2:
		pCard = new CardTwo(cardPosition);
		break;
	case 3:
		pCard = new CardThree(cardPosition);
		break;
	case 4:
		pCard = new CardFour(cardPosition);
		break;
	case 5:
		pCard = new CardFive(cardPosition);
		break;
	case 6:
		pCard = new CardSix(cardPosition);
		break;
	case 7:
		pCard = new CardSeven(cardPosition);
		break;
	case 8:
		pCard = new CardEight(cardPosition);
		break;
	case 9:
		pCard = new CardNine(cardPosition);
		break;
	case 10:
		pCard = new CardTen(cardPosition);
		break;
	case 11:
		pCard = new CardEleven(cardPosition);
		break;
	case 12:
		pCard = new CardTwelve(cardPosition);
		break;
	
	

	

		// A- Add the remaining cases

	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid(); // same as the function before

		Input* pIn = pGrid->GetInput();

		Output* pOut = pGrid->GetOutput();

		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type

		pCard->ReadCardParameters(pGrid);

		// C- Add the card object to the GameObject of its Cell:

		bool addedcard = pGrid->AddObjectToCell(pCard); //adds card to the cell chosen

		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

		if (addedcard == false)//checks if the cell is occupied
		{
			pGrid->PrintErrorMessage("Error cell is occupied with another object");

		}
		pOut->ClearStatusBar();
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
