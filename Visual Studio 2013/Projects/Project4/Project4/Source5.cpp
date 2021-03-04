#include<stdio.h>
#include<string.h>
struct highScores{
	char name[20];
	int score;
};
void main567()
{
	FILE *fp;
	highScores scores[100] = { { NULL }, {0} };
	char n[20] = { "kama" };
	int num = 80, i = 0;
	highScores temp;
	fopen_s(&fp, "Scores.txt", "r+");
	while (!feof(fp))
	{
		fscanf_s(fp, "%s", scores[i].name, 10);
		fscanf_s(fp, "%d", &scores[i].score);
		puts(scores[i].name);
		printf("%d\n", scores[i].score);
		if (i == 3)
			break;
		i++;
	}
	puts("\n ....");
	for (int i = 0; i < 4; i++)
	{
		if (num>scores[i].score)
		{/*
			strcpy(temp.name, scores[i].name);
			temp.score = scores[i].score;
			strcpy(scores[i].name, n);
			scores[i].score = num;
			*/
			for (int j = 4; j >= i; j--)
			{
				strcpy(scores[j + 1].name, scores[j].name);
				scores[j + 1].score = scores[j].score;
			}
			strcpy(scores[i].name, n);
			scores[i].score = num;
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		puts(scores[i].name);
		printf("%d\n", scores[i].score);
		
	}
	//puts(name);

	fclose(fp);
}