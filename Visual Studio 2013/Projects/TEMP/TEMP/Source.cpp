// C/C++ program to find union and intersection of two unsorted 
// linked lists
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

/* A utility function to insert a node at the beginning of
a linked list*/
void push(struct Node** head_ref, int new_data);

/* A utility function to check if given data is present in a list */
bool isPresent(struct Node *head, int data);


/* Function to get intersection of two linked lists
head1 and head2 */
struct Node *getIntersection(struct Node *head1,
struct Node *head2, struct Node *head3)
{
	struct Node *result = NULL;
	struct Node *t1 = head1;


	// Traverse list1 and search each element of it in
	// list2. If the element is present in list 2,
	//If the element is present in list 3,then
	// insert the element to result
	while (t1 != NULL)
	{
		if (isPresent(head2, t1->data))
			push(&result, t1->data);
		t1 = t1->next;

		if (isPresent(head3, t1->data))
			push(&result, t1->data);
		t1 = t1->next;

	}

	/*while (t1 != NULL)
	{
	if (isPresent(head3, t1->data))
	push(&result, t1->data);
	t1 = t1->next;
	}*/



	return result;
}

/* A utility function to insert a node at the begining of a linked list*/
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* A utility function to print a linked list*/
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/* A utility function that returns true if data is
present in linked list else return false */
bool isPresent(struct Node *head, int data)
{
	struct Node *t = head;
	while (t != NULL)
	{
		if (t->data == data)
			return 1;
		t = t->next;
	}
	return 0;
}

/* Drier program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	struct Node* head3 = NULL;
	struct Node* intersecn = NULL;



	push(&head1, 1);
	push(&head1, 2);
	push(&head1, 3);
	push(&head1, 4);

	/*create a linked lits 8->4->2->10 */
	push(&head2, 1);
	push(&head2, 2);
	push(&head2, 6);
	push(&head2, 8);

	push(&head3, 1);
	push(&head3, 2);
	push(&head3, 9);
	push(&head3, 8);


	intersecn = getIntersection(head1, head2, head3);


	printf("\n First list is \n");
	printList(head1);

	printf("\n Second list is \n");
	printList(head2);

	printf("\n Third list is \n");
	printList(head3);

	printf("\n Intersection list is :  ");
	printList(intersecn);
	printf("\n");

	return 0;
}