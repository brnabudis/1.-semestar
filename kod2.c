#include <stdlib.h>
#include <stdio.h>
int main()
{
 FILE *fp;
 float data[5];
 int i;
 char filename[20];
 puts("Otipkaj 5 realnih brojeva");
 for (i = 0; i < 5; i++)
 scanf("%f", &data[i]);
 fflush(stdin);
 puts("Otipkaj ime datoteka:");
 gets(filename);
 if ( (fp = fopen(filename, "w")) == NULL)
 {
 fprintf(stderr, "Greska pri otvaranju datoteke %s.", filename);
 exit(1);
 }
 for (i = 0; i < 5; i++)
 {
 fprintf(fp, "\ndata[%d] = %f", i, data[i]);
 fprintf(stdout, "\ndata[%d] = %f", i, data[i]);
 }
 fclose(fp);
 printf("\nSada procitaj datoteku: %s", filename);
 return(0);
} 
