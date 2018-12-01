/******************************************************************
** Author:  Nicole Beecher
** Assignment:   Assignment 4 random adventurer test

*********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	printf("Random test for adventurer card\n");
	struct gameState game;

	int seed = 1000;
	int numPlayer = 2;
	
	int k[10] = { adventurer, council_room, feast, gardens,
		mine, remodel, smithy, village, province, great_hall };
	
	int handPos = 0;
	int testCount = 0;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;
	int failed = 0;
	int passed = 0;
	//int handCount = 0;
	int expected = 0;
	int randomHandCount = 0;
	int randomDeckCount = 0;
	int bonus = 0;
	srand(time(NULL));

	int i;
	int j;

	for (i = 0; i <= 1; i++)
	{
		for (j = 0; j <= 2000; j++)
		{
			testCount++;

			randomHandCount = (rand() % 500) - 1;
			randomDeckCount = (rand() % 500);
			if (randomHandCount == 0) {
				printf("\nrandom Hand Count == 0\n");
			}
	
			expected = randomHandCount + 2;

			memset(&game, 23, sizeof(struct gameState));	
			initializeGame(numPlayer, k, seed, &game);	
			game.handCount[i] = randomHandCount;		
			game.deckCount[i] = randomDeckCount;		
			game.whoseTurn = i;				

											
			if (randomDeckCount != 0) {
				cardEffect(adventurer, choice1, choice2, choice3, &game, handPos, &bonus); 
			}
		

			if (numHandCards(&game) == expected && randomDeckCount != 0) 
			{
				passed++;
			}
			else 
			{
				failed++;				
			}

		}
	}
	
	printf("\nTimes ran: %d | Tests Passed: %d | Tests Failed: %d\n", testCount, passed, failed);

	return 0;	

}
