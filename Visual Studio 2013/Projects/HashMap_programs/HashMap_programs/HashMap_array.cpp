
#include<stdio.h>
#include<string.h>

const int MAXSIZE = 26;
struct hash
{
	char data[50];
}hashTable[MAXSIZE];
int last = 0;

//Adding
void add(char data[])
{
	int hashIndex = data[0] - 'A';
	while (strcmp(hashTable[hashIndex].data, "") != 0 && strcmp(hashTable[hashIndex].data, "empty") != 0)
	{
		hashIndex++;
	}
	strcpy_s(hashTable[hashIndex].data, data);
}

//Searching
int search(char data[])
{
	int hashIndex = data[0] - 'A';
	for (int i = hashIndex; i < MAXSIZE;i++)
	{
		if (strcmp(hashTable[i].data, data) == 0)
		{
			return 1;
		}
	}
	return 0;
}

//Deleting
int deletee(char data[])
{
	int hashIndex = data[0] - 'A';
	for (int i = hashIndex; i < MAXSIZE; i++)
	{
		if (strcmp(hashTable[i].data, data) == 0)
		{
			strcpy_s(hashTable[i].data, "empty");
			return 1;
		}
	}
	return 0;
}

//Display
void display()
{
	//puts("\n");
	for (int i = 0; i < MAXSIZE; i++)
	{
		puts(hashTable[i].data);
	}
}

void main()
{
	char choice[50];
	char data[50];
	while (true)
	{
		puts("||...................||");
		puts("Use 'insert' to insert..");
		puts("Use 'delete' to delete");
		puts("Use 'search' to search");
		puts("Use 'display' to display");
		puts("Use 'quite' to quite");
		puts("||...................||\n");

		scanf_s("%s", &choice, sizeof(choice));

		if (strcmp(choice, "insert") == 0)
		{
			scanf_s("%s", &data, sizeof(data));
			add(data);
		}
		else if (strcmp(choice, "search") == 0)
		{
			scanf_s("%s", &data, sizeof(data));
			if (search(data))
				puts("Searched data found!!");
			else
				puts("Searched data is not in the table!!");
		}
		else if (strcmp(choice, "delete") == 0)
		{
			scanf_s("%s", &data, sizeof(data));

			if (deletee(data))
				puts("empty!!");
			else
				puts("Data not found in the Hash table!");

		}
		else if (strcmp(choice, "display") == 0)
		{
			display();
		}
		else if (strcmp(choice, "quite") == 0)
		{
			puts("\n||\\\\\\\\\\\\\\\\\\||");
			puts("PROGRAM ENDED!!");
			break;
		}
		puts("\n");
	}
}