
#include<stdio.h>
#include<string.h>
const int SIZE = 1000;
struct data {
	char name[20];
	char id[20];
	float cgpa;
};

struct data students[SIZE];
int count=0;
void menu()
{
		printf("\nPress '1' to input student data.\n");
		printf("Press '2' to search student data.\n");
		printf("press '0' to quite this program.\n\n");
}
void input()
{ 
	getchar();
	printf("Input the name : ");
	gets_s(students[count].name);
	printf("Input the id : ");
	gets_s(students[count].id);
	printf("Input the cgpa : ");
	scanf_s("%f",&students[count].cgpa);
	getchar();
	count++;
}
void search()
{
	char searchid[20];
	getchar();
	printf("Input the ID:");
	gets_s(searchid);
	for (int i = 0; i < count; i++)
	{
		if (strcmp(students[i].id,searchid)==0)
		{
			printf("Name:");
			puts(students[i].name);
			printf("ID:");
			puts(students[i].id);
			printf("CGPA:%.2f",students[i].cgpa);
			printf("\n\n");
		}
	}
}

void main()
{
	while (1)
	{
		int select;
		menu();
		scanf_s("%d", &select);
		if (select == 1)
		{
			input();
		}
		if (select == 2)
		{
			search();
		}
		if (select == 0)
		{
			puts("Good Bye\n");
			break;
		}
	}
}