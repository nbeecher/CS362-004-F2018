/******************************************************************
** Author:  Nicole Beecher
** Assignment:   Assignment 3 Unit Test 3
** Description:  Test isGameOver function
*********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"


int main()
{
	printf("\nUnit Test 3");

	int returnValue = 0;

	struct gameState state;

	int cards[10] = { adventurer, council_room, feast, gardens,
		mine, remodel, smithy, village, province, great_hall };

	//initialize game and verify game does not end
	initializeGame(2, cards, 2, &state);

	returnValue = isGameOver(&state);

	if (returnValue == 1)
	{
		printf("\ninit failed");
	}
	else
	{
		printf("\ninit passed");
	}


	
	//set province to 0. game should end
	state.supplyCount[province] = 0;
	returnValue = isGameOver(&state);

	if (returnValue != 1)
	{
		printf("\nprovince failed");
	}
	else
	{
		printf("\nprovince passed");
	}


	//initialize game and verify game does not end
	initializeGame(2, cards, 2, &state);


	//set atleast 3 piles to empty
	state.supplyCount[curse] = 0;
	state.supplyCount[estate] = 0;
	state.supplyCount[copper] = 0;
	state.supplyCount[silver] = 0;
	state.supplyCount[gold] = 0;

	returnValue = 0;

	returnValue = isGameOver(&state);

	if (returnValue != 1)
	{
		printf("\n3 piles failed");
	}
	else
	{
		printf("\n3 piles passed");
	}	

	printf("\nUnit Test 3 testing completed");
	return 0;

}
