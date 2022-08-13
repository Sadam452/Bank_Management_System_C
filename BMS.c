/*
After performimng this lab,student should be able to:
1. Understand concept of files
2. understand How to add records to files
3. understand How to retrieve information from files
4. understand Functions
5. understand How to delete, rename, update files
6. understand How to filter the data
7. How to pass values to functions
8. How to work with strings
9. understand Concept of loops, conditional statements
10. understand How to use Windows functions (like chnaging color of text, clear the screen)
11. Work with structures
12. understand Switch
13. How to update data in one file while taking condition on other file
14. Arrays
15. Error handling in c programming
16. understand pointers
17. How to access system functions like - text colour, background colour, data & time, sound.

Design Thinking Activity:
Problem:   Bank Management System
Generate Ideas:
Login Options:
                         1 : Admin
                         2 : User
                         3 : Create User account
                         4 : Create Admin account
                         5 : Clear Screen
                         6 : Exit
                         Enter your choice[1/2/3/4] :
                         
                         //admin
                          Login type : Admin  [ id ]
                         Menu
                        1. Add an account
                        2. View all accounts
                        3. Check account balance
                        4. View a particular account
                        5. Update Details
                        6. Account Deletion
                        7. View profile
                        8. Change password
                        9. Clear the screen
                        10. Logout
                           Your Choice =
                           
                           // user
                            Login type : User  [ id ]
                         Menu
                        1. Check account balance
                        2. Deposit Money
                        3. Withdraw Money
                        4. Update Details
                        5. View profile
                        6. Transfer Money
                        7. Change Password
                        8. Transaction history
                        9. Account ststement
                        10. Clear the screen
                        11. Logout
                           Your Choice[1/2/3/4/5/6/7/8/9/10/11] =
                           
*/

#include <stdio.h>
#include <windows.h>
#include <time.h> //for date and time
#include <errno.h> // for perror() and strerror() to work for detecting errors
#include<conio.h>

//structure for an account
struct account
{
	char name[30],fName[30];
    long int acc_no;
	int age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    char dob[12];
    char email[30];
}customer,add;

//structure for admin
struct admin
{
	char name[30],id[10],dob[12],email[30],password[10];
	double phone;
}adm,admm;

//structure for users
struct user
{
	long int acc_no;
	char id[10],password[10];
}users;

void title(){
	printf("\n\t\t\t %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
	printf("\n\t\t\t %% Bank Management System %%%");
	printf("\n\t\t\t %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
}

//function to clear the screen
inline void clrscr(){
    system("cls");
}

//This function is used to chamge backgroud and text color
void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

//function to add bank account to file "accounts.dat"
void add_account(){
	char choice;
	printf("\n[Enter details to create an account]\n");
	printf("Account Holder's Name[upto 30 characters, Underscore separated(_)] :");
	scanf("%s",&customer.name);
	printf("Account Holder's Father's Name[upto 30 characters, Underscore separated(_)] :");
	scanf("%s",&customer.fName);
	printf("Account Holder's Age[Integer] :");
	scanf("%d",&customer.age);
	printf("Account Holder's Address[upto 60 characters, Underscore separated(_)] :");
	scanf("%s",&customer.address);
	printf("Account Holder's Citizenship[upto 15 characters, Underscore separated(_)] :");
	scanf("%s",&customer.citizenship);
	printf("Account Holder's Contact[10 digit Number] :");
	scanf("%lf",&customer.phone);
	printf("Account Number[Number 5 to 8 digits] :");
	scanf("%ld",&customer.acc_no);
	printf("Account Type[upto 10 characters, Underscore separated(_)] :");
	scanf("%s",&customer.acc_type);
	printf("Account Openeing Balance[Real Number] :");
	scanf("%f",&customer.amt);
	printf("Account Holder's DOB[01-01-2022 format] :");
	scanf("%s",&customer.dob);
	printf("Account Holder's Email[upto 30 characters, no spaces] :");
	scanf("%s",&customer.email);
	SetColorAndBackground(4,0);
	printf("\n\t\t\tProcessing your details...");
	SetColorAndBackground(15,0);
	sleep(3);
	printf("\nWe have recieved the following details:\n");
	printf("///////////////////////////////////////////");
	printf("\nName : %s",customer.name);
	printf("\nFathers Name : %s",customer.fName);
	printf("\nAge : %d",customer.age);
	printf("\nAddress : %s",customer.address);
	printf("\nCitizenship : %s",customer.citizenship);
	printf("\nContact : %lf",customer.phone);
	printf("\nAccount Number : %ld",customer.acc_no);
	printf("\nAccount Type : %s",customer.acc_type);
	printf("\nAccount Balance : %f",customer.amt);
	printf("\nDOB : %s",customer.dob);
	printf("\nEmail : %s",customer.email);
	
	printf("\nDo you want to continue with the same details(y/n)?");
	scanf("%s",&choice);
	if(choice == 'y' || choice == 'Y'){

		FILE *outFile;
		outFile = fopen("accounts.dat","a+");
		//printf("The error message is : %s\n",strerror(errno)); //to show error message if program is unable to open the file
		while(fscanf(outFile,"%s %s %d %s %s %lf %ld %s %f %s %s\n",&add.name,&add.fName,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_no,
		&add.acc_type,&add.amt,&add.dob,&add.email)!=EOF)
    	{
        	if (customer.acc_no == add.acc_no)
	        {
	        	SetColorAndBackground(4,0);
				printf("\n\t\t\tAccount no. already in use!");
				SetColorAndBackground(15,0);
				fclose(outFile);
				return;
	        }
   		}
		fprintf(outFile,"%s %s %d %s %s %lf %ld %s %f %s %s\n",customer.name,customer.fName,customer.age,customer.address,customer.citizenship,customer.phone,customer.acc_no,
				customer.acc_type,customer.amt,customer.dob,customer.email);
		fclose(outFile);
		SetColorAndBackground(4,0);
		printf("\n\t\t\t\tCreating an account...");
		SetColorAndBackground(15,0);
		sleep(3);
		printf("\n\t\t\t\tAccount has been successfully created!");
	}
	else{
		printf("\n\t\t\tWe have ignored your changes...");
	}
}

//function to display details of all accounts
void display(){
	int flag = 0; // to see whether any record has been printed or not
	FILE *outFile;
	outFile = fopen("accounts.dat","r");
	while(fscanf(outFile,"%s %s %d %s %s %lf %ld %s %f %s %s\n",&add.name,&add.fName,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_no,
	&add.acc_type,&add.amt,&add.dob,&add.email)!=EOF)
	{
		printf("\n///////////////////////////////////////////");
		printf("\nName : %s",add.name);
		printf("\nFathers Name : %s",add.fName);
		printf("\nAge : %d",add.age);
		printf("\nAddress : %s",add.address);
		printf("\nCitizenship : %s",add.citizenship);
		printf("\nContact : %lf",add.phone);
		printf("\nAccount Number : %ld",add.acc_no);
		printf("\nAccount Type : %s",add.acc_type);
		printf("\nAccount Balance : %f",add.amt);
		printf("\nDOB : %s",add.dob);
		printf("\nEmail : %s",add.email);
		flag = 1;
	}
	fclose(outFile);
	if(flag == 0){
		SetColorAndBackground(4,0);
		printf("\n\t\t\tNo record exists!");
		SetColorAndBackground(15,0);
	}
}
//function to display account details of particular account
void display_(long int account_num){
	if(account_num <= 0){
		exit(EXIT_FAILURE); //failure
	}
	int flag = 0;
	FILE *outFile;
	outFile = fopen("accounts.dat","r");
	//printf("The error message is : %s\n",strerror(errno));
	
	while(fscanf(outFile,"%s %s %d %s %s %lf %ld %s %f %s %s\n",&add.name,&add.fName,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_no,
	&add.acc_type,&add.amt,&add.dob,&add.email)!=EOF)
	{
	if (account_num == add.acc_no)
    	{
		printf("\n///////////////////////////////////////////");
		printf("\nName : %s",add.name);
		printf("\nFathers Name : %s",add.fName);
		printf("\nAge : %d",add.age);
		printf("\nAddress : %s",add.address);
		printf("\nCitizenship : %s",add.citizenship);
		printf("\nContact : %lf",add.phone);
		printf("\nAccount Number : %ld",add.acc_no);
		printf("\nAccount Type : %s",add.acc_type);
		printf("\nAccount Balance : %f",add.amt);
		printf("\nDOB : %s",add.dob);
		printf("\nEmail : %s",add.email);
		flag = 1;
		break;
   		}
	}
	fclose(outFile);
	if(flag == 0){
		SetColorAndBackground(4,0);
		printf("\n\t\t\tNo record found with input account number!");
		SetColorAndBackground(15,0);
	}
}
//function to view account balance of a particular account
void check_balance(long int account_num){
		if(account_num <= 0){
		exit(EXIT_FAILURE); //failure
	}
	int flag = 0;
	FILE *outFile;
	outFile = fopen("accounts.dat","r");
	//printf("The error message is : %s\n",strerror(errno));
	
	while(fscanf(outFile,"%s %s %d %s %s %lf %ld %s %f %s %s\n",&add.name,&add.fName,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_no,
	&add.acc_type,&add.amt,&add.dob,&add.email)!=EOF)
	{
	if (account_num == add.acc_no)
    	{
		printf("\n///////////////////////////////////////////");
		printf("\nAccount Number : %ld",add.acc_no);
		printf("\nAccount Balance : %f",add.amt);
		flag = 1;
		break;
   		}
	}
	fclose(outFile);
	if(flag == 0){
		SetColorAndBackground(4,0);
		printf("\n\t\t\tNo record found with input account number!");
		SetColorAndBackground(15,0);
	}
	
}

//This function updates the account details of a particular account
void update(long int account_num){
	if(account_num <= 0){
		exit(EXIT_FAILURE); //failure
	}
	int flag = 0;
	FILE *outFile,*outFile_;
	outFile = fopen("accounts.dat","r+");
	outFile_ = fopen("accounts_.dat","a+");
	//printf("The error message is : %s\n",strerror(errno));
	
	while(fscanf(outFile,"%s %s %d %s %s %lf %ld %s %f %s %s\n",&add.name,&add.fName,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_no,
	&add.acc_type,&add.amt,&add.dob,&add.email)!=EOF)
	{
	if (account_num == add.acc_no)
    	{
		printf("\n[Enter Updated Details]\n");
		printf("Account Holder's Age[Integer] :");
		scanf("%d",&customer.age);
		printf("Account Holder's Address[upto 60 characters, Underscore separated(_)] :");
		scanf("%s",&customer.address);
		printf("Account Holder's Contact[10 digit Number] :");
		scanf("%lf",&customer.phone);
		printf("Account Holder's DOB[01-01-2022 format] :");
		scanf("%s",&customer.dob);
		printf("Account Holder's Email[upto 30 characters, no spaces] :");
		scanf("%s",&customer.email);
		
		fprintf(outFile_,"%s %s %d %s %s %lf %ld %s %f %s %s\n",add.name,add.fName,customer.age,customer.address,add.citizenship,customer.phone,add.acc_no,
				add.acc_type,add.amt,customer.dob,customer.email);
		flag = 1;
   		}
   	else{
   		fprintf(outFile_,"%s %s %d %s %s %lf %ld %s %f %s %s\n",add.name,add.fName,add.age,add.address,add.citizenship,add.phone,add.acc_no,
				add.acc_type,add.amt,add.dob,add.email);
	   }
	}
	fclose(outFile);
	fclose(outFile_);
	remove("accounts.dat");
	rename("accounts_.dat","accounts.dat");
	if(flag == 0){
	SetColorAndBackground(4,0);
	printf("\n\t\t\tNo record found with input account number!");
	SetColorAndBackground(15,0);
	}
	else{
	SetColorAndBackground(4,0);
	printf("\n\t\t\tUpdated Successfully!");
	SetColorAndBackground(15,0);
	}	
}

//this function requests account deletion to admin[admin module will be implemented in next program]
void deletion(long int account_num){
	if(account_num <= 0){
		exit(EXIT_FAILURE); //failure
	}
	int flag = 0;
	FILE *outFile,*outFile_;
	outFile = fopen("accounts.dat","r+");
	outFile_ = fopen("accounts_.dat","a+");
	//printf("The error message is : %s\n",strerror(errno));
	while(fscanf(outFile,"%s %s %d %s %s %lf %ld %s %f %s %s\n",&add.name,&add.fName,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_no,
	&add.acc_type,&add.amt,&add.dob,&add.email)!=EOF)
	{
	if (account_num == add.acc_no)
    	{		
		flag = 1;
   		}
   	else{
   		fprintf(outFile_,"%s %s %d %s %s %lf %ld %s %f %s %s\n",add.name,add.fName,add.age,add.address,add.citizenship,add.phone,add.acc_no,
				add.acc_type,add.amt,add.dob,add.email);
	   }
	}
	fclose(outFile);
	fclose(outFile_);
	remove("accounts.dat");
	rename("accounts_.dat","accounts.dat");
	if(flag == 0){
	SetColorAndBackground(4,0);
	printf("\n\t\t\tNo record found with input account number!");
	SetColorAndBackground(15,0);
	}
	else{
	SetColorAndBackground(4,0);
	printf("\n\t\t\tDeleted Successfully!");
	SetColorAndBackground(15,0);
	}	
}

//This function adds money to particular account number
void deposit(long int account_num,float amt){
	if(amt <= 0){
		printf("\nAmount can't be negative");
		return; 
		//exit(EXIT_FAILURE); //failure
	}
	int flag = 0;
	FILE *outFile,*outFile_,*statement;
	outFile = fopen("accounts.dat","r+");
	outFile_ = fopen("accounts_.dat","a+");
	statement = fopen("statement.dat","a+");
	//printf("The error message is : %s\n",strerror(errno));
	//find date and time
	time_t seconds;
	seconds = time(NULL);
	
	while(fscanf(outFile,"%s %s %d %s %s %lf %ld %s %f %s %s\n",&add.name,&add.fName,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_no,
	&add.acc_type,&add.amt,&add.dob,&add.email)!=EOF)
	{
	if (account_num == add.acc_no)
    	{
    		float amount = amt + add.amt;
			fprintf(outFile_,"%s %s %d %s %s %lf %ld %s %f %s %s\n",add.name,add.fName,add.age,add.address,add.citizenship,add.phone,add.acc_no,
				add.acc_type,amount,add.dob,add.email);	
			fprintf(statement,"%ld %ld %s %f\n",account_num,seconds,"+",amt);
		flag = 1;
   		}
   	else{
   		fprintf(outFile_,"%s %s %d %s %s %lf %ld %s %f %s %s\n",add.name,add.fName,add.age,add.address,add.citizenship,add.phone,add.acc_no,
				add.acc_type,add.amt,add.dob,add.email);
	   }
	}
	fclose(outFile);
	fclose(outFile_);
	fclose(statement);
	remove("accounts.dat");
	rename("accounts_.dat","accounts.dat");
	printf("\n\t\t\tProcessing your request, please hold for a while...");
	sleep(2);
	if(flag == 0){
	SetColorAndBackground(4,0);
	printf("\n\t\t\tNo record found with input account number!");
	SetColorAndBackground(15,0);
	}
	else{
	SetColorAndBackground(4,0);
	printf("\n\t\t\tThe amount has been deposited Successfully, Thank you for using our services!");
	SetColorAndBackground(15,0);
	}
}

//This function withdraws money from bank account
void withdraw(long int account_num,float amt){
	if(amt <= 0){
		printf("\nAmount can't be negative");
		exit(EXIT_FAILURE); //failure
	}
	int flag = 0;
	FILE *outFile,*outFile_,*statement;
	outFile = fopen("accounts.dat","r+");
	outFile_ = fopen("accounts_.dat","a+");
	statement = fopen("statement.dat","a+");
	//printf("The error message is : %s\n",strerror(errno));
	//find date and time
	time_t seconds;
	seconds = time(NULL);

	while(fscanf(outFile,"%s %s %d %s %s %lf %ld %s %f %s %s\n",&add.name,&add.fName,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_no,
	&add.acc_type,&add.amt,&add.dob,&add.email)!=EOF)
	{
	if (account_num == add.acc_no)
    	{
    		flag = 1;
    		float amount;
    		if(add.amt >= amt){
    			amount = add.amt - amt;
    			flag = 2; // to see whether the account has enough amount
    			fprintf(statement,"%ld %ld %s %f\n",account_num,seconds,"-",amt);
			}
			else
			amount = add.amt;
		fprintf(outFile_,"%s %s %d %s %s %lf %ld %s %f %s %s\n",add.name,add.fName,add.age,add.address,add.citizenship,add.phone,add.acc_no,
				add.acc_type,amount,add.dob,add.email);		
   		}
   	else{
   		fprintf(outFile_,"%s %s %d %s %s %lf %ld %s %f %s %s\n",add.name,add.fName,add.age,add.address,add.citizenship,add.phone,add.acc_no,
				add.acc_type,add.amt,add.dob,add.email);
	   }
	}
	fclose(outFile);
	fclose(outFile_);
	fclose(statement);
	remove("accounts.dat");
	rename("accounts_.dat","accounts.dat");
	printf("\n\t\t\tProcessing your request, please hold for a while...");
	sleep(2);
	if(flag == 0){
	SetColorAndBackground(4,0);
	printf("\n\t\t\tNo record found with input account number!");
	SetColorAndBackground(15,0);
	}
	else if(flag == 2){
	SetColorAndBackground(4,0);
	printf("\n\t\t\tThe amount has been withdrawn successfully, Thank you for using our services!");
	SetColorAndBackground(15,0);
	}
	else if(flag == 1){
	SetColorAndBackground(4,0);
	printf("\n\t\t\tThis account has insufficient funds!");
	SetColorAndBackground(15,0);	
	}
}

//this function shows admin details
void viewAdminProfile(char id[10]){
	int flag = 0;
	FILE *outFile;
	outFile = fopen("admin.dat","r");
	//printf("The error message is : %s\n",strerror(errno));
	
	while(fscanf(outFile,"%s %lf %s %s %s %s\n",&adm.name,&adm.phone,&adm.id,&adm.email,&adm.password,&adm.dob)!=EOF)
	{
	if (!strcmp(id,adm.id))
    	{
			flag = 1;
			printf("\n\t Name : %s\n\t Phone : %lf\n\t DOB : %s\n\t Email : %s",adm.name,adm.phone,adm.dob,adm.email);
			break;
   		}
	}
	fclose(outFile);
	if(flag == 0){
		printf("\n\t\t\tFailed to show details !");
	}
}

//this function shows admin details
void viewUserProfile(long int acc){
	if(acc <= 0){
		exit(EXIT_FAILURE); //failure
	}
	int flag = 0;
	FILE *outFile;
	outFile = fopen("accounts.dat","r");
	//printf("The error message is : %s\n",strerror(errno));
	while(fscanf(outFile,"%s %s %d %s %s %lf %ld %s %f %s %s\n",&add.name,&add.fName,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_no,
	&add.acc_type,&add.amt,&add.dob,&add.email)!=EOF)
	{
	if (acc == add.acc_no)
    	{
			flag = 1;
			printf("\n\t Name : %s\n\t Account : %ld \n\t Phone : %lf\n\t DOB : %s\n\t Email : %s",add.name,add.acc_no,add.phone,add.dob,add.email);
			break;
   		}
	}
	fclose(outFile);
	if(flag == 0){
		printf("\n\t\t\tFailed to show details !");
	}
}

//this function creates account for user who already have bank account
void createUserAccount(){
	long int acc;
	char id[10],password[10];
	printf("\n\tEnter account number :");
	scanf("%ld",&acc);
	printf("\nEnter User ID[without spaces & < 10 characters] :");
	scanf("%s",&id);
	printf("\nEnter User Password[without spaces & < 10 characters] :");
	scanf("%s",&password);
	int flag = 0;
	FILE *outFile;
	outFile = fopen("accounts.dat","r");
	//printf("The error message is : %s\n",strerror(errno));
	while(fscanf(outFile,"%s %s %d %s %s %lf %ld %s %f %s %s\n",&add.name,&add.fName,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_no,
	&add.acc_type,&add.amt,&add.dob,&add.email)!=EOF)
	{
	if (acc == add.acc_no)
    	{		
		flag = 1;
		break;
   		}
	}
	fclose(outFile);
	if(flag == 0){
	SetColorAndBackground(4,0);
	printf("\n\t\t\tNo record found with input account number!");
	SetColorAndBackground(15,0);
	return;
	}
	//create user login account now
	char choice;
	SetColorAndBackground(4,0);
	printf("\n\t\t\tProcessing your details...");
	SetColorAndBackground(15,0);
	sleep(1);
	printf("\nWe have recieved the following details:\n");
	printf("///////////////////////////////////////////");
	printf("\nAccount num : %ld",acc);
	printf("\nUser ID : %s",id);
	printf("\nPassword : %s",password);
	char pass[10];
	strcpy(pass,password); //copying password.
	printf("\nDo you want to continue with the same details(y/n)?");
	scanf("%s",&choice);
	if(choice == 'y' || choice == 'Y'){
		outFile = fopen("users.dat","a+");
		//printf("The error message is : %s\n",strerror(errno));
		while(fscanf(outFile,"%s %ld %s\n",&users.id,&users.acc_no,&users.password)!=EOF)
    	{
        	if (users.acc_no == acc)
	        {
	        	SetColorAndBackground(4,0);
				printf("\n\t\t\tLogin account already exists!");
				SetColorAndBackground(15,0);
				fclose(outFile);
				return;
	        }
	        else if(!strcmp(users.id,id)){
	        	SetColorAndBackground(4,0);
				printf("\n\t\t\tUser ID already in use!");
				SetColorAndBackground(15,0);
				fclose(outFile);
				return;
			}
   		}
		fprintf(outFile,"%s %ld %s\n",id,acc,pass);
		fclose(outFile);
		SetColorAndBackground(4,0);
		printf("\n\t\t\t\tCreating a login account...");
		SetColorAndBackground(15,0);
		sleep(2);
		printf("\n\t\t\t\tLogin account has been successfully created!");
	}
	else{
		printf("\n\t\t\tWe have ignored your changes...");
	}
	
}

//this function creates account for user who already have bank account
void createAdminAccount(){
	printf("\nEnter name[without spaces]:");
	scanf("%s",&adm.name);
	printf("\nEnter Phone number:");
	scanf("%lf",&adm.phone);
	printf("\nEnter user id:");
	scanf("%s",&adm.id);
	printf("\nEnter Email:");
	scanf("%s",&adm.email);
	printf("\nEnter Password[lenth<10]:");
	scanf("%s",&adm.password);
	printf("\nEnter DOB:");
	scanf("%s",&adm.dob);

	int flag = 0;
	FILE *outFile;
	outFile = fopen("admin.dat","a+");
	//printf("The error message is : %s\n",strerror(errno));
	while(fscanf(outFile,"%s %lf %s %s %s %s\n",&admm.name,&admm.phone,&admm.id,&admm.email,&admm.password,&admm.dob)!=EOF)
	{
	if (!strcmp(adm.id,admm.id))
    	{		
		flag = 1;
		break;
   		}
	}
	
	if(flag == 0){
	fprintf(outFile,"%s %lf %s %s %s %s\n",adm.name,adm.phone,adm.id,adm.email,adm.password,adm.dob);
	fclose(outFile);
	SetColorAndBackground(4,0);
	printf("\n\t\t\tAdmin account created successfully!");
	}
	else{
		printf("\n\t\t\tAdmin id in use!");
	}
	SetColorAndBackground(15,0);
	
}

//this function transfers Money from one user to another
void TransferMoney(account_num){
	long int accountNum;
	float amt;
	printf("Enter Recipient's Account Number :");
	scanf("%ld",&accountNum);
	printf("Enter Amount :");
	scanf("%f",&amt);
	if(amt < 1){ //to avoid amounts less than 1 being sent
		printf("\n\t\t\tAmount must be greater or equal to 1");
		exit(EXIT_FAILURE);
	}
	if(account_num == accountNum){
		SetColorAndBackground(4,0);
		printf("\n\t\t\tSender and reciever account can't be same!");
		SetColorAndBackground(15,0);
		return;
	}
	int flag = 0;
	FILE *outFile,*outFile_,*history;
	outFile = fopen("accounts.dat","r+");
	outFile_ = fopen("accounts_.dat","a+");
	history = fopen("history.dat","a+");
//	printf("The error message is : %s\n",strerror(errno));
	while(fscanf(outFile,"%s %s %d %s %s %lf %ld %s %f %s %s\n",&add.name,&add.fName,&add.age,&add.address,&add.citizenship,&add.phone,&add.acc_no,
	&add.acc_type,&add.amt,&add.dob,&add.email)!=EOF)
	{
	if (account_num == add.acc_no){
    		flag = 1;
    		float amount;
    		if(add.amt >= amt){
    			amount = add.amt - amt;
    			flag = 2; // to see whether the account has enough amount
			}
			else
			amount = add.amt;
		fprintf(outFile_,"%s %s %d %s %s %lf %ld %s %f %s %s\n",add.name,add.fName,add.age,add.address,add.citizenship,add.phone,add.acc_no,
				add.acc_type,amount,add.dob,add.email);		
   		}
    else if( accountNum == add.acc_no ){
   		float amount_ = add.amt + amt;
   		fprintf(outFile_,"%s %s %d %s %s %lf %ld %s %f %s %s\n",add.name,add.fName,add.age,add.address,add.citizenship,add.phone,add.acc_no,
				add.acc_type,amount_,add.dob,add.email);
		
	   }
	else {
		fprintf(outFile_,"%s %s %d %s %s %lf %ld %s %f %s %s\n",add.name,add.fName,add.age,add.address,add.citizenship,add.phone,add.acc_no,
				add.acc_type,add.amt,add.dob,add.email);
	}
	}
	fclose(outFile);
	fclose(outFile_);
	printf("\n\t\t\tProcessing your request, please hold for a while...");
	sleep(2);
	if(flag == 0){
	remove("accounts_.dat");
	SetColorAndBackground(4,0);
	printf("\n\t\t\tNo record found with input account number!");
	SetColorAndBackground(15,0);
	}
	else if(flag == 2){
	remove("accounts.dat");
	rename("accounts_.dat","accounts.dat");
	//save details to history.dat
	fprintf(history,"%ld %ld %f\n",account_num,accountNum,amt);
	fclose(history);
	SetColorAndBackground(4,0);
	printf("\n\t\t\tThe amount has been withdrawn successfully, Thank you for using our services!");
	SetColorAndBackground(15,0);
	}
	else if(flag == 1){
	remove("accounts_.dat");
	SetColorAndBackground(4,0);
	printf("\n\t\t\tThis account has insufficient funds!");
	SetColorAndBackground(15,0);	
	}
}

//This function changes password of user
void ChangePassword(account_num){
	char newPassword[10];
	printf("Enter New Password :");
	scanf("%s",&newPassword);
	int flag = 0;
	FILE *outFile,*outFile_;
	outFile = fopen("users.dat","r+");
	outFile_ = fopen("users_.dat","a+");
	//printf("The error message is : %s\n",strerror(errno));
	while(fscanf(outFile,"%s %ld %s\n",&users.id,&users.acc_no,&users.password)!=EOF)
	{
	if (account_num == users.acc_no){
    		flag = 1;
			fprintf(outFile_,"%s %ld %s\n",users.id,users.acc_no,newPassword);		
   		}
    else{
   		fprintf(outFile_,"%s %ld %s\n",users.id,users.acc_no,users.password);
	   }
	}
	fclose(outFile);
	fclose(outFile_);
	remove("users.dat");
	rename("users_.dat","users.dat");
	printf("\n\t\t\tProcessing your request, please hold for a while...");
	sleep(2);
	if(flag == 0){
	SetColorAndBackground(4,0);
	printf("\n\t\t\tNo record found with input account number!");
	SetColorAndBackground(15,0);
	}
	else if(flag == 1){
	SetColorAndBackground(4,0);
	printf("\n\t\t\tThe password has been updated successfully!");
	SetColorAndBackground(15,0);
	}
}

//show transaction history
void transactions(long int account_num){
	FILE *history;
	long int raccount,saccount;
	float amount;
	history = fopen("history.dat","r");
	SetColorAndBackground(10,0);
	while(fscanf(history,"%ld %ld %f\n",&saccount,&raccount,&amount)!=EOF){
		if(saccount == account_num || raccount == account_num){
			printf("\nSender : %ld\t\tReciever : %ld\t\tAmount : %f",saccount,raccount,amount);
		}
		
	}
	SetColorAndBackground(15,0);
}
//this function changes admin password
void ChangePasswordAdmin(char adminID[10]){
	char newPassword[10];
	printf("Enter New Password :");
	scanf("%s",&newPassword);
	int flag = 0;
	FILE *outFile,*outFile_;
	outFile = fopen("admin.dat","r+");
	outFile_ = fopen("admin_.dat","a+");
	//printf("The error message is : %s\n",strerror(errno));
	
	while(fscanf(outFile,"%s %lf %s %s %s %s\n",&admm.name,&admm.phone,&admm.id,&admm.email,&admm.password,&admm.dob)!=EOF)
	{
	if (!strcmp(adminID,admm.id)){
    		flag = 1;
			fprintf(outFile_,"%s %lf %s %s %s %s\n",admm.name,admm.phone,admm.id,admm.email,newPassword,admm.dob);		
   		}
    else{
   		fprintf(outFile_,"%s %lf %s %s %s %s\n",admm.name,admm.phone,admm.id,admm.email,admm.password,admm.dob);
	   }
	}
	fclose(outFile);
	fclose(outFile_);
	remove("admin.dat");
	rename("admin_.dat","admin.dat");
	printf("\n\t\t\tProcessing your request, please hold for a while...");
	sleep(2);
	if(flag == 0){
	SetColorAndBackground(4,0);
	printf("\n\t\t\tNo record found with input account number!");
	SetColorAndBackground(15,0);
	}
	else if(flag == 1){
	SetColorAndBackground(4,0);
	printf("\n\t\t\tThe password has been updated successfully!");
	SetColorAndBackground(15,0);
	}
}

//This function shows current date and time
void dateTime_(){
	time_t t= time(NULL);
	struct tm tm = *localtime(&t);
	printf("\n\t\t\t Date & Time is : %d-%02d-%02d %02d:%02d:%02d",tm.tm_mday,tm.tm_mon + 1,tm.tm_year + 1900,tm.tm_hour,tm.tm_min,tm.tm_sec);
}

//Account statement - deposits and withdrawls
void statement(long int account_num){
	FILE *history;
	char status[2];
	float amount;
	long int account,date;
	history = fopen("statement.dat","r");
	SetColorAndBackground(10,0);
	//fprint(statement,"%ld %s %s %f\n",account_num,date,"+",amt);
	while(fscanf(history,"%ld %ld %s %f\n",&account,&date,&status,&amount)!=EOF){
		if(account == account_num){
			printf("\n\t\tTransaction ID : %ld\t\tStatus : %s%f",date,status,amount);
		}
		
	}
	fclose(history);
	SetColorAndBackground(15,0);
}
//admin module
void admin(){
    char adminID[10],password[10];
    long int account_num;
    int choice = 0;
	printf("\n\t\t\tLogin type : Admin");
    printf("\n\t\t\tEnter Admin id[without spaces & length <= 10]: ");
    scanf("%s",&adminID);
    printf("\t\t\tEnter Admin password[without spaces & length <= 10]: ");
    scanf("%s",&password);

	//authenticating the admin login
	int flag = 0;
	FILE *outFile;
	outFile = fopen("admin.dat","r");
	//printf("The error message is : %s\n",strerror(errno));
	
	while(fscanf(outFile,"%s %lf %s %s %s %s\n",&adm.name,&adm.phone,&adm.id,&adm.email,&adm.password,&adm.dob)!=EOF)
	{
	if (!strcmp(adminID,adm.id) && !strcmp(password,adm.password))
    	{
			flag = 1;
			break;
   		}
	}
	fclose(outFile);
	if(flag == 1){
		printf("\n\t\t\tLogged in Successfully !");
	}
	else{
		printf("\n\t\t\tLogin failed, Check your id and password !");
		return;
	}
	//showing options after successful login
    while(choice != 10){
		printf("\n\t\t\t Login type : Admin  [ %s ]",adminID);
        printf("\n\t\t\t Menu");
        printf("\n\t\t\t1. Add an account\n\t\t\t2. View all accounts\n\t\t\t3. Check account balance\n\t\t\t4. View a particular account"
		"\n\t\t\t5. Update Details \n\t\t\t6. Account Deletion \n\t\t\t7. View profile \n\t\t\t8. Change Password\n\t\t\t9. Clear the screen\n\t\t\t10. Logout"
		"\n\t\t\t   Your Choice[1/2/3/4/5/6/7/8/9/10] = ");
        scanf("%d",&choice);
        switch(choice){
			case 1:
				add_account();
				break;
			case 2:
				display();
				break;
			case 3:
				printf("Enter account number:");
				scanf("%ld",&account_num);
				check_balance(account_num);
				break;
			case 4:
				printf("Enter account number:");
				scanf("%ld",&account_num);
				display_(account_num);
				break;
			case 5:
				printf("Enter account number:");
				scanf("%ld",&account_num);
				update(account_num);
				break;
			case 6:
				printf("Enter account number:");
				scanf("%ld",&account_num);
				deletion(account_num);
				break;
			case 7:
				viewAdminProfile(adminID);
				break;
			case 8:
				ChangePasswordAdmin(adminID);
				break;
			case 9:
				clrscr();
				SetColorAndBackground(12,0);
				title();
				SetColorAndBackground(13,0);
				dateTime_();
				SetColorAndBackground(15,0); 
				break;
			case 10:
				break;
			default:
				printf("\nPlease choose a valid option!"); 
		    }
    }
    SetColorAndBackground(4,0);
	printf("\n\t\t\t Logging out...");
	SetColorAndBackground(15,0);
	sleep(2);
}
void user(){
    char id[10],password[10];
    long int account_num;
    float amount;
    int choice = 0;
	printf("\n\t\t\tLogin type : User");
    //fflush(stdin);
    printf("\n\t\t\tEnter User id[without spaces & length <= 10]: ");
    scanf("%s",&id);
    printf("\t\t\tEnter User password[without spaces & length <= 10]: ");
    scanf("%s",&password);

	//authenticating the admin login
	int flag = 0;
	FILE *outFile;
	outFile = fopen("users.dat","r");
	//printf("The error message is : %s\n",strerror(errno));
	  
	while(fscanf(outFile,"%s %ld %s\n",&users.id,&users.acc_no,&users.password)!=EOF)
	{
	if (!strcmp(id,users.id) && !strcmp(password,users.password))
    	{
			flag = 1;
			account_num = users.acc_no;
			break;
   		}
	}
	fclose(outFile);
	if(flag == 1){
		printf("\n\t\t\tLogged in Successfully !");
	}
	else{
		printf("\n\t\t\tLogin failed, Check your id and password !");
		return;
	}
	//showing options after successful login
    while(choice != 11){
		printf("\n\t\t\t Login type : User  [ %s ]",id);
        printf("\n\t\t\t Menu");
        printf("\n\t\t\t1. Check account balance\n\t\t\t2. Deposit Money\n\t\t\t3. Withdraw Money \n\t\t\t4. Update Details \n\t\t\t5. View profile"
		"\n\t\t\t6. Transfer Money\n\t\t\t7. Change Password\n\t\t\t8. Transaction History\n\t\t\t9. Statement\n\t\t\t10. Clear the screen\n\t\t\t11. Logout"
		"\n\t\t\t   Your Choice[1/2/3/4/5/6/7/8/9/10/11] = ");
        scanf("%d",&choice);
        switch(choice){
			case 1:
				check_balance(account_num);
				break;
			case 2:
				printf("Enter amount to deposit:");
				scanf("%f",&amount);
				deposit(account_num,amount);
				break;
			case 3:
				printf("Enter amount to withdraw:");
				scanf("%f",&amount);
				withdraw(account_num,amount);
				break;
			case 4:
				update(account_num);
				break;
			case 5:
				viewUserProfile(account_num);
				break;
			case 6:
				TransferMoney(account_num);
				break;
			case 7:
				ChangePassword(account_num);
				break;
			case 8:
				transactions(account_num);
				break;
			case 9:
				statement(account_num); 
				break;
			case 10:
				clrscr();
				SetColorAndBackground(12,0);
				title();
				SetColorAndBackground(13,0);
				dateTime_();
				SetColorAndBackground(15,0);
				break;
			case 11:
				break;
			default:
				printf("\n\t\t\tPlease choose a valid option!"); 
		    }
    }
    SetColorAndBackground(4,0);
	printf("\n\t\t\t Logging out...");
	SetColorAndBackground(15,0);
	sleep(2);
}
int main(){
	SetColorAndBackground(12,0);
	title();
	SetColorAndBackground(13,0); 
	dateTime_();
	SetColorAndBackground(15,0);

	int choice = 0;
	while(1){
		printf("\n\t\tLogin Options:");
    	printf("\n\t\t\t 1 : Admin ");
    	printf("\n\t\t\t 2 : User ");
    	printf("\n\t\t\t 3 : Create User account ");
    	printf("\n\t\t\t 4 : Create Admin account ");
    	printf("\n\t\t\t 5 : Clear Screen ");
		printf("\n\t\t\t 6 : Exit");
		printf("\n\t\t\t Enter your choice[1/2/3/4] : ");
  		scanf("%d",&choice);
  		if(choice == 1){
		admin();
		}
		else if(choice == 2){
			user();
		}
		else if(choice == 3){
			createUserAccount();			
		}
		else if(choice == 4){
			createAdminAccount();
		}
		else if(choice == 5){
			clrscr();
			SetColorAndBackground(12,0);
			title();
			SetColorAndBackground(13,0); 
			dateTime_();
			SetColorAndBackground(15,0); 
		}
		else if(choice == 6){
			printf("\a");
			printf("\n\t\t\tExiting the Menu...");
			sleep(1);
			break;
		}
		else
		printf("\n\t\t\t Please choice the correct option[1/2/3/4/5/6]");
	}
	printf("Exiting...END OF THE PROGRAM");
	return 0;
}
