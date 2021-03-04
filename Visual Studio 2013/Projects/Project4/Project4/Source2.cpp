#include<stdio.h>
void main124SD(){
	FILE *fp;
	int c,count=0,countW=1;
	fopen_s(&fp,"input.txt", "r");
	while ((c = fgetc(fp)) != EOF){
		
		count++;
		if (c == ' '){
			countW++;
		}
	}
	printf("%d,%d", count, countW);
	fclose(fp);
}