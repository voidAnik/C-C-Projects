/*Question number 1*/
#include<stdio.h>
#include<string.h>
void main1(){
	char str2[100], str1[100];
	int flag = 0;
	gets_s(str1);
	gets_s(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i < len2; i++){
		flag = 0;
		for (int j = 0; j < len1; j++){
			if (str2[i] == str1[j]){
				flag = 1;
				break;
				
			}
		}
		if (flag==0)
		printf("%c", str2[i]);
	
	}
	puts("");
}