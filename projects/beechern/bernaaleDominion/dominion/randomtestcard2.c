/******************************************************************
** Author:  Nicole Beecher
** Assignment:   Assignment 4 Test Smithy

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
int failedDiscards = 0;
int failedDraws = 0;
int failedHands = 0;

void testSmithyCard(int players, struct gameState *game) {
	int cardEffectTest, draw1, draw2, draw3, discardTest, initHandCount, postHandCount, initDeckCount, postDeckCount;
	int bonus = 0;

	struct gameState initial;
	//copy the passed in randGameame state to initialState
	memcpy(&initial, game, sizeof(struct gameState));

	//call the card effect function
	cardEffectTest = cardEffect(smithy, 0, 0, 0, game, 0, &bonus);
	//check
	if (cardEffectTest)
		failedEffects++;

	//player draws 3 cards
	draw1 = drawCard(players, &initial);
	draw2 = drawCard(players, &initial);
	draw3 = drawCard(players, &initial);

	//call discardCard
	discardTest = discardCard(0, players, &initial, 0);
	//check
	if (discardTest)
		failedDiscards++;

	//compare hand and deck
	initHandCount = initial.handCount[players];
	postHandCount = game->handCount[players];
	initDeckCount = initial.deckCount[players];
	postDeckCount = game->deckCount[players];

	//check
	if (draw1 == -1 && initial.deckCount[players] != 0)
		failedDraws++;
	if (draw2 == -1 && initial.deckCount[players] != 0)
		failedDraws++;
	if (draw3 == -1 && initial.deckCount[players] != 0)
		failedDraws++;


	if (!(postHandCount == initHandCount && postDeckCount == initDeckCount))
		failedHands++;
}


int main()
{
	printf("Random test for smithy card\n");

	int seed = 2000;
	int i, j, currentPlayer, totalFailures;

	struct gameState game;
	
	srand(time(NULL));
	

	for (i = 0; i < seed; i++) 
	{
		for (j = 0; j < sizeof(struct gameState); j++)
		{
			((char*)&game)[j] = floor(Random() * 256);
		}
		
		currentPlayer = floor(Random() * MAX_PLAYERS);

		
		game.deckCount[currentPlayer] = floor(Random() * MAX_DECK);
		game.discardCount[currentPlayer] = floor(Random() * MAX_DECK);
		game.handCount[currentPlayer] = floor(Random() * MAX_HAND);
		game.playedCardCount = floor(Random() * (MAX_DECK - 1));
		game.whoseTurn = currentPlayer;
		

		testSmithyCard(currentPlayer, &game);
	}
	
	totalFailures = failedEffects + failedDiscards + failedDraws + failedHands;
	printf("RESULTS for smithy test:\n\n");


	if (totalFailures == 0)
		printf("All Tests Passed\n\n");
	
	else 
	{
		printf("Results by function:\n\n");
		printf("discardCard() failed: %i\n", failedDiscards);
		printf("drawCard() failed: %i\n", failedDraws);
		printf("cardEffect() failed: %i\n", failedEffects);
		printf("Hand/Deck Count mismatch: %i\n", failedHands);
	}



	return 0;
}





