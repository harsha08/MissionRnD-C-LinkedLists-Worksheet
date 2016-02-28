/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	struct node *tmp = NULL,*prev=NULL;
	int i = 0;
	tmp = prev = head;
	if (K <= 0)
	{
		return NULL;
	}
	while (tmp != NULL)
	{
		i++;
		if (i != K)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		else if (i == K)
		{
			if (tmp == head)
			{
				tmp = tmp->next;
				free(prev);
				head = prev = tmp;
			}
			else
			{
				prev->next = tmp->next;
				free(tmp);
				tmp = prev->next;
			}
			i = 0;
		}
	}
	
	return head;
}