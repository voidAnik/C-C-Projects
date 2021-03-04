//
//#include<stdio.h>
//
//const int MAXSIZE = 2;
//struct st{
//	int memory[100];
//	int top = -1;
//}stack;
//
//int isFull(); int isEmpty(); void push(int data); int pop(); int peek();
//
//void main()
//{
//	int choice;
//	int data;
//
//	while (1)
//	{
//		puts("Enter '1' to push..");
//		puts("Enter '2' to pop..");
//		puts("ENter '3' to just peek..");
//		puts("Enter '4' to end this program..\n");
//		puts(".......................||\n");
//		printf("Input: ");
//
//		scanf_s("%d", &choice);
//
//		if (choice == 1)
//		{
//			printf("Input data: ");
//			scanf_s("%d", &data);
//			push(data);
//		}
//		else if (choice == 2)
//		{
//
//			if (!isEmpty())
//			{
//				printf("Retrived data: %d\n", pop());
//			}
//			else
//			{
//				puts("Stack is empty.couldn't retrive data!!");
//			}
//		}
//		else if (choice == 3)
//		{
//			if (!isEmpty())
//			{
//				printf("peeked top data: %d\n", peek());
//			}
//			else
//			{
//				puts("Stack is empty.couldn't peeked data!!");
//			}
//		}
//		else if (choice == 4)
//		{
//			break;
//		}
//		else
//		{
//			puts("Invalid input!!");
//		}
//	}
//
//}
//
//int isFull()
//{
//	if (MAXSIZE == stack.top + 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int isEmpty()
//{
//	if (stack.top <= -1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//void push(int data)
//{
//	if (!isFull())
//	{
//		stack.top++;
//		stack.memory[stack.top] = data;
//	}
//	else
//	{
//		puts("Stack is full.Couldn't insert data!!");
//	}
//}
//
//int pop()
//{
//	if (!isEmpty())
//	{
//		int data = stack.memory[stack.top];
//		stack.top--;
//		return data;
//	}
//
//}
//
//int peek()
//{
//	if (!isEmpty())
//	{
//		return stack.memory[stack.top];
//	}
//}
//
