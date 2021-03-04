#include<stdio.h>
#include<string.h>
struct student{
	char name[100];
	int id;
	float cgpa;
};
void main()
{
	struct student students[100];
	int i,n;
	scanf_s("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets_s(students[i].name);
		scanf_s("%d", &students[i].id); 
		scanf_s("%f", &students[i].cgpa);
		getchar(); 
	}
	int index;
	float min = students[0].cgpa;
	for (i = 0; i < n; i++)
	{
		if (students[i].cgpa<min)
		{
			min = students[i].cgpa;
			index = i;
		}
	}
	puts(students[index].name);
	printf("%d", students[index].id);
	printf("%.2f", min);

}
