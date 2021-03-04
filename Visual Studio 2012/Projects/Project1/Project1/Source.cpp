#include <stdio.h>
struct student
{
	char name[50];
	int roll;
	char address[50];
	char Class[10];
};

void main()
{
	struct student students[3];
	printf("Enter information:\n");
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("Enter name: ");
		gets(students[i].name);
		printf("Enter Address: ");
		gets(students[i].address);
		printf("Enter Class: ");
		gets(students[i].Class);
		printf("Enter roll number: ");
		scanf("%d", &students[i].roll);
		getchar();
	}
	printf("Displaying Information:\n");
	for (i = 0; i < 3; i++)
	{
		printf("Name: ");
		puts(students[i].name);
		printf("Address: ");
		puts(students[i].address);
		printf("Class: ");
		puts(students[i].Class);
		printf("Roll number: %d\n", students[i].roll);
	}
}