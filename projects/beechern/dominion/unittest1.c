/******************************************************************
** Author:  Nicole Beecher
** Assignment:   Assignment 3 Unit Test 1
** Description:  Test getCost function
*********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{

	printf("Unit Test 1");

	int cards[27] = { curse, estate, duchy, province, copper, silver, gold, adventurer, council_room,
		feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward,
		tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map };

	int cost[27] = { 0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4 };

	struct gameState state;

	
	//initialize game and verify game does not end
	initializeGame(2, cards, 2, &state);

	int errors = 0;
	int i;
	for (i = 0; i < 27; i++)
	{
		if (getCost(cards[i]) != cost[i])
		{
			printf("\nFailure %d", cards[i]);
			errors++;
		}
		else
		{
			continue;
		}
	}

	if (errors == 0)
	{
		printf("\nNo errors found in getCost function.");
	}


	printf("\nUnit Test 1 testing completed");
	return 0;
}
