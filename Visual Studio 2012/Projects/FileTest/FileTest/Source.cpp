#include <stdio.h>
 
#define MAXCHAR 1000
int main980809() {
    FILE *fp;
    char str[MAXCHAR];
    char* filename = "reading.txt";
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        printf("%s", str);
    fclose(fp);
    return 0;
}