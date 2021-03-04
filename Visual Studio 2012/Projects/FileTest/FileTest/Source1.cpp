#include<stdio.h>
void main124()
{
  FILE* file ;
  fopen_s(&file,"TXT.txt","r");
  int i = 0;

  //fscanf (file, "%d", &i);    
  while (!feof (file))
    {  
      fscanf (file, "%d", &i); 
	  printf ("%ld ", i);
    }
  fclose (file);        
}