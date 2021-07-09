#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

void new_acc();
//void login();
void encryption();
void decryption();
int fdate(int d,int m , int y);
int validity(int x,int d,int m,int y);
int varify(int i);
void tdate();
void password();

typedef struct user_details
{
	char detail[50];
	char info[100];
}USER;

USER user[20]={
	{"Serial Number",},
	{"Name",},
	{"Date of Birth(dd/mm/yyyy)",},
	{"Age",},
	{"Citizenship",},
	{"PAN",},{"Address",},
	{"Email",},{"Aadhar",},
	{"Phone Number",},
	{"Amount to be deposited",},
	{"username",},
	{"length of password(8 - 12)",}
	};

int sysdate[7];

enum information{sr_no,name,dob,age,citizenship,pan,address,email,aadhar,phone,amount,username,passkey};

void main()
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
	//else if(n==2)
		//login();
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

void new_acc()
{
	
	FILE* count = fopen("count.txt","r");
	if (count ==NULL )
	{
		/*
		printf("Error Occured while processing\n");
		perror("Error Details:");
		exit(0);
		*/
	} 
	
	char buffer[100]="0";
	fscanf(count,"%s",buffer);
	fclose(count);
	itoa(atoi(buffer)+1,user[0].info,10);
	char file_name[50];strcpy(file_name,user[0].info);strcat(file_name,".txt");

	FILE* bank_detail=fopen("bank_detail.csv","a+");
	FILE* users=fopen(file_name,"w+");
	strcpy(file_name,user[0].info);strcat(file_name,".csv");
	FILE* tran=fopen(file_name,"a+");
	count = fopen("count.txt","w");
	if (bank_detail==NULL ||users==NULL||tran==NULL )
	{
		printf("Error Occured while processing\n");
		perror("Error Details:");
		exit(0);
	} 									
	else
	{
		system("cls");
		printf("\t\t\t==== ADD RECORD  ====");
		for(int i=1;i<=11;i++)
		{
			system("cls");
			//sleep(1);
			printf("\n\tEnter the %s:\t",user[i].detail);scanf("%[^\n]s",user[i].info);fflush(stdin);
			i = varify(i);
		}
		
		system("cls");
		for(int i=1;i<=10;i++)
		{
			fputs(user[i].info,users);fprintf(users,"\n");
		}
		printf("\nAccount created successfully!! \n");
		password();
		printf("Your username is : %s and password is : %s",user[11].info,user[12].info);
		tdate();
		fprintf(bank_detail,"%s,%s,%s,%d/%d/%d,%d:%d:%d:%d\n",user[0].info,user[11].info,user[12].info,sysdate[0],sysdate[1],sysdate[2],sysdate[3],sysdate[4],sysdate[5],sysdate[6]);
		fprintf(count,"%s",user[0].info);
		fprintf(tran,"%d/%d/%d,%d:%d:%d:%d,%s\n",sysdate[0],sysdate[1],sysdate[2],sysdate[3],sysdate[4],sysdate[5],sysdate[6],user[10].info);
		fclose(bank_detail);fclose(users);fclose(count);fclose(tran);
		//encryption();
		getche();
	}
}

int varify(int i)
{
if(i==1)
	{				
		if (strlen(user[i].info)<4)
		{
			printf("Invalid entry!\nName is too short");
			getche();
			i--;
		}
		else if(strlen(user[i].info)>40)
		{
			printf("Invalid entry!\nName is too long");
			getche();
			i--;	
		}
	}
	else if (i==2)
	{
		char check[20];
		strcpy(check,user[i].info);
		char *dd = strtok(check,"/");
		char *mm =strtok(NULL,"/");
		char *yy =strtok(NULL,"/");
		if (fdate(atoi(dd),atoi(mm),atoi(yy))==0)
		{
			printf("Invalid Date");
			getche();
			i--;
		}
	}
	else if(i==3)
	{
		
	}
	else if(i==4)
	{
		
	}
	else if(i==5)
	{
		
	}
	else if(i==6)
	{
		
	}
	else if(i==7)
	{
		
	}
	else if(i==8)
	{
		
	}
	else if(i==9)
	{
		
	}
	else if(i==10)
	{
		
	}
	else if(i==11)
	{
		if (strlen(user[i].info)<4)
		{
			printf("Invalid entry!\nUsername is too short");
			getche();
			i--;
		}
		else if(strlen(user[i].info)>12)
		{
			printf("Invalid entry!\nUsername is too long");
			getche();
			i--;	
		}
	}
return i;
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


void tdate() 
{
    SYSTEMTIME t;
    GetLocalTime(&t); 
	sysdate[0]=t.wDay;
	sysdate[1]=t.wMonth;
	sysdate[2]=t.wYear;
	sysdate[3]=t.wHour;
	sysdate[4]=t.wMinute;
	sysdate[5]=t.wSecond;
	sysdate[6]=t.wMilliseconds;
}


void password()
{
    int i = 0,N=8;
    int randomizer = 0;
    srand((unsigned int)(time(NULL)));
    char numbers[] = "0123456789";
    char letter[] = "abcdefghijklmnoqprstuvwyzx";
    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
    char symbols[] = "!@#$%^&*()_-/|+.,:;\"'";
    char passkey[9]={[8]='\0'};
    randomizer = rand() % 4;
    for (i = 0; i < N; i++) 
	{
        if (randomizer == 1) 
		{
           passkey[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
        }
        else if (randomizer == 2) 
		{
            passkey[i] = symbols[rand() % 8];
            randomizer = rand() % 4;
        }
        else if (randomizer == 3) 
		{
            passkey[i] = LETTER[rand() % 26];
            randomizer = rand() % 4;
        }
        else
		{
            passkey[i] = letter[rand() % 26];
            randomizer = rand() % 4;
        }
    }
	strcpy(user[12].info,passkey);
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

/*

void login()
{
	system("cls");
	printf("\nEnter Your User name: ");scanf("%[^\n]s",&usern);fflush(stdin);
	printf("\nEnter Your Password: ");scanf("%[^\n]",&password);fflush(stdin);
	FILE* bank_detail=fopen("bank_detail.csv","a+");
	FILE* users=fopen("users.txt","r+");	
	if (bank_detail==NULL ||users==NULL )
	{
		printf("Error Occured while processing");
		exit(-1);
	}
	
	else
	{
		//decryption();
		rewind(users);
		fscanf(users,"%d/%d/%d\n%[^\n]s\n%d\n%[^\n]s\n%d/%d/%d\n%[^\n]s\n%s\n%[^\n]s\n%s\n%[^\n]s\n%s\n",&month,&date,&year,name,&age,citezenship,&b_month,&b_day,&b_year,pan,aadhar,address,phone,email,&ammount);
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
			printf("$ %s\n",ammount);
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
		fprintf(users,"%d/%d/%d\n%s\n%d\n%s\n%d/%d/%d\n%s\n%s\n%s\n%s\n%s\n%d\n",month,date,year,name,age,citezenship,b_month,b_day,b_year,pan,aadhar,address,phone,email,ammount);
		fclose(bank_detail);fclose(users);
		//encryption();
	}
}*/
