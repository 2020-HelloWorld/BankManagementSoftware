#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "head.h"

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
			//printf("\nYour balance:\n");
			//printf("$ %d\n",ammount);
			//ammount = 100000;
			printf("Name %s\n",name);
			//printf("%s\n",citezenship);
			//printf("%d\n",aadhar);
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