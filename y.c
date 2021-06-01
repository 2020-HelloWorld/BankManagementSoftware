#include <stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
int new_acc();
int login();
void username(int n);
int main_exit;
char usern[20];
double password;
int x=0;
void close(void)
{
    printf("\n\n\n\nTHANK YOU...!! \n\n\n\n");
    }
    
void delay(int j)
{   
    int i,k;
    for(i=0;i<j;i++)
         k=i;
}
struct date{
    int month,day,year;

    };
struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
	double aadhar;
	double pan;
	char email[50];
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;
int main()
{
	int n;
	system("cls");
	printf("\n\n\t\t\t       BANKING MANAGEMENT SYSTEM");
	printf("\n");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO OUR BANK \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n");
	printf("\n");
	printf("SELECT THE FOLLOWING OPTIONS: \n1.To create new account\n2.To login to excisting account\n");
	scanf("%d",&n);
	if (n==1)
		new_acc();
	else if(n==2)
		login();
	else 
    {
        printf("Invalid Key....PLEASE ENTER THE CORRECT choice");
        close();
    }
		
}
int new_acc()
{	 int choice;
    FILE *ptr;
	 ptr=fopen("bank.dat","a+");
	 account_no:
	 system("cls");
    printf("\t\t\t==== ADD RECORD  ====");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
	while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %d %s %1f %f %d/%d/%d %d %s\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,&add.aadhar,add.address,&add.pan,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year,add.age,add.email)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {
				printf("Account no. already in use!");
                delay(1000000000);
        		goto account_no;
            }
    }
	add.acc_no=check.acc_no;
	printf("\nEnter your name:");scanf("%s",add.name);
	printf("\n Enter your age:");scanf("%d",&add.age);
	printf("\nEnter your citizenship:");scanf("%s",add.citizenship);
    printf("\nEnter your DOB:");scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
	printf("\nEnter your PAN number:");scanf("%1f",&add.pan);
	printf("\nEnter your Adhaar No. :");scanf("%d",&add.aadhar);
	printf("\nEnter your Address:"); scanf("%s",add.address);
    printf("\nEnter your Phone number:");scanf("%d",&add.phone);
	printf("\nEnter your Email ID:");scanf("%s",add.email);
	printf("\nEnter the amount to be deposited :$");scanf("%f",&add.amt);
    fclose(ptr);
    delay(1000000);
    printf("\nAccount created successfully!! \n");
	username(7);
	add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
	
}


int login()
	
{	
	
	printf("\nEnter Your User name: ");scanf("%s",&usern);
	printf("\nEnter Your Password: ");scanf("%d",&password);
	if (1!=1)
	{
		if (x<3)
        {
            int login();
            x++;
        }
		else 
			printf("U have entered wrong password thrice, wait for the cooldown");
	}
	else
	{
		int n;
		printf("\nSelect the following options\n1. To edit user information\n2.To perform transactions\n3.Balance enquiry\n");
		scanf("%d",&n);
		if (n==3)
		{
			printf("\nYour balance");
            // balance();         not done yet
		}
		else if(n==2)
		{
			printf("Transaction");
             //transaction();    not done yet
		}
		else if(n==1)
		{
			printf("Edit User information");
            //edit();          not done yet
		}
		else
			printf("Invalid key");
	}
}

void username(int N)
{
   
    int i = 0;
    int randomizer = 0;
  
    srand((unsigned int)(time(NULL)));
  
    
    char numbers[] = "0123456789";
    char letter[] = "abcdefghijklmnoqprstuvwyzx";
    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
    char symbols[] = "!@#$^&*?";
    char user[N];
    randomizer = rand() % 4;
	printf("YOUR USERNAME: ");
    for (i = 0; i < N; i++) {
  
        if (randomizer == 1) {
           user[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
            printf("%c", user[i]);
        }
        else if (randomizer == 2) {
            user[i] = symbols[rand() % 8];
            randomizer = rand() % 4;
            printf("%c", user[i]);
        }
        else if (randomizer == 3) {
            user[i] = LETTER[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", user[i]);
        }
        else {
            user[i] = letter[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", user[i]);
        }
    }
}