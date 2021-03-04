#include<stdio.h>
#include<stdlib.h>
const int max = 5;
int queue[100], rear = -1, front = -1;

void enqueue(int num)
{
	if ((max - 1 == rear && front == 0) || (front == rear + 1))
	{
		puts("Queue is full");
	}
	else if (front == -1)
	{
		front = 0;			
		rear = 0;
	}
	else
	{	
		rear = (rear + 1) % max;
	}
	queue[rear] = num;
}

void dequeue()
{
	if ((front == -1 && rear == -1) )
	{
		puts("Queue Is Empty");
	}
	else if (front - 1 == rear)
	{
		puts("Queue Is Empty");
		front = -1;
		rear = -1;
	}
	else
	{
		printf("\n%d item has been dequeued\n", queue[front]);
		front = (front + 1) % max;
	}

}

void display()
{
	int i;
	if (front == -1 || front == rear + 1)
	{
		puts("Queue Is Empty");
	}
	if (front > rear)
	{
		for (int i = front; i < max; i++)
		{
			printf("%d ", queue[i]);
		}
		for (int i = 0; i <= rear; i++)
			printf("%d ", queue[i]);
	}
	else
	{
		for (int i = front; i <= rear; i++)
			printf("%d ", queue[i]);
	}
}



void main()
{
	int choice, num;
	printf("1 to ENQUEUE\n2 to DEQUEUE\n3 to DISPLAY\n4 to EXIT\n\n");
	while (1)
	{
		printf("\nEnter the choice you want to make : ");
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			printf("\nEnter the number you want to input : ");
			scanf_s("%d", &num);
			enqueue(num);
		}
		else if (choice == 2)
		{
			dequeue();
		}
		else if (choice == 3)
		{
			display();
		}
		else if (choice == 4)
		{
			break;
		}
		else
			printf("\nInvalid Choice\n");
	}
}
