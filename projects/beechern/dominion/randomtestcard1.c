/******************************************************************
** Author:  Nicole Beecher
** Assignment:   Assignment 4 Test Village

*********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int failedEffects = 0;
int failedCoins = 0;
int failedBuys = 0;
int failedHands = 0;
int failedActions = 0;

void testVillageCard(int player, struct gameState *after) {
	struct gameState initial;

	int cardEffectTest;
	int bonus = 0;


	memcpy(&initial, after, sizeof(struct gameState));

	cardEffectTest = cardEffect(village, 0, 0, 0, after, 0, &bonus);
	if (cardEffectTest)
		failedEffects++;

	if (after->handCount[player] != initial.handCount[player])
	{
		failedHands++;
	}

	if (after->numBuys != initial.numBuys)
	{
		failedBuys++;
	}

	if (after->numActions != initial.numActions + 2)
	{
		failedActions++;
	}

	if (after->coins != initial.coins)
	{
		failedCoins++;
	}

}


int main()
{

	printf("Random test for village card\n");

	int i, j;
	int player, totalFailures;

	int k[10] = {adventurer, council_room, feast, gardens, mine,remodel, smithy, village, baron, great_hall};

	struct gameState game;

	srand(time(NULL));

	memset(&game, 0, sizeof(struct gameState));


	for (i = 0; i < 2000; i++) 
	{
		for (j = 0; j < sizeof(struct gameState); j++)
		{
			((char*)&game)[j] = floor(Random() * 256);
		}

		//initializeGame(2, k, i, &game);

		player = floor(Random() * MAX_PLAYERS);

		game.deckCount[player] = floor(Random() * MAX_DECK);
		game.discardCount[player] = floor(Random() * MAX_DECK);
		game.handCount[player] = floor(Random() * MAX_HAND);
		game.playedCardCount = floor(Random() * (MAX_DECK - 1));
		game.whoseTurn = player;

		//for (j = 0; j < game.deckCount[player]; j++) 
		//{
		//	game.hand[player][j] = floor((Random() * 26) + 1);
		//}

		testVillageCard(player, &game);
	}

	totalFailures = failedEffects + failedBuys + failedCoins + failedHands + failedActions;

	printf("RESULTS for village test:\n\n");

	if (totalFailures == 0)
		printf("All Tests Passed\n\n");

	else 
	{
		printf("Results:\n\n");
		printf("Failed buys: %i\n", failedBuys);
		printf("Failed coins: %i\n", failedCoins);
		printf("Failed actions: %i\n", failedActions);
		printf("Hand/Deck Count mismatch: %i\n", failedHands);
		printf("Failed effects: %i\n", failedEffects);
	}
	

	return 0;
}


