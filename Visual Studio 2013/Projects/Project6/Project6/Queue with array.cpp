
#include<stdio.h>

const int MAXSIZE = 10;
int Queue[100];
int top = -1, bottom = -1;

int isFull(); int isEmpty(); void enQueue(int data); void deQueue(); void display();

void main()
{
	int choice;
	int data;

	while (1)
	{
		puts("Enter '1' to insert..");
		puts("Enter '2' to delete..");
		puts("ENter '3' to display..");
		puts("Enter '0' to end this program..\n");
		printf("Input: ");

		scanf_s("%d", &choice);

		if (choice == 1)
		{
			printf("Input data: ");
			scanf_s("%d", &data);
			enQueue(data);
		}
		else if (choice == 2)
		{
			deQueue();
			puts("Deleted!!");
			
				
		}
		else if (choice == 3)
		{
			
				display();
		}
		else if (choice == 0)
		{
			break;
		}
		else
		{
			puts("Invalid input!!");
		}
	}

}

int isFull()
{
	if (MAXSIZE -1 == top)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty()
{
	if (top ==-1 && bottom == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enQueue(int data)
{
	if (isFull())
	{
		puts("Queue is full.Couldn't insert data!!");
		return;
	}
	else if (bottom == -1)
	{
		bottom = top = 0;
	}
	else
	{
		top = (top + 1) % MAXSIZE;
	}
	Queue[top] = data;
}

void deQueue()
{
	if (isEmpty())
		puts("Queue is empty.couldn't delete data!!");

	else if (top == bottom)
	{
		top = bottom = -1;
	}
	else
	{
		bottom = (bottom + 1) % MAXSIZE;
	}

}

void display()
{
	if (top == -1)
	{
		puts("Queue is empty.couldn't display data!!");
	}
	else
	{
		puts("Displaying Elements:");
		for (int i = bottom; i <= top; i++)
		{
			printf("%d\n", Queue[i]);
		}
	}
}
