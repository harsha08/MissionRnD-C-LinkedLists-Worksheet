/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int get_value(struct node *head,int i)
{
	int c = 0;
	struct node *tmp = NULL;
	for (tmp = head; c<i; tmp = tmp->next, c++);
	return tmp->num;
}
void set_value(struct node *head,int i, int value)
{
	struct node *tmp = NULL;
	int c = 0;
	for (tmp = head; c<i; tmp = tmp->next, c++);

	tmp->num = value;
}

void quicksort(struct node *head,int first, int last)
{
	int pivot, j, temp, i;

	if (first<last)
	{
		pivot = first;
		i = first;
		j = last;


		while (i<j)
		{

			while ((get_value(head,i) <= get_value(head,pivot)) && (i<last))
			{

				i++;
			}
			while (get_value(head,j)>get_value(head,pivot))
			{

				j--;
			}
			if (i<j)
			{
				temp = get_value(head,i);
				set_value(head,i, get_value(head,j));
				set_value(head,j, temp);
				printf("\n%d", j);
			}
		}

		temp = get_value(head,pivot);
		set_value(head,pivot, get_value(head,j));
		set_value(head,j, temp);
		quicksort(head,first, j - 1);
		quicksort(head,j + 1, last);

	}
}

struct node * sortLinkedList(struct node *head) {
	struct node *tmp, *tmp1;
	tmp = head;
	while (tmp != NULL)
	{
		tmp1 = tmp->next;
		while (tmp1 != NULL)
		{
			if (tmp->num>tmp1->num)
			{
				int t = tmp->num;
				tmp->num = tmp1->num;
				tmp1->num = t;
			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return head;
}