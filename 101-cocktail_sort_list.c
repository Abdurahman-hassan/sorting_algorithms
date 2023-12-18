#include "sort.h"

/**
 * swap_nodes - swap 2 nodes
 *
 * @node1: 1st node
 * @node2: 2nd node
 */

void swap_nodes(listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
}


/**
 * swap_and_print - swap 2 nodes then print the linked list
 *
 * @node1: 1st node
 * @node2: 2nd node
 * @head: the head of the linked list
 */
void swap_and_print(listint_t *node1, listint_t *node2, listint_t **head)
{
	swap_nodes(node1, node2);
	while ((*head)->prev)
		(*head) = (*head)->prev;
	print_list(*head);
}

/**
 * go - it's a round of bubble sort algorithm
 *
 * @last_back: the first node in the round
 * @last_go: the last node in the round
 * @head: the head of the linked list
 *
 * Return: count of swaps happened in this round
 */
int go(listint_t *last_back, listint_t **last_go, listint_t **head)
{
	int swap_counter = 0;

	while (last_back->next != *last_go)
	{
		if (last_back->n > last_back->next->n)
			swap_and_print(last_back, last_back->next, head), swap_counter++;
		else
			last_back = last_back->next;
	}
	(*last_go) = last_back;
	return (swap_counter);
}

/**
 * back - it's a round of selection sort algorithm
 *
 * @last_back: the last node in the round
 * @last_go: the first node in the round
 * @head: the head of the linked list
 *
 * Return: count of swaps happened in this round
 */
int back(listint_t **last_back, listint_t *last_go, listint_t **head)
{
	int swap_counter = 0;

	while (last_go->prev != *last_back)
	{
		if (last_go->n < last_go->prev->n)
			swap_and_print(last_go->prev, last_go, head), swap_counter++;
		else
			last_go = last_go->prev;
	}
	(*last_back) = last_go;
	return (swap_counter);
}

/**
 * cocktail_sort_list - implementation of cocktail sort algorithm
 *
 * @list: the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *last_go = NULL, *last_back = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;
	if (!go(*list, &last_go, list))
		return;
	if (!back(&last_back, last_go, list))
		return;
	while (last_go != last_back)
	{
		if (!go(*list, &last_go, list))
			return;
		if (last_go == last_back)
			return;
		if (!back(&last_back, last_go, list))
			return;
	}
}
