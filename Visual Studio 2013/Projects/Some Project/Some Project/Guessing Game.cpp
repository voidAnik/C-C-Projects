


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
const int SIZE = 100;
char playername[30];
/*It's a guessing game*/
void main()
{
	int i = 0, guess;
	int count = 0, playcount = 0;
	int scores[SIZE];
	char ch;
	puts("\t\tWelcome to guessing GAME :-)\n\t\t<<Created By Anik _Islam>>");
	puts("\npress 'R / r' To read instructions about game & play!\nOR, press 'P / p' or just Enter to skip and start playing game..");
	ch = getchar();
	while (1 == 1)
	{
		count = 0;
		if (ch == 'r' || ch == 'R')//Giving instruction
		{
			printf("There always a hidden number.You have to guess the number.If you guess a wrong  number");
			printf(" it will give you the clue that your guessed number is high or low from   the hidden number.");
			printf("And by this you have to guess the number.It will also give    the scores depend on your tries..\n\n Now ");
			ch = 'p';
		}
		else if (ch == 'p' || ch == 'P' || ch == '\n')
		{
			if (playcount == 0)
			{
				printf("Type Your name_ ");
				gets_s(playername);
				printf("%s lets start Guessing The Number:\n", playername);
			}
			else
			{
				printf("Okay, %s Lets start guessing again :");
			}
			while (1 == 1)
			{
				count++;
				scanf_s("%d", &guess);//taking user guess
				if (guess == random)
				{
					printf("\nWoW!congrats!You found the number in %d tries :-D\n\n", count);
					scores[i] = count;
					i++;
					getchar();
					break;//It will break and terminate this inner loop whenever player is right!
				}
				//Will give player clue
				if (guess<random)
				{
					printf("Your guess is low.Try again! /guessed:%d\n", count);
				}
				if (guess>random)
				{
					printf("Your guess is high.Try again! /guessed:%d\n", count);
				}
			}
			playcount++;
			//Choice for play again or end the game!
			puts("press ''R'' To read instructions about game");
			puts("Press ''P'' or just Enter to play again!!");
			puts("Press ''Q'' and Enter to ESCAPE :-(\n");
			ch = getchar();
		}
		if (ch == 'q' || ch == 'Q')
		{
			if (playcount == 0)
			{
				printf("You played %d times and you didn't make any scores\n\n");
				break;
			}
			else
			{
				printf("Hey, %s You played %d times and tried score is sequentially: ",playername, playcount);
				for (int j = 0; j<playcount; j++)//Will play scores
				{
					if (j == playcount - 1)//for not printing the last comma(,)
					{
						printf("%d", scores[j]);
					}
					else
					{
						printf("%d , ", scores[j]);
					}
				}
				puts("\n\t\tGOOD BYE!!\n\n");
				break;
			}
		}
		else//If the choice is wrong
		{
			puts("Wrong choice..Choice between 'Q/q' and 'P/p' or just enter to play..");
			ch = getchar();
		}
	}
}