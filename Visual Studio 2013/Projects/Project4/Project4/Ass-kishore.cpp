#include <stdio.h>
#include <stdlib.h>

void main34()
{
	int N, i, j, count = 0;
	char str[10][100];
	scanf_s("%d", &N);
	getchar();

	for (i = 0; i<N; i++)
	{
		j = 0;
		while (1)
		{
			str[i][j] = getchar();
			if (str[i][j] == '\n' )
			{
				j++;
				break;
			}
			j++;
		}
		str[i][j] = NULL;
	}

	// 1 = 2
	// 2, 3, 5 = 5
	// 4 = 4
	// 6, 9, 0 = 6
	// 7 = 3
	// 8 = 7


	for (i = 0; i<N; i++){
		count = 0;
		for (j = 0; str[i][j] != '\0'; j++){
			if (str[i][j] == '1'){
				count = count + 2;
			}
			if (str[i][j] == '2' || str[i][j] == '3' || str[i][j] == '5'){
				count = count + 5;
			}
			if (str[i][j] == '4'){
				count = count + 4;
			}
			if (str[i][j] == '6' || str[i][j] == '9' || str[i][j] == '0'){
				count = count + 6;
			}
			if (str[i][j] == '7'){
				count = count + 3;
			}
			if (str[i][j] == '8'){
				count = count + 7;
			}
		}
		printf("\n%d leds\n", count);
	}
}