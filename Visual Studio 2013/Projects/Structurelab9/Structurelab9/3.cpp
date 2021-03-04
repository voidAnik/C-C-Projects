
#include<stdio.h>
struct Student{
	char name[20];
	char id[10];
	float spl;
	float dld;
	float dm;
};
float input(struct Student students[], int size);
int score[100];
void main234(){
	struct Student students[100];
	int size;
	scanf_s("%d", &size);
	getchar();
	float average = input(students, size);
	for (int i = 0; i < size; i++){
		if (score[i] < average){
			puts(students[i].name);
			puts(students[i].id);
		}
	}

}
float input(struct Student students[], int size){

	int total = 0;
	for (int i = 0; i < size; i++){
		gets_s(students[i].name);
		gets_s(students[i].id);
		scanf_s("%f", &students[i].spl);
		scanf_s("%f", &students[i].dld);
		scanf_s("%f", &students[i].dm);
		getchar();
		total += (students[i].spl + students[i].dld + students[i].dm);
		score[i] = total;
	}
	float avr = total / size;
	return avr;
}