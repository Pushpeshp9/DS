#include<stdio.h>
#include<stdlib.h>
main(int argc,char *argv[])
{
 FILE *fp1,*fp2;
 char ch;
 if(argc!=3)
 {
  printf("\n insufficient arguments.\n");
  exit(0);
 }
 fp1=fopen(argv[1],"r");
 fp2=fopen(argv[2],"w");
 if(fp1==NULL || fp2==NULL)
 {
   printf("\n File not created.\n");
   exit(0); 
 }
 if (NULL != fp1) 
 {
    fseek (fp1, 0, SEEK_END);
    int size = ftell(fp1);
    if (0 == size)
    {
     printf("File is empty.\n");
     exit(0);
    }
 }
while(!feof(fp1))
{
 ch=fgetc(fp1);
 fputc(ch,fp2);
}
printf("\n File successfully copied ");
fclose(fp1);
fclose(fp2);
}
