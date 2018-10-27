/******************************************************************
** Author:  Nicole Beecher
** Assignment:   Assignment 3 Card Test 2
** Description:  Adventurer
*********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"


int main()
{
	printf("\nCard Test 2");

	struct gameState state, test;

	int cards[10] = { adventurer, council_room, feast, gardens,
		mine, remodel, smithy, village, province, great_hall };

	//initialize game
	initializeGame(2, cards, 2, &state);

	memcpy(&test, &state, sizeof(struct gameState));

	cardEffect(adventurer, 0, 0, 0, &test, 0, 0);

	//check if the deckcount goes down by 2
	if (test.deckCount[0] != state.deckCount[0] - 2) 
	{		
		printf("\nFail deckcount not corret");
	}
	else {
		printf("\nPass deckcount");
	}

	//check hand count
	if (test.handCount[0] != state.handCount[0] + 2 - 1) 
	{		
		printf("\nFail hand count check");
	}
	else {
		printf("\nPass hand count check");
	}


	//check if the two cards taken are treasure cards
	if (test.hand[0][test.handCount[0] - 1] != copper && test.hand[0][test.handCount[0] - 1] != silver && test.hand[0][test.handCount[0] - 1] != gold) 
	{		
		printf("\nFail one of the cards taken not a treasure card");
	}
	else 
	{
		printf("\nPass treasure card check");
	}

	if (test.hand[0][test.handCount[0] - 2] != copper && test.hand[0][test.handCount[0] - 2] != silver && test.hand[0][test.handCount[0] - 2] != gold) 
	{		
		printf("\nFail one of the cards taken not a treasure card");
	}
	else 
	{
		printf("\nPass treasure card check");
	}

	printf("\nCard Test 2 testing completed");


	return 0;
}
