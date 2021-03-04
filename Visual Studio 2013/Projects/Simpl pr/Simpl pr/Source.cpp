
#include<stdio.h>
struct Student {
	int spl;
	int dm;
	int dld;
	char name[50];
	char id[50];
	int sum;
};
void main4567() {
	struct Student std[1000];
	int size = 2;
	int total = 0;
	for (int i = 0; i < size; i++){
		gets_s(std[i].name);
		gets_s(std[i].id);
		scanf_s("%d", &std[i].spl);
		scanf_s("%d", &std[i].dm);
		scanf_s("%d", &std[i].dld);
		getchar();
		std[i].sum = std[i].spl + std[i].dm + std[i].dld;
		total += std[i].sum;
	}
	float avg = total / size;
	for (int i = 0; i < size; i++){
		if (std[i].sum < avg){
			puts(std[i].name);
			puts(std[i].id);
		}
	}

}