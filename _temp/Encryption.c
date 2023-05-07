#include <stdio.h>
#include <conio.h>
int main()
{

	char ch,ch1='A';
	FILE *fp ,*tfp;
	fp=fopen("sourcef.txt","r");
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
	fp=fopen("sourcef.txt","w");
	if(fp==NULL || tfp==NULL)
		return 0;
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


return 0;
}
