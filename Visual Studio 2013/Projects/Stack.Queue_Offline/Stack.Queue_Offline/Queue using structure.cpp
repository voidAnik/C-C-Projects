/*
#include<stdio.h>

const int MAXSIZE = 5;
struct Qu{
	int memory[100];
	int top = -1, bottom = -1;
}queue;

//
int isFull(); int isEmpty(); void enQueue(int data); void deQueue(); void display();
void multiPush(int tempIn[], int size); void deQueueMIn(); void search(int value);

void main()
{
	int choice;
	int data;

	while (1)
	{
		puts("\n\nEnter '1' to insert..");
		puts("Enter '2' to delete..");
		puts("Enter '3' to display..");
		puts("Enter '4' to multiEnqueue..");
		puts("Enter '5' to Dequeue minimum element..");
		puts("Enter '6' to search element..");
		puts("Enter '0' to end this program..\n");
		puts("....................||\n");
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
		}
		else if (choice == 3)
		{

			display();
		}
		else if (choice == 4)
		{
			int size, tempIn[100];
			printf("How many push:");
			scanf_s("%d", &size);
			puts("Input Elements::");
			for (int i = 0; i < size; i++)
			{
				scanf_s("%d", &tempIn[i]);
			}
			multiPush(tempIn, size);
		}
		else if (choice == 5)
		{
			deQueueMIn();
		}
		else if (choice == 6)
		{
			int value;
			printf("Input element to search:");
			scanf_s("%d", &value);
			search(value);
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
	if ((MAXSIZE - 1 == queue.top && queue.bottom==0)|| (queue.bottom == queue.top + 1))
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
	if (queue.top == -1 && queue.bottom == -1)
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
	else if (queue.top == -1)
	{
		queue.bottom = 0;
		queue.top = 0;
	}
	else if (queue.top == MAXSIZE - 1 && queue.bottom>0)
	{
		queue.top = 0;
	}
	else
	{
		queue.top++;
	}
	queue.memory[queue.top] = data;
	puts("Data inserted!!");
	
}

void deQueue()
{
	if (isEmpty())
	{
		puts("Queue is empty.couldn't delete data!!");
	}
	else if (queue.top == queue.bottom)
	{
		printf("%d DELETED!!\n", queue.memory[queue.bottom]);
		queue.top = -1;
		queue.bottom = -1;
	}
	else
	{
		printf("%d DELETED!!\n", queue.memory[queue.bottom]);
		queue.bottom++;
	}

}

void display()
{
	if (isEmpty())
	{
		puts("Queue is empty.couldn't display data!!");
		return;
	}
	if (queue.bottom > queue.top)
	{
		for (int i = queue.bottom; i < MAXSIZE; i++)
		{
			printf("%d ", queue.memory[i]);
		}
		for (int i = 0; i <= queue.top; i++)
			printf("%d ", queue.memory[i]);
	}
	else
	{
		for (int i = queue.bottom; i <= queue.top; i++)
			printf("%d ", queue.memory[i]);
	}
}

void multiPush(int tempIn[],int size)
{
	for (int i = 0; i < size; i++)
	{
		enQueue(tempIn[i]);
	}
}

void deQueueMIn()
{
	int min = queue.memory[0];
	int minIndex;
	for (int i = 0; i < queue.top; i++)
	{
		if (min> queue.memory[i])
		{
			min = queue.memory[i];
			minIndex = i;
		}
	}
	queue.memory[minIndex] = -1;
}
void search(int value)
{
	int found = 0;
	for (int i = 0; i < queue.top; i++)
	{
		if (value == queue.memory[i])
		{
			found = 1;
		}
	}
	if (found==1)
		puts("Element found!!");
}
*/