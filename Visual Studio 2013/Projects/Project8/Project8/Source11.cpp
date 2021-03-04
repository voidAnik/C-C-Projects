#include<stdio.h>
#include<math.h>
#define SIZE 100

int wallpoints[SIZE];
int lengths[SIZE];

int solve(int n, int h)
{
	int maxLadder = h;
	for (int i = 0; i < n; i++)
	{
		int tempLadder = ceil(wallpoints[i] - (lengths[i] / 4)) - h;

		if (tempLadder > maxLadder)
		{
			maxLadder = tempLadder;
		}
	}
	return maxLadder;
}

int main()
{
	int n = 0, h = 0;

	scanf("%d%d", &n, &h);
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &wallpoints[i]);
	}
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &lengths[i]);
	}
	int Ladder = solve(n, h);
	printf("%d", Ladder);
}
