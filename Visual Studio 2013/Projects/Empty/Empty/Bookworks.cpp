// Bookwork
#include<stdio.h>
#include <string.h>

struct book {

	char name[50];
	char author[30];
	int year;
	int price1, price2;

};

void main() {

	int i;
	struct book dir[2];

	for (i = 0; i < 2; i++) {

		printf("Enter the name of the book: ");
		scanf("%s", dir[i].name);
		printf("Enter the author of the book: ");
		scanf_s("%s", dir[i].author);
		printf("Enter the publishing year: ");
		scanf_s("%d", &dir[i].year);
		printf("Enter the price range: ");
		scanf_s("%d%d", &dir[i].price1, &dir[i].price2);
	}
	int ys;
	printf("Enter a year to be searched for: ");
	scanf_s("%d", &ys);

	for (i = 0; i < 2; i++) {

		if (dir[i].year <= ys) {

			printf("Book:\n Name: %s\n Author's name: %s\n Published year: %d\n Price range: %d-%d\n", dir[i].name, dir[i].author, dir[i].year, dir[i].price1, dir[i].price2);

		}

	}

}