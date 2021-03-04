
#include<stdio.h>
#include<string.h>
struct Empinfo{
	char name[50];
	char Email[50];
	char password[50];
	char Hdegree[10], passyear[10];
	float cgpa;
	float test;
};
const int size = 100;
void main1234()
{
	struct Empinfo employers[size];
	int n = 3;
	for (int i = 0; i < n; i++)
	{
		gets_s(employers[i].name);
		gets_s(employers[i].Email);
		gets_s(employers[i].password);
		gets_s(employers[i].Hdegree);
		gets_s(employers[i].passyear);
		scanf_s("%f%f", &employers[i].cgpa, &employers[i].test);
		getchar();
		employers[i].test += (employers[i].cgpa * 10);
	}
	printf("Give a Email and password :\n");
	char tempEmail[50];
	char tempPassword[50];
	gets_s(tempEmail);
	gets_s(tempPassword);
	for (int i = 0; i < n; i++)
	{
		if ((strcmp(tempEmail, employers[i].Email) == 0) && (strcmp(tempPassword, employers[i].password) == 0))
		{
			printf("Total marks of your test:%f\n", employers[i].test);
		}
	}
}