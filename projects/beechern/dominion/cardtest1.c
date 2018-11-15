/******************************************************************
** Author:  Nicole Beecher
** Assignment:   Assignment 3 Card Test 1
** Description:  Smithy
*********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"


int main()
{
	printf("\nCard Test 1");

	struct gameState state, test;

	int cards[10] = { adventurer, council_room, feast, gardens,
		mine, remodel, smithy, village, province, great_hall };

	//initialize game
	initializeGame(2, cards, 2, &state);

	memcpy(&test, &state, sizeof(struct gameState));

	//check handcout goes up by 3 for player playing smithy card
	cardEffect(smithy, 0, 0, 0, &test, 0, 0);

	if (test.handCount[0] != state.handCount[0] + 3 - 1) 
	{		
		printf("\nFailed handcount");
	}
	else 
	{
		printf("\nPased handcount");
	}

	//check if deckcount goes down by 3
	if (test.deckCount[0] != state.deckCount[0] - 3) 
	{		
		printf("\nFailed deckcount decreasing by 3");
	}
	else 
	{
		printf("\nPassed deckcount decreasing by 3");
	}


	printf("\nCard Test 1 testing completed");


	return 0;
}


