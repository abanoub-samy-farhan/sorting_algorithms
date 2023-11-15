#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	int n;
	listint_t *tmp, *list2 = *list;

	while(list2 != NULL)
	{
		n = 1;
		while (n)
		{
			tmp = list2;
			n = is_not_ordered(tmp, list);
			if (n == 1)
			{
				print_list(*list);
			}
			tmp = tmp->prev;
		}
		list2 = list2->next;
	}
}

int is_not_ordered(listint_t *list, listint_t **head)
{
	listint_t *node1, *node2, *next1, *prev2;
	if (list->prev == NULL)
	{
		return 0;
	}
	if (list->n < list->prev->n)
	{
		node1 = list;
		next1 = list->next;
		node2 = list->prev;
		prev2 = list->prev->prev;
		if (prev2 != NULL)
		{
			prev2->next = node1;
		}
		else
		{
		      *head = node1;
		}
		if (next1 != NULL)
		{
			next1->prev = node2;
		}
		node1->prev = prev2;
		node2->next = next1;
		node1->next = node2;
		node2->prev = node1;
		return (1);
	}
	return (0);
}
