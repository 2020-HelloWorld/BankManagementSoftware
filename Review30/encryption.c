#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "head.h"

void encryption()
{
	char ch,ch1='A';
	FILE *fp ,*tfp;
	fp=fopen("users.txt","r");
	tfp=fopen("tempf.txt","w");
	if(fp==NULL || tfp==NULL)
		printf("/nFile does not exist");
	else 
	{ 
		while((ch=fgetc(fp))!=EOF)
		{
			ch=ch+(ch1*2);
			fputc(ch,tfp);
		}
	}
	fclose(fp);
	fclose(tfp);
	tfp=fopen("tempf.txt","r");
	fp=fopen("users.txt","w");
	if(fp==NULL || tfp==NULL)
	{
		printf("Error while encryption\n");
		exit(-1);
	}
	else 
	{
		while((ch=fgetc(tfp))!=EOF)
		{
			ch=fputc(ch,fp);
		
		}
	}
	fclose(fp);
	fclose(tfp);
	printf("\nFile encrypted succesfully");
}
