#include<stdio.h>
int top = -1, max=4,bottom = -1;
int A[100];
void enqueue(int data)
{
	if (top == max - 1)
	{
		printf("Overloaded");
	}
	else if (top == -1)
	{
		top = 0;
		A[top] = data;
	}
	else
	{
		top++;
		A[top] = data;
	}
}
void dequeue()
{
	if (top = -1)
	{
		printf("Empty");
	}
	else if (bottom == top)
	{
		bottom = top = -1;
	}
	else
	{
		bottom = bottom + 1;
	}
}
void main()
{
	int A[100], i, j, n;
	//scanf_s("%d", &n);
	enqueue(1);
	enqueue(2);
	enqueue(3);
	dequeue();
	for (int i = bottom; i < top; i++)
	{
		printf("%d ,", A[i]);
	}

}