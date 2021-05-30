#include <stdio.h>
int new_acc();
int login();
int x=0;
int main()
{
	int n;
	printf("Select following options\n1.To create new account\n2.To login to excisting account\n");
	scanf("%d",&n);
	if (n==1)
		new_acc();
	else if(n==2)
		login();
	else 
		printf("Invalid Key");
}
int new_acc()
{
	printf("\nEnter your name");
	printf("\nEnter your PAN number");
	printf("\nEnter your DOB");
	printf("\nEnter your Ph number");
	printf("\nEnter your Adhaar No.");
	printf("\nEnter your Address");
	printf("\nEnter your Email ID");
}

int login()
{
	printf("\nEnter Your User name");
	printf("\nEnter Your Password");
	if (1!=1)
	{
		if (x<3)
        {
            int login();
            x++;
        }
		else 
			printf("U have entered wrong password thrice, waite for the cooldown");
	}
	else
	{
		int n;
		printf("\nSelect the following options\n1. To edit user information\n2.To perform transactions\n3.Balance enquiry\n");
		scanf("%d",&n);
		if (n==3)
		{
			printf("\nYour balance");
		}
		else if(n==2)
		{
			printf("Transaction");
		}
		else if(n==1)
		{
			printf("Edit User information");
		}
		else
			printf("Invalid key");
	}
}