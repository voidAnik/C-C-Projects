#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int data=-1;
	struct node *next;
}*head;

node* create_node()
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = -1;
	temp->next = NULL;
	return temp;
}
void main()
{
	char choice[50];
	char word[50];
	struct node *right;
	right = head;
	puts("Enter choice:");
	scanf_s("%s", choice,sizeof(choice));

	scanf_s("%s", word, sizeof(choice));

	if (strcmp(choice, "insert") == 0)
	{
		for (int i = 10; i <= 100; i += 10)
		{
			/*struct node *temp = (struct node*)malloc(sizeof(struct node));*/
			struct node *temp = new_node();
			temp->data = i;
			temp->next = NULL;
			if (head == NULL)
			{
				head = temp;
				right = head;
			}
			else
			{
				right->next = temp;
				right = temp;
			}
		}
	}
	puts("DISPLAY::");
	right = head;
	while (right != NULL)
	{
		printf("%d , ", right->data);
		right = right->next;
	}

}
