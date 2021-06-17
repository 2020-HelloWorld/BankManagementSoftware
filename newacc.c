#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

int new_acc();
int login();
void encryption();
void decryption();
int fdate(int d,int m , int y);
int validity(int x,int d,int m,int y);
int main()
{
	int n;
	beginning:
	system("cls");
	printf("\n\n\t\t\t       BANKING MANAGEMENT SYSTEM");
	printf("\n");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO OUR BANK \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n");
	printf("\n");
	printf("SELECT THE FOLLOWING OPTIONS: \n1.To create new account\n2.To login to excisting account\n3.To exit\n");
	scanf("%d",&n);fflush(stdin);
	if (n==1)
		new_acc();
	else if(n==2)
		login();
	else if (n==3)
	{
		system("cls");
		printf("\n\t\t\t       ====T H A N K\tY O U====");
		exit(-1);
	}
	else 
    {	
        printf("Invalid Key....PLEASE ENTER THE CORRECT choice");
		char k = getch();
        goto beginning;
    }
		
}
int new_acc()
{
	FILE* bank_count;bank_count=fopen("bank_count.txt","a+");
	FILE* bank_detail;bank_detail=fopen("bank_detail.txt","a+");
	FILE* users;users=fopen("users.txt","w+");
	if (bank_count==NULL ||bank_detail==NULL ||users==NULL )
	{
		printf("Error Occured while processing");
		exit(-1);
	}
	else
	{
		int date,month,year,b_day,b_month,b_year,age,aadhar,phone,ammount;
		char name[100],citezenship[50],pan[20],address[500],email[100];
		system("cls");
		printf("\t\t\t==== ADD RECORD  ====");
		date1:
		printf("\n\n\nEnter today's date(mm/dd/yyyy):");scanf("%d/%d/%d",&month,&date,&year);fflush(stdin);
		if (fdate(date,month,year)==0)
		{
			printf("Invalid Date");
			getche();
			goto date1;
		}
		name:
		printf("\nEnter your name:");scanf("%[^\n]s",name);fflush(stdin);

		date2:
		printf("\nEnter your DOB(mm/dd/yyyy):");scanf("%d/%d/%d",&b_month,&b_day,&b_year);fflush(stdin);
		if (fdate(b_day,b_month,b_year)==0)
		{
			printf("Invalid Date");
			getche();
			goto date2;
		}
		age:
		printf("\nEnter your age:");scanf("%d",&age);fflush(stdin);
		
		citezenship:
		printf("\nEnter your citezenship:");scanf("%s",citezenship);fflush(stdin);
		
		pan:
		printf("\nEnter your PAN number:");scanf("%s",pan);fflush(stdin);
		
		adhaar:
		printf("\nEnter your Adhaar No. :");scanf("%d",&aadhar);fflush(stdin);
		
		address:
		printf("\nEnter your Address:"); scanf("%[^\n]s",address);fflush(stdin);
		
		ph_num:
		printf("\nEnter your Phone number:");scanf("%d",&phone);fflush(stdin);
		
		email:
		printf("\nEnter your Email ID:");scanf("%s",email);fflush(stdin);
		
		ammount:
		printf("\nEnter the amount to be deposited :$");scanf("%d",&ammount);fflush(stdin);
		
		printf("\nAccount created successfully!! \n");
		fprintf(users,"%d/%d/%d\n%s\n%d\n%s\n%d/%d/%d\n%s\n%d\n%s\n%d\n%s\n%d\n",month,date,year,name,age,citezenship,b_month,b_day,b_year,pan,aadhar,address,phone,email,ammount);
		fclose(bank_count);fclose(bank_detail);fclose(users);
		encryption();
	}
}


int login()
{
	system("cls");
	int date,month,year,b_day,b_month,b_year,age,aadhar,phone,ammount;
	char name[100],citezenship[50],pan[20],address[500],email[100];
	char usern[50],password[50];
	printf("\nEnter Your User name: ");scanf("%[^\n]s",&usern);fflush(stdin);
	printf("\nEnter Your Password: ");scanf("%[^\n]",&password);fflush(stdin);
	FILE* bank_detail;bank_detail=fopen("bank_detail.txt","a+");
	FILE* users;users=fopen("users.txt","r+");	
	if (bank_detail==NULL ||users==NULL )
	{
		printf("Error Occured while processing");
		exit(-1);
	}
	
	else
	{
		decryption();
		rewind(users);
		fscanf(users,"%d/%d/%d\n%[^\n]s\n%d\n%[^\n]s\n%d/%d/%d\n%[^\n]s\n%d\n%[^\n]s\n%d\n%[^\n]s\n%d\n",&month,&date,&year,name,&age,citezenship,&b_month,&b_day,&b_year,pan,&aadhar,address,&phone,email,&ammount);
		int n;
		beginning1:
		system("cls");
		printf("\nSelect the following options\n1. To edit user information\n2.To perform transactions\n3.Balance enquiry\n4.To exit\n");
		scanf("%d",&n);fflush(stdin);
		if(n==1)
		{
			printf("Edit User information");
			//edit();          not done yet
		}		
		else if(n==2)
		{
			printf("Transaction");
			 //transaction();    not done yet
		}

		else if (n==3)
		{
			printf("\nYour balance:\n");
			printf("$ %d\n",ammount);
			ammount = 100000;
			printf("Name %s\n",name);
			printf("%s\n",citezenship);
			printf("%d\n",aadhar);
			printf("%d/%d/%d",month,date,year);
		}
		else if (n==4)
		{
			system("cls");
			printf("\n\t\t\t       ====T H A N K\tY O U====");
			exit(-1);
		}
		else
		{
			printf("Invalid key");
			char k = getch();
			goto beginning1;
		}
		fprintf(users,"%d/%d/%d\n%s\n%d\n%s\n%d/%d/%d\n%s\n%d\n%s\n%d\n%s\n%d\n",month,date,year,name,age,citezenship,b_month,b_day,b_year,pan,aadhar,address,phone,email,ammount);
		fclose(bank_detail);fclose(users);
		encryption();
	}
}

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

int validity(int x,int d,int m,int y)
{	
	int i ;
	if (d>=1 && d<=x)
		i = 1;
	else
		i = 0;
	return i;
}
int fdate(int d,int m , int y)
{
	int z;
	if (m>12)
		z =0;
		
	else if (m != 2)
	{
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 )
			z = validity(31,d,m,y);
		else
			z = validity(30,d,m,y);
	}
	else 
	{
		if (y%100 == 0)
		{
			if (y%400 == 0)
				z = validity(29,d,m,y);
			else
				z = validity(28,d,m,y);
		}
		else if (y %4 == 0)
			z = validity(29,d,m,y);
		else
			z = validity(28,d,m,y);
	}
	return z;
}