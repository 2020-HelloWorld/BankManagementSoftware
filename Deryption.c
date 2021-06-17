#include <stdio.h>
int main()
{
	char ch,ch1='A';
	FILE *fp ,*tfp;
	fp=fopen("sourcef.txt","w");
	tfp=fopen("tempf.txt","r");
	if(fp==NULL || tfp==NULL)
		printf("/nFile does not exist");
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

return 0;
}