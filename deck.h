#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct values_s - this represents card values
 *
 * @name: this will be the name of the cards value
 * @val: this will be the numeric value of the card
 */
typedef struct values_s
{
	char *name;
	int val;
} values_t;

/**
 * enum kind_e - this will be the enumeration of the card suits
 *
 * @SPADE: this will represent  the spade suite
 * @HEART: this will represent the heart suit
 * @CLUB: this will represent the club suit
 * @DIAMOND: this will represent the diamond suit
 *
 * Description: It will define the feasible suits of a standard deck
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART = 1,
	CLUB = 2,
	DIAMOND = 3
} kind_t;

/**
 * struct card_s -this will be the playing cards
 *
 * @value: this will be the cards value
 * @kind: this will be the kind of card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - this will be a deck of cards
 *
 * @card: this will be a pointer to the card
 * @prev: this will be a pointer to the first node in the list
 * @next: this will be the pointer to the following node in the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif
