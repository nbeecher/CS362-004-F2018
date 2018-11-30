/******************************************************************
** Author:  Nicole Beecher
** Assignment:   Assignment 3 Card Test 4
** Description:  Embargo
*********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"


int main()
{
	printf("\nCard Test 4");

	struct gameState state, test;

	int cards[10] = { adventurer, embargo, feast, gardens,
		mine, remodel, smithy, village, province, great_hall };

	//initialize game
	initializeGame(2, cards, 2, &state);

	memcpy(&test, &state, sizeof(struct gameState));
	
	cardEffect(embargo, 0, 0, 0, &test, 0, 0);

	//check hand count
	if (test.handCount[0] != state.handCount[0] - 1)
	{
		printf("\nFail hand count check");
	}
	else {
		printf("\nPass hand count check");
	}


	//check coin count
	if (test.coins != state.coins + 2)
	{
		printf("\nFail coin count check");
	}
	else {
		printf("\nPass coin count check");
	}

	//check deckcount
	if (test.deckCount[0] != state.deckCount[0] - 1)
	{
		printf("\nFailed deck count");
	}
	else {
		printf("\nPass deck count");
	}

	printf("\nCard Test 4 testing completed");

	return 0;


}

