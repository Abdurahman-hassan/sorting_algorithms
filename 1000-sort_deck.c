#include "deck.h"

/**
 * card_value_to_int - Convert card values to integers for sorting
 * @value: The value of the card as a string
 * Return: The integer value of the card for sorting purpose
 */
int card_value_to_int(const char *value)
{
	if (strcmp(value, "Ace") == 0)
		return (1);
	if (strcmp(value, "King") == 0)
		return (13);
	if (strcmp(value, "Queen") == 0)
		return (12);
	if (strcmp(value, "Jack") == 0)
		return (11);
	return (atoi(value)); /* For numeric cards, convert string to integer */
}

/**
 * card_compare - Comparison function for sorting cards
 * @a: Pointer to the first deck_node_t object
 * @b: Pointer to the second deck_node_t object
 * This function is used by qsort to compare two cards.
 * Cards are compared first by kind, then by value.
 * Return: Difference between the cards based on kind and value
 */
int card_compare(const void *a, const void *b)
{
	const deck_node_t *cardA;
	const deck_node_t *cardB;

	/* Cast the void pointers to deck_node_t pointers */
	cardA = *(const deck_node_t **)a;
	cardB = *(const deck_node_t **)b;

	/* Compare the cards first by kind, then by value */
	if (cardA->card->kind != cardB->card->kind)
		return (cardA->card->kind - cardB->card->kind);
	return (card_value_to_int(
				cardA->card->value) - card_value_to_int(cardB->card->value));
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Double pointer to the head
 * of a doubly linked list of deck_node_t objects
 * This function sorts a deck of cards
 * in ascending order first by card kind (suit),
 * then by card value. It converts the linked list into an array for sorting,
 * and then reconstructs the linked list.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;
	deck_node_t **array;
	size_t length;
	size_t i;

	length = 0;
	current = *deck;

	if (!deck || !*deck)
		return;

	while (current)
	{
		length++;
		current = current->next;
	}
	array = (deck_node_t **)malloc(length * sizeof(deck_node_t *));
	if (!array)
		return; /* Handle memory allocation failure */

	current = *deck;
	/* Copy the nodes into the array */
	for (i = 0; i < length; i++)
	{
		array[i] = current;
		current = current->next;
	}
	/* Sort the array using qsort */
	qsort(array, length, sizeof(deck_node_t *), card_compare);
	/* Rebuild the linked list with sorted nodes */
	for (i = 0; i < length - 1; i++)
	{
		array[i]->next = array[i + 1];
		array[i + 1]->prev = array[i];
	}
	/* Set the head and tail of the linked list */
	array[0]->prev = NULL;
	array[length - 1]->next = NULL;
	*deck = array[0];
	free(array);
}
