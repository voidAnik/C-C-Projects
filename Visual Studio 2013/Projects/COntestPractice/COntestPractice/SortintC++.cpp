#include<stdio.h>
#include<algorithm>
using namespace std;

#define SIZE 100
float sTime[SIZE];

int cmp(float a, float b)
{
	return(b < a);
}
int main()
{
	int n, k;
	scanf_s("%d%d", &n, &k);
	for (int i = 0; i < k; i++)
	{
		scanf_s("%f", &sTime[i]);
	}
	sort(sTime, sTime + k, cmp);

	for (int i = 0; i < k;i++)
	{
		printf("%.1f ", sTime[i]);
	}

}