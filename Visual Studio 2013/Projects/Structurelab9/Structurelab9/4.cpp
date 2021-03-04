
#include<stdio.h>
struct sub{
	float spl, dm, dld;
};
struct MinMaxAvg{
	sub min, max, avg;
};

struct MinMaxAvg findmaxminavg(float scores[][3], int n);
void Displaylowscores(float scores[][3], int n, struct MinMaxAvg minmaxavg);

void main4()
{
	float scores[100][3];
	int n = 3;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf_s("%f", &scores[i][j]);
		}
	}
	struct MinMaxAvg minmaxavg=findmaxminavg(scores, n);
	printf("MAX of SPL:%f  DM:%f DLD:%f\n", minmaxavg.max.spl, minmaxavg.max.dm, minmaxavg.max.dld);
	printf("MIN of SPL:%f  DM:%f DLD:%f\n", minmaxavg.min.spl, minmaxavg.min.dm, minmaxavg.min.dld);
	printf("Average of SPL:%f  DM:%f DLD:%f\n", minmaxavg.avg.spl, minmaxavg.avg.dm, minmaxavg.avg.dld);
	Displaylowscores(scores, n,minmaxavg);
}

void Displaylowscores(float scores[][3], int n,struct MinMaxAvg minmaxavg)
{
	puts("Above average value:");
	printf("SPL:");
	for (int i = 0; i < n; i++)
	{
		if (scores[i][0]>minmaxavg.avg.spl)
		{
			printf("%f,", scores[i][0]);
		}
	}
	printf("\nDiscrete Math:");
	for (int i = 0; i < n; i++)
	{
		if (scores[i][1]>minmaxavg.avg.dm)
		{
			printf("%f,", scores[i][0]);
		}
	}
	printf("\nDLD:");
	for (int i = 0; i < n; i++)
	{
		if (scores[i][2]>minmaxavg.avg.dld)
		{
			printf("%f,", scores[i][0]);
		}
	}
}

struct sub computemax(float scores[][3], int n)
{
	struct sub max;
	max.spl = scores[0][0];
	max.dm = scores[0][1];
	max.dld = scores[0][2];
	for (int i = 0; i < n; i++)
	{
		if (max.spl < scores[i][0])
		{
			max.spl = scores[i][0];
		}
		if (max.dm < scores[i][1])
		{
			max.dm = scores[i][1];
		}
		if (max.dld < scores[i][2])
		{
			max.dld = scores[i][2];
		}

	}
	return max;
}

struct sub computemin(float scores[][3], int n)
{
	struct sub min;
	min.spl = scores[0][0];
	min.dm = scores[0][1];
	min.dld = scores[0][2];
	for (int i = 0; i < n; i++)
	{
		if (min.spl > scores[i][0])
		{
			min.spl = scores[i][0];
		}
		if (min.dm > scores[i][1])
		{
			min.dm = scores[i][1];
		}
		if (min.dld > scores[i][2])
		{
			min.dld = scores[i][2];
		}

	}
	return min;
}

struct sub computeavg(float scores[][3], int n)
{
	struct sub avg;
	float t1=0, t2=0, t3=0;
	for (int i = 0; i < n; i++)
	{
		t1 += scores[i][0];
		t2 += scores[i][0];
		t3 += scores[i][0];
	}
	avg.spl = t1 / n;
	avg.dm = t2 / n;
	avg.dld = t3 / n;
	return avg;
}

struct MinMaxAvg findmaxminavg(float scores[][3], int n)
{
	struct MinMaxAvg minmaxavg;
	minmaxavg.max = computemax(scores, n);
	minmaxavg.min = computemin(scores, n);
	minmaxavg.avg = computeavg(scores, n);
	return minmaxavg;
}