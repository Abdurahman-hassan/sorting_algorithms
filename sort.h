#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* ====================== utilities Functions ====================== */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* ====================== Bubble sort Function ====================== */
void bubble_sort(int *array, size_t size);

/* ====================== Insertion sort Function ====================== */
void swap_nodes(listint_t *node1, listint_t *node2);
void head_2_beg(listint_t **list);
void swap_and_print(listint_t *node1, listint_t *node2, listint_t **head);
void insertion_sort_list(listint_t **list);

/* ====================== Selection sort Function ====================== */
void selection_sort(int *array, size_t size);

/* ====================== Quick sort Function ====================== */
void swap(int *f, int *s);
ssize_t partition(int *arr, ssize_t start, ssize_t end, size_t sz);
void real_quick(int *arr, ssize_t lo, ssize_t hi, size_t sz);
void quick_sort(int *arr, size_t size);

/* ====================== Shell sort Function ====================== */
void shell_sort(int *array, size_t size);


void cocktail_sort_list(listint_t **list);
void quick_sort_hoare(int *arr, size_t size);

#endif
