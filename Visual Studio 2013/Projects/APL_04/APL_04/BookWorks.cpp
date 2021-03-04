
#include<stdio.h>
#include<string.h>
const int SIZE = 100;
typedef struct
{
	char name[50];
	char author[50];
	int year;
	float price;
}Book;

int SearchAuthor(Book books[], int len);
void SearchYear(Book books[], int len);
void SearchRange(Book books[], int len);
void main()
{
	Book books[SIZE] = { { "History of Bangladesh", "Abul Muhith", 2016, 800 }, { "Boba Kahini", "Jashim Uddin", 1964, 2113 }, 
	{ "Shaheb Bibi Golam", "Bimol mitro", 1956, 540 }, { "Srikanto", "Sharat Chandra", 1917, 300 }, { "Himu", "Humayun Ahmed", 2007, 230 },
	{ "Misir Ali", "Humayun Ahmed", 1998, 200 }, { "Brishty'r Kahini", "Jafar Iqbal", 2007, 300 }, {"Dushtu Cheler Dol","Jafar Iqbal",2008,180},
	{ "Nari", "Huamyun Azad", 2000, 200 }, { "Gora", "Rabindro Nath Tagore", 1910, 250 }, { "Achinpur", "Humayun Ahmed", 2006, 350 } };

	int selector;
	int len = 11;
	puts("\t\t <Welcome to BookWorks> \n");
	puts("Here is your menu:");
	while (1==1)
	{
		puts("\n\n1.To search by author name press '1' & Enter..");
		puts("2.To search by max Year press '2' & Enter..");
		puts("3.To search by price range press '3' & Enter..");
		puts("4.To QUITE press '4' & Enter..");
		printf("\nEnter choice_ ");
		scanf_s("%d", &selector);
		getchar();
		if (selector == 1)
		{
			int countAuth=SearchAuthor(books,len);
			if (countAuth!=0)
			printf("Total Books: %d \n", countAuth);
		}
		else if (selector == 2)
		{
			SearchYear(books, len);
		}
		else if (selector == 3)
		{
			SearchRange(books, len);
		}
		else if (selector == 4)
		{
			puts("\nBye....");
			break;
		}
		else
		{
			puts("\nWrong input!! try again..");
		}
	}
}
int SearchAuthor(Book books[],int len)
{
	char sAuthor[15];
	int count = 0;
	printf("Enter author name:_ ");
	gets_s(sAuthor);
	for (int i = 0; i < len; i++)
	{
		if (strcmp(books[i].author, sAuthor) == 0)
		{

			printf("\nName of Book: %s\n", books[i].name);
			printf("Author name: %s\n", books[i].author);
			printf("Year: %d\n", books[i].year);
			printf("Price: %.2fTK\n", books[i].price);
			count++;
		}
	}
	if (count == 0)
	{
		puts("\nHere is no book by this author or wrong input. :-(");
	}
	return count;
}
void SearchYear(Book books[], int len)
{
	int sYear;
	int flag = 0;
	printf("Enter max year:_ ");
	scanf_s("%d", &sYear);
	for (int i = 0; i < len; i++)
	{
		if (books[i].year < sYear)
		{
			printf("\nName of Book: %s\n", books[i].name);
			printf("Author name: %s\n", books[i].author);
			printf("Year: %d\n", books[i].year);
			printf("Price: %.2fTK\n", books[i].price);
			flag++;
		}
	}
	if (flag == 0)
	{
		puts("\nHere is no book under this year or wrong input. :-(");
	}
}
void SearchRange(Book books[], int len)
{
	float minR, maxR;
	int flag=0;
	printf("Enter minimum & maximum price range:_ ");
	scanf_s("%f %f", &minR, &maxR);
	for (int i = 0; i < len; i++)
	{
		if (books[i].price<maxR && books[i].price>minR)
		{
			printf("\nName of Book: %s\n", books[i].name);
			printf("Author name: %s\n", books[i].author);
			printf("Year: %d\n", books[i].year);
			printf("Price: %.2fTK\n", books[i].price);
			flag++;
		}
	}
	if (flag == 0)
	{
		puts("\nHere is no book in this range or wrong input. :-(");
	}

}