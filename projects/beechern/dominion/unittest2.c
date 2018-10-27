/******************************************************************
** Author:  Nicole Beecher
** Assignment:   Assignment 3 Unit Test 2
** Description:  Test handCard function
*********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"


int main()
{
	printf("\nUnit Test 2");

	struct gameState state;

	int cards[10] = { adventurer, council_room, feast, gardens,
		mine, remodel, smithy, village, province, great_hall };


	//initialize game 
	initializeGame(2, cards, 2, &state);
	int i;
	for (i = 0; i < 10; i++)
	{
		state.hand[1][i] = cards[i];
		state.handCount[1] += 1;


		int j, result;
		for (j = 0; cards[j] != 0; j++)
		{
			result = handCard(j, &state);
			if ((cards[result] == cards[j]) == 0)
			{
				continue;
			}
			else
			{
				printf("\nFailure %d", cards[result]);
			}
		}
	}

	printf("\nUnit Test 2 testing completed");

	return 0;

}

