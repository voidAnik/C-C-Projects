#include <stdio.h>
#include <time.h>
#include <string.h>
#define NUM_WORDS 152

static const char *words[] = { "aas", "aegis", "aka", "ake", "akes", "ash", "ate", "ates", "ave", "avel", "aves",
"eas", "ease", "easel", "eat", "eave", "eaves", "egis", "eisel", "eish", "elm", "elt", "eta", "etas",
"evil", "geat", "geo", "geos", "ghi", "gie", "gies", "gis", "hie", "hies", "hilt", "hive", "hives", "ilea",
"ish", "iso", "ivies", "kaas", "kae", "kaes", "kas", "kat", "kea", "keas", "kelt", "kesh", "ket", "keta",
"ketas", "kevil", "koa", "koas", "kos", "lea", "leak", "leas", "lease", "leash", "leat", "lei", "lek", "les",
"let", "lev", "leva", "lie", "lies", "live", "lives", "mease", "meat", "mel", "melt", "mes", "mesa", "mese", "mesh", "met",
"meta", "oak", "oat", "oaves", "oes", "oka", "okas", "oke", "okes", "okta", "oktas", "ose", "sae", "sake", "sat", "sate", "satem",
"sav", "save", "sea", "seat", "seg", "sei", "seil", "sekt", "sel", "selva", "set", "seta", "setae", "shiel", "shiv", "shiva", "shive",
"sigh", "soak", "soave", "soke", "tae", "tael", "taes", "tak", "taka", "take", "takes", "tao", "taos", "tas", "tash", "tav", "tavs", "tea",
"teak", "teas", "tease", "teil", "tel", "tes", "vae", "vaes", "vas", "vase", "vat", "veil", "vet", "vie", "vies", "vile", "vlei", "vlies" };

char board[5][5] = { ' ', '1', '2', '3', '4',
'1', 'i', 'i', 'l', 'm',
'2', 'h', 'v', 'e', 't',
'3', 'g', 's', 'a', 'k',
'4', 'i', 'e', 'o', 'a' };

char pword[100][10];
int unum = 0;
//Function Header
void check();

int convertToSecond(int h, int m, int s){
	return h * 3600 + m * 60 + s;
}

int main() {
	unsigned int count = 0;
	int row, col;
	time_t t = time(NULL);
	struct tm start_time = *localtime(&t);
	int total_seconds = 0;
	int move = 1;

	//sample printing of words
	int i;
	for (i = 0; i < NUM_WORDS; i++){
		printf("%s ", words[i]);
	}
	printf("\n");
	while (1){
		printf("PLAYING MOVE #%d\n", move);
		//Showing the board
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				printf("% c ", board[i][j]);
			}
			puts("");
		}
		printf("Enter your move:-\n");
		//Taking inputs
		int N;
		int j;
		int x = 0, y = 0;
		for ( j = 0; j < 10; j++)
		{
			N = 0;
			scanf("%d %d", &row, &col);
			//printf("% c", board[row][col]);
			if (row == 0 && col == 0)
			{
				pword[unum][j] = NULL;
				break;
			}
			if (row == -1 && col == -1)
			{
				break;
			}
			if ((row == x && col == y - 1) || (row == x && col == y + 1) || (row == x - 1 && col == y - 1) || (row == x - 1 && col == y) 
				|| (row == x - 1 && col == y + 1) || (row == x + 1 && col == y - 1) || (row == x + 1 && col == y) 
				|| (row == x + 1 && col == y + 1) || (j==0))
			{
				pword[unum][j] = board[row][col];
				printf("\n% c\n", pword[unum][j]);
			}
			else
			{
				N = 1;
				break;
			}
			x = row;
			y = col;
		}
		if (N == 1)
		{
			printf("Invalid move\n");
		}

		else if (row == -1 && col == -1){
			t = time(NULL);
			struct tm end_time = *localtime(&t);
			total_seconds = (convertToSecond(end_time.tm_hour, end_time.tm_min, end_time.tm_sec) - convertToSecond(start_time.tm_hour, start_time.tm_min, start_time.tm_sec));
			break;
		}
		else if (j < 3)
		{
			printf("Invalid chain! length of chain is less than 3\n");
		}

		else
		{
			check();
		}

		/*else {
			printf("Okay, enter row, col again.\n");*/
		move++;
	}
	printf("The end.\n");
	printf("Total time taken: %d seconds.\n", total_seconds);
}

void check()
{
	int D = 0;
	int F = 0;
	printf("Word: %s\n", pword[unum]);
	for (int i = 0; i < NUM_WORDS; i++)
	{
		for (int j = 0; j < unum; j++)
		{
			if (strcmp(pword[j], pword[unum]) == 0)
			{
				printf("This word is already been used");
				F = 1;
				D = 1;
				break;
			}
		}
		if (F == 1){ break; }
		if (strcmp(words[i], pword[unum]) == 0)
		{
			printf("Found in DIC\n");
			D = 1;
			break;
		}
	}
	unum++;
	if (D == 0)
	{
		printf("Not found in DIC\n");
	}
}