/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	struct node *tmp;
	int countof2 = 0, countof0 = 0, countof1 = 0, len = 0;
	for (tmp = head; tmp != NULL; tmp = tmp->next)
	{
		if (tmp->data == 2)
		{
			countof2++;
		}
		else
		{
			countof1 += tmp->data;
		}
		len++;
	}	
	countof0 = len-(countof2 + countof1);	

	for (tmp = head; countof0>0; tmp = tmp->next,countof0--)
	{
		tmp->data = 0;
	}
	for (; countof1>0; tmp = tmp->next, countof1--)
	{
		tmp->data = 1;
	}
	for (; countof2>0; tmp = tmp->next, countof2--)
	{
		tmp->data = 2;
	}
}