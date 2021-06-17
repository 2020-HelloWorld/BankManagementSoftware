#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "head.h"

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