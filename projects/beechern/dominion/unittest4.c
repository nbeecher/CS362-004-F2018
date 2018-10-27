/******************************************************************
** Author:  Nicole Beecher
** Assignment:   Assignment 3 Unit Test 4
** Description:  Test updateCoins function
*********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"


int main()
{

	printf("\nUnit Test 4");

	struct gameState state;
	
	int rCoin = 0;
	int count = 0;
	time_t t;
	

	srand((unsigned)time(&t));	

	int cards[10] = { adventurer, council_room, feast, gardens,
		mine, remodel, smithy, village, province, great_hall };

	//initialize game and verify game does not end
	initializeGame(2, cards, 2, &state);


	//Check that it works for each player
	int i;
	for (i = 0; i < MAX_PLAYERS; i++) {

		count = 0;
		//random number from 0 to 2
		rCoin = rand() % 3;		

		int j;
		for (j = 0; j < state.handCount[i]; j++) {

			if (rCoin == 0) {
				state.hand[i][j] = copper;
				count += 1;
			}

			if (rCoin == 1) {
				state.hand[i][j] = silver;
				count += 2;
			}

			if (rCoin == 2) {
				state.hand[i][j] = gold;
				count += 3;
			}

		}
		
		updateCoins(i, &state, 0);

		
		if (count == state.coins)
		{
			printf("\nPassed no bonus");
		}
		else
		{
			printf("\nFailed no bonus");
		}
		//assert(count == state->coins);


		//Test again with an updated value (to see if the bonus works)
		count += 4;
		updateCoins(i, &state, 4);
			
		if (count == state.coins)
		{
			printf("\nPassed Bonus");
		}
		else
		{
			printf("\nFailed Bonus");
		}
		//assert(count == state->coins);


	}

	
	printf("\nUnit Test 4 testing completed");

	return 0;

}
