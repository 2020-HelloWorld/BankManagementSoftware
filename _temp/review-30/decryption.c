#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "head.h"

void decryption()
{
	char ch,ch1='A';
	FILE *fp ,*tfp;
	fp=fopen("users.txt","w");
	tfp=fopen("tempf.txt","r");
	if(fp==NULL || tfp==NULL)
	{
		printf("Error while decryption\n");
		exit(-1);
	}
	else 
	{ 
		while((ch=fgetc(tfp))!=EOF)
		{
			ch=ch-(ch1*2);
			fputc(ch,fp);
		}
	}
	fclose(fp);
	fclose(tfp);
	printf("\nFile decrypted succesfully");
}

