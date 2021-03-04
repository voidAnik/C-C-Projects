//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//const int MAXSIZE = 52;
//struct node{
//	char data[50];
//	struct node *next;
//};
//
//struct array{
//	struct node *head;
//}hashTable[MAXSIZE];
//
//
////Creating new node
//node* create_node()
//{
//	struct node *temp = (struct node*)malloc(sizeof(struct node));
//	temp->next = NULL;
//	return temp;
//}
//
////Adding new data
//void add(char data[])
//{
//	int hashIndex = data[0] - 'A';
//	struct node *temp = create_node();
//	strcpy_s(temp->data, data);
//	temp->next = hashTable[hashIndex].head;
//	hashTable[hashIndex].head = temp;
//}
//
////Displaying whole hash map
//void display()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d...>",i+1);
//		struct node *point = hashTable[i].head;
//		while (point != NULL)
//		{
//			printf(" %s--->", point->data);
//			point = point->next;
//		}
//		printf(" NULL\n");
//
//	}
//}
//
////Searching from hash map
//int search(char data[])
//{
//	int hashIndex = data[0] - 'A';
//	struct node *point = hashTable[hashIndex].head;
//	while (point != NULL)
//	{
//		if (strcmp(point->data, data) == 0)
//		{
//			return 1;
//		}
//		point = point->next;
//	}
//	return 0;
//}
//
////Deleting from hash map
//int deletee(char data[])
//{
//	int hashIndex = data[0] - 'A';
//	struct node *prev, *temp;
//	temp = hashTable[hashIndex].head;
//	prev = hashTable[hashIndex].head;
//	while (temp != NULL)
//	{
//		if (strcmp(temp->data, data) == 0)
//		{
//			if (temp == hashTable[hashIndex].head)
//			{
//				hashTable[hashIndex].head = temp->next;
//				free(temp);
//				return 1;
//			}
//			else
//			{
//				prev->next = temp->next;
//				free(temp);
//				return 1;
//			}
//		}
//		else
//		{
//			prev = temp;
//			temp = temp->next;
//		}
//	}
//	return 0;
//}
//
//
//void main()
//{
//	char choice[50];
//	char data[50];
//	while (true)
//	{
//		puts("||...................||");
//		puts("Use 'insert' to insert..");
//		puts("Use 'delete' to delete");
//		puts("Use 'search' to search");
//		puts("Use 'display' to display");
//		puts("Use 'quite' to quite");
//		puts("||...................||\n");
//
//		scanf_s("%s", &choice, sizeof(choice));
//
//		if (strcmp(choice, "insert") == 0)
//		{
//			scanf_s("%s", &data, sizeof(data));
//			add(data);
//		}
//		else if (strcmp(choice, "search") == 0)
//		{
//			scanf_s("%s", &data, sizeof(data));
//			if (search(data))
//				puts("Searched data found!!");
//			else
//				puts("Searched data is not in the table!!");
//		}
//		else if (strcmp(choice, "delete") == 0)
//		{
//			scanf_s("%s", &data, sizeof(data));
//
//			if (deletee(data))
//				puts("Deleted!!");
//			else
//				puts("Data not found in the Hash table!");
//
//		}
//		else if (strcmp(choice, "display") == 0)
//		{
//			display();
//		}
//		else if (strcmp(choice, "quite") == 0)
//		{
//			puts("\n||\\\\\\\\\\\\\\\\\\||");
//			puts("PROGRAM ENDED!!");
//			break;
//		}
//		puts("\n");
//	}
//}