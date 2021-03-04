#include<stdio.h>
#include<string.h>
struct Student{
	double id;
	float cgpa;
	char stu[100];
};
void main123()
{
	Student stu[100];
	int n;
	scanf_s("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		gets_s(stu[i].stu);
		scanf_s("%f", &stu[i].cgpa);
		scanf_s("%lf", &stu[i].id);
		getchar();
	}
	float min = stu[0].cgpa;int  index = 0;
	for (int i = 0; i < n; i++)
	{
		if (min>stu[i].cgpa)
		{
			min = stu[i].cgpa;
			index = i;
		}
	}
	puts(stu[index].stu);
	printf("%.2lf\n", stu[index].id);
	printf("%f\n", stu[index].cgpa);



}