#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "head.h"

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