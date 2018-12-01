/******************************************************************
** Author:  Nicole Beecher
** Assignment:   Assignment 3 Card Test 3
** Description:  Village
*********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"


int main()
{
	printf("Card Test 3");

	struct gameState state, test;

	int cards[10] = { adventurer, council_room, feast, gardens,
		mine, remodel, smithy, village, province, great_hall };

	//initialize game
	initializeGame(2, cards, 2, &state);

	memcpy(&test, &state, sizeof(struct gameState));

	//check handcount goes up by 1 for player playing village card
	cardEffect(village, 0, 0, 0, &test, 0, 0);

	if (test.handCount[0] != state.handCount[0] + 1 - 1)
	{
		printf("\nFailed handcount");
	}
	else
	{
		printf("\nPased handcount");
	}

	//check if number of actions increases by 2
	if (test.numActions != state.numActions + 2) 
	{		
		printf("\nFail number of actions");
	}
	else {
		printf("\nPass number of actions");
	}

	//check deckcount
	if (test.deckCount[0] != state.deckCount[0] - 1) 
	{		
		printf("\nFailed deck count");
	}
	else {
		printf("\nPass deck count");
	}

	printf("\nCard Test 3 testing completed");

	return 0;

}

