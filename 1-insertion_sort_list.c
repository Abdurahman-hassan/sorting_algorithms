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
 * head_2_beg - make the first node head
 *
 * @list: the head of the linked list
 */
void head_2_beg(listint_t **list)
{
	while ((*list)->prev)
		(*list) = (*list)->prev;
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
	head_2_beg(head);
	print_list(*head);
}

/**
 * insertion_sort_list - implementation of insertion sort algorithm
 *
 * @list: the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *nxt;
	if (!list || !(*list) || !(*list)->next)
		return;
	curr = *list;
	while (curr)
	{
		nxt = curr->next;
		while (curr->prev && (curr->n < curr->prev->n))
			swap_and_print(curr->prev, curr, list);
		curr = nxt;
	}
}
