/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	struct node *head = NULL, *ptr = NULL, *tmp = NULL;
	int r;
	if (N == 0)
	{
		head = (struct node *)malloc(sizeof(struct node));
		head->num = 0;
		head->next = NULL;
	}
	else
	{
		if (N < 0)
		{
			N = -N;
		}
		while (N != 0)
		{
			r = N % 10;
			N = N / 10;

			ptr = (struct node *)malloc(sizeof(struct node));
			ptr->num = r;
			ptr->next = NULL;
			if (head == NULL)
			{
				head = ptr;
			}
			else
			{
				ptr->next = head;
				head = ptr;
			}
		}
		
	}
	return head;
}