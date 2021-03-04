#include<stdio.h>
#include<stdio.h>
#include<string.h>
struct highScores{
	char name[20];
	int score;
};
FILE *file;
highScores highScorer[100] = { { NULL }, { 0 } };
void main6789()
{
	int i = 0;
	fopen_s(&file, "Scoress.txt", "r+");
	while (!feof(file))
	{
		fscanf_s(file, "%s", highScorer[i].name, 30);
		fscanf_s(file, "%d", highScorer[i].score);
		if (i == 3)
			break;
		i++;
	}
	fclose(file);
}