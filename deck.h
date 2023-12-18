#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * enum kind_e - Playing card suits
 *
 * @SPADE: Spade playing card suit
 * @HEART: Heart playing card suit
 * @CLUB: Club playing card suit
 * @DIAMOND: Diamond playing card suit
 */
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

/* ====================== Sort deck Function ====================== */
int card_value_to_int(const char *value);
int card_compare(const void *a, const void *b);
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
