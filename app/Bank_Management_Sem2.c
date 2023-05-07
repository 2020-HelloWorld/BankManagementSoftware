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
#include <winuser.h>

void new_acc();
void login();
void encryption(char E_file[]);
void decryption(char E_file[]);
int fdate(int d,int m , int y);
int validity(int x,int d,int m,int y);
int varify(int i);
void tdate();
void password();
void upi_password();
int password_validity(char a[]);
void display_bank();

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
	{"length of password(8 - 12)",},
	{"upi Id",},
	{"upi password"},
	};

int sysdate[7];

enum information{sr_no,name,dob,age,citizenship,pan,address,email,aadhar,phone,amount,username,passkey,upi,upi_pass};

char Bank_Name[50],IFSC_code[50],Branch[50],Bank_Ph[15],Bank_add[500],bank_mail[50];

void main()
{
	HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 10);
	int n;
	FILE* bd = fopen("Bank_info.txt","r");
	if(bd==NULL)
	{
		perror("\nMessage: "); 
		exit(-1);
	}
	fgets(Bank_Name,50,bd);fgets(IFSC_code,50,bd);fgets(Branch,50,bd);fgets(Bank_Ph,15,bd);fgets(Bank_add,500,bd);fgets(bank_mail,50,bd);
	fclose(bd);
	beginning:
	system("cls");
	printf("\n\n\t\t\t       BANKING MANAGEMENT SYSTEM");
	printf("\n");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO OUR BANK \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n");printf("\n");printf("\n");
	printf("Bank Name: %s\n",Bank_Name);printf("IFSC code: %s\n",IFSC_code);
	printf("\n");
	printf("SELECT THE FOLLOWING OPTIONS: \n1.To create new account\n2.To login to existing account\n3.To exit\n");
	scanf("%d",&n);fflush(stdin);
	if (n==1)
		{new_acc();
		goto beginning;}
	else if(n==2)				
		{login();
		goto beginning;}
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
	HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 11);
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
	char file_name[50],file_name1[50];strcpy(file_name,user[0].info);strcat(file_name,".txt");char c;
	itoa(atoi(buffer)+1,user[0].info,10);
	FILE* bank_detail=fopen("bank_detail.csv","a+");
	FILE* users=fopen(file_name,"w+");
	strcpy(file_name1,user[0].info);strcat(file_name1,".csv");
	FILE* tran=fopen(file_name1,"a+");
	count = fopen("count.txt","w");
	if (bank_detail==NULL ||users==NULL||tran==NULL )
	{
		//printf("Error Occured while processing\n");
		MessageBox(0,"Error Occured while processing","$$ERROR$$",1);
		//perror("Error Details:");
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
		tdate();
		for(int i=1;i<=10;i++)
		{
			fputs(user[i].info,users);fprintf(users,"\n");
		}
		
		printf("Do you want to create upi(y/n): ");fflush(stdin);scanf("%c",&c);
		switch(c)
		{
			case 'y' :strcpy(user[13].info,user[9].info);
					  upi_password();
					  strcat(user[13].info,"@bnk");
					  break;
		    case 'n' :
					printf("You can start your upi services later by logging in\n");
					strcpy(user[13].info,"-");
					strcpy(user[14].info,"-");
					break;
			default:printf("Select 'y' for yes and 'n' for no\n");
		}
		system("cls");
		printf("\nAccount created successfully!! \n");
		password();
		printf("Your username is : %s and password is : %s",user[11].info,user[12].info);
		tdate();
		fprintf(bank_detail,"%s,%s,%s,%s,%s,%d/%d/%d,%d:%d:%d:%d\n",user[0].info,user[11].info,user[12].info,user[13].info,user[14].info,sysdate[0],sysdate[1],sysdate[2],sysdate[3],sysdate[4],sysdate[5],sysdate[6]);
		fprintf(count,"%s",user[0].info);
		fprintf(tran,"%d/%d/%d,%d:%d:%d:%d,%s,Credit\n",sysdate[0],sysdate[1],sysdate[2],sysdate[3],sysdate[4],sysdate[5],sysdate[6],user[10].info);

		fclose(bank_detail);fclose(users);fclose(count);fclose(tran);
		//encryption("File Name);
		encryption(file_name);
		getche();
	}
}





void login()
{
	
	HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 9);
	int store=0;
	system("cls");
	char UN[20],PW[20],file_name[20];char c;
	char* word;
	int yes_or_no=0;fflush(stdin);
	login_page:
	
	printf("\nEnter Your User name: ");scanf("%[^\n]s",UN);fflush(stdin);
	printf("\nEnter Your Password: ");scanf("%[^\n]s",PW);fflush(stdin);
	FILE* bank_detail=fopen("bank_detail.csv","r");
	if (bank_detail==NULL )
	{
		MessageBox(0,"Error Occured while processing","$$ERROR$$",1);
		//printf("Error Occured while processing");
		//perror("ERROR Message:");
		exit(0);
	}
	else
	{
		char buffer[100];
		while(fgets(buffer,100,bank_detail))
		{
			word = strtok(buffer,",");strcpy(user[0].info ,word);
			word = strtok(NULL,",");strcpy(user[11].info ,word);
			word = strtok(NULL,",");strcpy(user[12].info ,word);
			store++;
			if(strcmp(user[11].info,UN)==0 &&strcmp(user[12].info,PW)==0)
			{
				yes_or_no++;
				word = strtok(NULL,",");strcpy(user[13].info ,word);
				word = strtok(NULL,",");strcpy(user[14].info ,word);
				break;
			}
		}
		if (yes_or_no==0)
		{
			MessageBox(0,"INVALID USERNAME OR PASSWORD","$$ERROR$$",1);
			goto login_page;

		}
		strcpy(file_name,user[0].info);
		char file_name1[20];
		strcpy(file_name1,file_name);
		strcat(file_name,".txt");
		strcat(file_name1,".csv");
		//for neft
		int amn,al;
		fclose(bank_detail);
		char acc_number[50],bank[50],rec_nam[50];
		decryption(file_name);
		FILE *users = fopen(file_name,"r");
		FILE *tran = fopen(file_name1,"a+");
		if (users==NULL||tran==NULL)
		{
			perror("ERROR Message:");
			exit(0);
		}
		else
		{
			logged_in:
			system("cls");
			for(int i=1;i<11;i++)
			{
				fgets(user[i].info,100,users);
			}
			
			int choice,choice1;
			printf("\nSelect the following options\n1. To edit user information\n2.To perform transactions\n3.Balance enquiry\n4.To display Transaction history\n5.Change Password\n6.To exit\n");
			scanf("%d",&choice);
			
			if(choice==1)
			{
				int j;
				printf("Select the information you want to edit\n");
				for(int i=1;i<10;i++)
				{
					printf("%d. %s : %s\n",i,user[i].detail,user[i].info);
				}
				printf(">");
				scanf("%d",&j);
				fflush(stdin);
				printf("Enter the updated %s\n",user[j].detail);
				scanf("%[^\n]s",user[j].info);strcat(user[j].info,"\n");
				printf("Your information has been updated\n");
				getche();
				goto logged_in;
			}
			else if(choice == 2)
			{
				transaction_start:
				printf("\nSelect the following options\n1. For NEFT\n2.UPI\n3.Withdrawal\n4.Deposit\n5.Exit\n>");
				scanf("%d",&choice1);
				if (choice1==1)
				{
					system("cls");
					printf("\nWelcome to NEFT Transcation");
					printf("\nPlease reconfirm your user name and password\n");
					printf("\nEnter Your User name: ");fflush(stdin);scanf("%[^\n]s",UN);
					printf("\nEnter Your Password: ");fflush(stdin);scanf("%[^\n]s",PW);
					if(strcmp(user[11].info,UN)||strcmp(user[12].info,PW))
					{
						MessageBox(0,"INVALID USERNAME OR PASSWORD","$$ERROR$$",1);
						goto transaction_start;
					}
					else
					{
						neft:
						printf("ENTER THE AMOUNT TO BE TRANSFERED: ");fflush(stdin);
						scanf("%d",&amn);
						if(atoi(user[10].info)>amn)
						{
							printf("ENTER THE NAME OF RECIEVER\n");fflush(stdin);scanf("%[^\n]s",bank);
							printf("ENTER THE BANK NAME OF RECIEVER\n");fflush(stdin);scanf("%[^\n]s",rec_nam);
							printf("ENTER THE ACCOUNT NUMBER OF THE RECEIVER\n");fflush(stdin);scanf("%[^\n]s",acc_number);
							al=atoi(user[10].info)-amn;
							itoa(al,user[10].info,10);
							printf("\n---------RECEIPT----------\n");
							printf("Money Transfered to");
							printf("\nBANK NAME:%s \nRECIEVER NAME:%s \nRECIEVER ACCOUNT NUMBER: %s",bank,rec_nam,acc_number);
							//printf("\nIFSC CODE: %s",IFSC_code);
							//printf("\nBRANCH: %s",);
							printf("\nAMOUNT TRANSFFERED: %d",amn);
							tdate();
							fprintf(tran,"%d/%d/%d,%d:%d:%d:%d,%d,NEFT\n",sysdate[0],sysdate[1],sysdate[2],sysdate[3],sysdate[4],sysdate[5],sysdate[6],amn);
								printf("\n");
								goto transaction_start;
						}
						else
						{
							printf("ERROR IN TRANFERRING MONEY DUE TO INSUFFICIENT BALANCE");
							goto neft;
						}
					}
				}
				else if (choice1==2)
				{
					if(strcmp(user[13].info,"-"))
					{
						//Code for UPI transaction
						char ph_no[50];char upi_pass[50];int bal;
						int amt;
						printf("\n\tEnter the Receiver's %s:\t",user[9].detail);fflush(stdin);scanf("%[^\n]s",ph_no);
						amm:
						printf("\n\tEnter the amount to be transferred:\t");fflush(stdin);scanf("%d",&amt);
						if(amt>atoi(user[10].info))
						{
							printf("\n\tBalance not sufficient...\tEnter the amount again:" );goto amm;
						}
						retry:
						printf("\n\tEnter Your %s:\t",user[14].detail);fflush(stdin);scanf("%[^\n]s",upi_pass);
							if(strcmp(user[14].info,upi_pass)==0)
							{
								bal=atoi(user[10].info)-amt;
								itoa(bal,user[10].info,10);
								//printf("\n\tTransaction succesfull!!")
								MessageBox(0,"Transaction succesfull!!","**congrats**",1);
								printf("\n\tYour current balance is %s",user[10].info);
								fseek(tran,0,2);
								tdate();
								fprintf(tran,"%d/%d/%d,%d:%d:%d:%d,%d,UPI Transfer\n",sysdate[0],sysdate[1],sysdate[2],sysdate[3],sysdate[4],sysdate[5],sysdate[6],amt);
							}
							else
							{
								MessageBox(0,"INVALID PASSWORD","$$ERROR$$",1);
								printf("Enter\n1.To try again\n2.To change password\n");fflush(stdin);
								int kn;
								scanf("%d",&kn);
								if (kn==1)
								{
									goto retry;
								}
								else if(kn==2)
								{
									
									printf("\nPlease reconfirm your user name and password\n");fflush(stdin);
									printf("\nEnter Your User name: ");scanf("%[^\n]s",UN);fflush(stdin);
									printf("\nEnter Your Password: ");scanf("%[^\n]s",PW);fflush(stdin);
									if(strcmp(user[11].info,UN)||strcmp(user[12].info,PW))
									{
										MessageBox(0,"INVALID USERNAME OR PASSWORD","$$ERROR$$",1);
										goto transaction_start;
									}
									else
									{
										upi_password();
										char det[500];
										FILE* tm=fopen("tem.dat","w");
										FILE* fp=fopen("bank_detail.csv","r");
										while(fgets(det,500,fp))
										{
											fputs(det,tm);
										}
										fclose(fp);fclose(tm);
										tm=fopen("tem.dat","r");
										fp=fopen("bank_detail.csv","w");
										int ko=1;
										while(fgets(det,500,tm))
										{
											if(ko!=store)
											{
												fputs(det,fp);
											}
											else 
											{
												tdate();
												fprintf(fp,"%s,%s,%s,%s,%s,%d/%d/%d,%d:%d:%d:%d\n",user[0].info,user[11].info,user[12].info,user[13].info,user[14].info,sysdate[0],sysdate[1],sysdate[2],sysdate[3],sysdate[4],sysdate[5],sysdate[6]);
											}
											ko++;
										}
										fclose(fp);fclose(tm);fclose(fopen("tem.dat","w"));
										goto amm;
									}
								}
							}
					}
					else
					{
						printf("You don't have a upi regestration\nDo you want to register for upi?(y/n): ");
						fflush(stdin);scanf("%c",&c);
						switch(c)
						{
							case 'y' :strcpy(user[13].info,user[9].info);
									  upi_password();
									  strcat(user[13].info,"@bnk");
									  break;
							case 'n' :
									printf("You can't perform upi transactions without regestering \n");
									break;
							default:printf("Select 'y' for yes and 'n' for no\n");
						}
					}
				}
				else if (choice1==3)
				{
					//Withdrawal
					int amt1;
					printf("Enter the amount you want to withdraw: ");fflush(stdin);scanf("%d",&amt1);
					amm1:
					if(amt1>atoi(user[10].info))
					{
						printf("\n\tBalance not sufficient...\tEnter the amount again:" );goto amm1;
					}
					else
					{
						int balance=atoi(user[10].info)-amt1;
						itoa(balance,user[10].info,10);
						//printf("\n\tTransaction succesfull!!")
						MessageBox(0,"Transaction succesfull!!","**congrats**",1);
						printf("\n\tYour current balance is %s",user[10].info);
						fseek(tran,0,2);
						tdate();
						fprintf(tran,"%d/%d/%d,%d:%d:%d:%d,%d,Debit\n",sysdate[0],sysdate[1],sysdate[2],sysdate[3],sysdate[4],sysdate[5],sysdate[6],amt1);
					}
					
					
				}
				else if (choice1==4)
				{
					//Deposit
					int amt2;
					printf("Enter the amount you want to deposit: ");fflush(stdin);scanf("%d",&amt2);
					int balance=atoi(user[10].info)+amt2;
					itoa(balance,user[10].info,10);
					//printf("\n\tTransaction succesfull!!")
					MessageBox(0,"Transaction succesfull!!","**congrats**",1);
					printf("\n\tYour current balance is %s",user[10].info);
					fseek(tran,0,2);
					tdate();
					fprintf(tran,"%d/%d/%d,%d:%d:%d:%d,%d,Credit\n",sysdate[0],sysdate[1],sysdate[2],sysdate[3],sysdate[4],sysdate[5],sysdate[6],amt2);
				}
				else if (choice1==5)
				{
					system("cls");
					printf("\n\t\t\t       ====T H A N K\tY O U====");
					exit(0);
				}
				else
			{
				printf("Invalid Key....PLEASE ENTER THE CORRECT choice");
				getche();
				fflush(stdin);
				goto transaction_start;
			}
				
			}
			else if(choice == 3)
			{
				printf("\nYour current balance is %s",user[10].info);
			}
			else if(choice==4)
			{
				//Transaction history
				char d_c;char full_info[500];char* pieces,*date_piece;int serial=1;char date_month[50];char month_user[20],user_data[20],taken_data[100];
				int mmm,yyy;
				//printf("Select\n1.To display entire transaction history/n2.To display transaction of particular month and year\n");
				//fflush(stdin);scanf("%c",&d_c);
				//if(d_c=='1')
				if(1)
				{
					printf("\t\t");
					printf("Sr.No\t  \tDate\t \t\tTime\t\t\tAmount\t  \tMode\n");printf("\n");printf("\t\t");
					
					while(fgets(full_info,500,tran))
					{
						printf("%d\t\t",serial);
						pieces=strtok(full_info,",");
						printf("%s\t\t",pieces);
						pieces=strtok(NULL,",");
						printf("%s\t\t",pieces);
						pieces=strtok(NULL,",");
						printf("%s\t\t",pieces);
						pieces=strtok(NULL,",");
						printf("%s\t\t",pieces);
						serial++;
					}
					getche();
					goto logged_in;
				}
				/*
				else if(d_c=='2')
				{
					serial = 1;
					display_transaction:
					printf("\nEnter month to be displayed(mm/yyyy): ");fflush(stdin);scanf("%[^\n]s",month_user);//printf("%s\n",month_user);
					date_piece=strtok(month_user,"/");mmm=atoi(date_piece);strcpy(user_data,date_piece);strcat(user_data,"/");
					date_piece=strtok(NULL,"/");yyy=atoi(date_piece);strcat(user_data,date_piece);
					tdate();
					if(mmm>=1&&mmm<=12&&yyy>0&&yyy<=sysdate[2])
					{
						printf("\t\t");
						printf("Sr.No\t\tDate\t\tTime\t\tAmount\t\tMode\n");printf("\t\t");
						while(fgets(full_info,500,tran))
						{
							pieces=strtok(full_info,",");
							strcpy(taken_data,pieces);
							date_piece=strtok(taken_data,"/");
							date_piece=strtok(NULL,"/");strcpy(date_month,date_piece);strcat(date_month,"/");
							date_piece=strtok(NULL,"/");strcat(date_month,date_piece);
							//printf("%s\t%s\t%s\n",date_month,month_user,user_data);
							if(strcmp(date_month,user_data)==0)
							{
								printf("%d\t\t",serial);
								pieces=strtok(full_info,",");
								printf("%s\t\t",pieces);
								pieces=strtok(NULL,",");
								printf("%s\t\t",pieces);
								pieces=strtok(NULL,",");
								printf("%s\t\t",pieces);
								pieces=strtok(NULL,",");
								printf("%s\t\t",pieces);
								serial++;
							}
						}
						if(serial==1)
						{
							printf("\n\t\t\tNo details avilable for given month\n");
						}
					}
					else
					{
						printf("Invalid Month\n");
						goto display_transaction;
					}
				}*/
				else
				{
					printf("Select the avilable options\n");
				}
			}
			else if(choice==5)
			{
				char temp_k[50];
				printf("Enter the updated password\n");
				scanf("%[\n]s",temp_k);
				if(password_validity(temp_k))
				{
					strcpy(user[12].info,temp_k);
					char det[500];
					FILE* tm=fopen("tem.dat","w");
					FILE* fp=fopen("bank_detail.csv","r");
					while(fgets(det,500,fp))
					{
						fputs(det,tm);
					}
					fclose(fp);fclose(tm);
					tm=fopen("tem.dat","r");
					fp=fopen("bank_detail.csv","w");
					int ko=1;
					while(fgets(det,500,tm))
					{
						if(ko!=store)
						{
							fputs(det,fp);
						}
						else 
						{
							tdate();
							fprintf(fp,"%s,%s,%s,%s,%s,%d/%d/%d,%d:%d:%d:%d\n",user[0].info,user[11].info,user[12].info,user[13].info,user[14].info,sysdate[0],sysdate[1],sysdate[2],sysdate[3],sysdate[4],sysdate[5],sysdate[6]);
						}
						ko++;
					}
					fclose(fp);fclose(tm);fclose(fopen("tem.dat","w"));
				}
				else
				{
					printf("Invalid password format\n");
				}
				
				
			}
			else if(choice == 6)
			{
				system("cls");
				printf("\n\t\t\t       ====T H A N K\tY O U====");
				
				fclose(users);users = fopen(file_name,"w");
				for(int i=1;i<=10;i++)
				{
					fputs(user[i].info,users);//fprintf(users,"\n");
				}
				fclose(users);fclose(tran);encryption(file_name);
				exit(0);
			}
			else
			{
				//printf("Invalid Key....PLEASE ENTER THE CORRECT choice");
				MessageBox(0,"Invalid Key....PLEASE ENTER THE CORRECT choice","$$ERROR$$",1);
				getche();
				goto logged_in;
			}
			fclose(users);users = fopen(file_name,"w");
			for(int i=1;i<=10;i++)
			{
				fputs(user[i].info,users);//fprintf(users,"\n");
			}
			fclose(users);fclose(tran);encryption(file_name);
		}
	
	}
	getche();
}			



int varify(int i)
{
if(i==1)
	{				
		if (strlen(user[i].info)<4)
		{
			//printf("Invalid entry!\nName is too short");
			MessageBox(0,"Invalid entry!\nName is too short","$$ERROR$$",1);
			getche();
			i--;
		}
		else if(strlen(user[i].info)>40)
		{
			//printf("Invalid entry!\nName is too long");
			MessageBox(0,"Invalid entry!\nName is too long","$$ERROR$$",1);
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
			//printf("Invalid Date");
			MessageBox(0,"Invalid Date","$$ERROR$$",1);
			getche();
			i--;
		}
	}
	else if(i==3)
	{
		tdate();
		char check[20];
		strcpy(check,user[i-1].info);
		char *dd = strtok(check,"/");
		char *mm =strtok(NULL,"/");
		char *yy =strtok(NULL,"/");
		if((sysdate[2]-atoi(yy)<atoi(user[i].info))||(sysdate[2]-atoi(yy)>atoi(user[i].info)+1))
		{
			i--;
			//printf("Age seems wrong\n");
			MessageBox(0,"ENTER THE CORRECT AGE","$$ERROR$$",1);
			getche();
		}
	}
	else if(i==4)
	{
		//No conditions
	}
	else if(i==5)
	{
		//user[i].info
		int kn=i;
		if(strlen(user[i].info)!=10)
		{
			//printf("Invalid PAN\n");
			MessageBox(0,"ENTER VALID PAN NUMBER","$$ERROR$$",1);
			i--;
		}
		else
		{
			for(int j=5;j<9;j++)
			{
				if(!(user[i].info[j]>47&&user[i].info[j]<58))
				{
					//printf("Invalid PAN\n");
					MessageBox(0,"ENTER VALID PAN NUMBER","$$ERROR$$",1);
					i--;
					break;
				}
			}
			if(kn==i)
			{
				for(int j=0;j<5;j++)
				{
					if(!(user[i].info[j]>64&&user[i].info[j]<91))
					{
						//printf("Invalid PAN\n");
						MessageBox(0,"ENTER VALID PAN NUMBER","$$ERROR$$",1);
						i--;
						break;
					}
				}
			}
			if(kn==i)
			{
				if(!(user[i].info[9]>64&&user[i].info[9]<91))
				{
					//printf("Invalid PAN\n");
					MessageBox(0,"ENTER VALID PAN NUMBER","$$ERROR$$",1);
					i--;
				}
			}
		}
		getche();
	}
	else if(i==6)
	{
		//No conditions
	}
	else if(i==7)
	{
		//No conditions
	}
	else if(i==8)
	{
		int zs = i;
		for(int j=0;j<strlen(user[i].info);j++)
		{
			if(!(user[i].info[j]>47&&user[i].info[j]<58))
			{
				//printf("Invalid Adhaar Number\n");
				MessageBox(0,"ENTER VALID AADHAR NUMBER","$$ERROR$$",1);
				i--;
				break;
			}
		}
		if(strlen(user[i].info)!=12&&zs==i)
		{
			//printf("Invalid Aadhar Number\n");
			MessageBox(0,"ENTER VALID AADHAR NUMBER","$$ERROR$$",1);
			i--;
		}
		getche();
	}
	else if(i==9)
	{
		//user[i].info
		int zs = i;
		for(int j=0;j<strlen(user[i].info);j++)
		{
			if(!(user[i].info[j]>47&&user[i].info[j]<58))
			{
				//printf("Invalid Phone Number\n");
				MessageBox(0,"ENTER VALID PHONE NUMBER","$$ERROR$$",1);
				i--;
				break;
			}
		}
		if(strlen(user[i].info)!=10&&zs==i)
		{
			//printf("Invalid Phone Number\n");
			MessageBox(0,"ENTER VALID PHONE NUMBER","$$ERROR$$",1);
			i--;
		}
		getche();
	}
	else if(i==10)
	{
		
		int zs = i;
		for(int j=0;j<strlen(user[i].info);j++)
		{
			if(!(user[i].info[j]>47&&user[i].info[j]<58))
			{
				//printf("Enter in numbers only\n");
				MessageBox(0,"ENTER  NUMBERS ONLY ","$$ERROR$$",1);
				i--;
				break;
			}
		}
		if(atoi(user[i].info)<500&&zs==i)
		{
			//printf("Minimum Deposite amount is 500\n");
			MessageBox(0,"Minimum Deposite amount is 500","$$ERROR$$",1);
			i--;
		}
		else if(atoi(user[i].info)>100000&&zs==i)
		{
			//printf("Maximum Deposite amount is 10000\n");
			MessageBox(0,"Maximum Deposite amount is 100000","$$ERROR$$",1);
			i--;
		}
		getche();
	}
	else if(i==11)
	{
		if (strlen(user[i].info)<4)
		{
			//printf("Invalid entry!\nUsername is too short");
			MessageBox(0,"Invalid entry!\nUsername is too short","$$ERROR$$",1);
			getche();
			i--;
		}
		else if(strlen(user[i].info)>12)
		{
			//printf("Invalid entry!\nUsername is too long");
			MessageBox(0,"Invalid entry!\nUsername is too long","$$ERROR$$",1);
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


void encryption(char E_file[])
{
	char ch,ch1='A';
	FILE *fp ,*tfp;
	fp=fopen(E_file,"r");
	tfp=fopen("tempf.dat","w");
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
	tfp=fopen("tempf.dat","r");
	fp=fopen(E_file,"w");
	if(fp==NULL || tfp==NULL)
	{
		//printf("Error while encryption\n");
		MessageBox(0,"Error while encryption","$$ERROR$$",1);
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
	//printf("\nFile encrypted succesfully");
}

void decryption(char E_file[])
{
	char ch,ch1='A';
	FILE *fp ,*tfp;
	fp=fopen(E_file,"w");
	tfp=fopen("tempf.dat","r");
	if(fp==NULL || tfp==NULL)
	{
		//printf("Error while decryption\n");
		MessageBox(0,"Error while decryption","$$ERROR$$",1);
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
	//printf("\nFile decrypted succesfully");
}


void upi_password()
{
	char passkey[5];
	char numbers[] = "0123456789";
	upi_key:
	printf("\n");
    printf("\nEnter your 4 digit upi password");scanf("%s",passkey);   
	if(strlen(passkey)!=4)
	{
		//printf("Password should be exactly 4 digits\n");
		MessageBox(0,"Password should be exactly 4 digits","$$ERROR$$",1);
		goto upi_key;
	}
	for(int j=0;j<4;j++)
	{
		if(!(passkey[j]>47&&passkey[j]<58))
		{
			//printf("Password should be only digits\n");
			MessageBox(0,"Password should be only digits","$$ERROR$$",1);
			goto upi_key;
		}
	}
	strcpy(user[14].info,passkey);
}

int password_validity(char a[])
{
	int l=0,L=0,c=0,n=0;
	char symbols[] = "!@#$%^&*()_-/|+.,:;\"'";
	if(strlen(a)<8)
	{
		//printf("Password is too short\n");
		MessageBox(0,"Password is too short","$$ERROR$$",1);
		return 0;
	}
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]<=57&&a[i]>=48)
		{
			n++;
		}
		else if(a[i]<=90&&a[i]>=65)
		{
			L++;
		}
		else if(a[i]<=122&&a[i]>=97)
		{
			l++;
		}
		else
		{
			for(int j=0;j<strlen(symbols);j++)
			{
				if(a[i]==symbols[j])
				{
					c++;
					break;
				}
			}
		}
	}
	if(l&&L&&c&&n)
	{
		return 1;
	}
	else if(l==0)
	{
		MessageBox(0,"Password must contain atleast 1 lowercase letter","$$ERROR$$",1);
		//printf("Password must contain atleast 1 lowercase letter\n");
	}
	else if(L==0)
	{
		MessageBox(0,"Password must contain atleast 1 uppercase letter","$$ERROR$$",1);
		//printf("Password must contain atleast 1 uppercase letter\n");

	}
	else if(c==0)
	{
		MessageBox(0,"Password must contain atleast 1 special charedcter","$$ERROR$$",1);
		//printf("Password must contain atleast 1 special charedcter\n");
	}
	else if(n==0)
	{
		MessageBox(0,"Password must contain atleast 1 number","$$ERROR$$",1);
		//printf("Password must contain atleast 1 number\n");
	}
	return 0;
}

void display_bank()
{
	printf("Bank Name:\t\t\t%s\nIFSC Code:\t\t\t%s\nBranch:\t\t\t%s\nPh Number:\t\t\t%s\nAddress:\t\t\t%s\nEmail ID:\t\t\t%s\n",Bank_Name,IFSC_code,Branch,Bank_Ph,Bank_add,bank_mail);
}
/*
void gotoxy(short int col,short int row)//this function is to place the cursor at given "row" and "col"
{
    HANDLE hStdout= GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position={col,row};
    SetConsoleCursorPosition(hStdout,position);
}*/