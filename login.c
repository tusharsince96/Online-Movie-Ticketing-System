#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct customer{
	char fname[20];
	char lname[20];
	char dob[20];
	char mob[20];
	char city[20];
	char username[20];
	char password[16];
}customer;

typedef struct adminAcc{
	char fname[20];
	char lname[20];
	char mob[20];
	char adminname[20];
	char password[20];	
}adminAcc;

struct movie{
	char mcode[10];
	char mname[20];
	char reldate[12];
	int cost;
};

struct book
{
	int mnum;
	char cname[30];
	char mname[30];
	char mdate[12];
	int mtimehour;
	int mtime;
	char ttype[30];
	int guestsnum;
	int housenum;
	int fee;
};

void user();
void registerUser();
void loginUser();
void userOption();
void userBook();
void admin();
void registerAdmin();
void adminBook();
void addMov();
void addMovie();
void dispMov();
void modMov();
void findMov();
void delMov();
void showmovie();

void count()
{
	int l=0;
	FILE *fp;
	customer c;	
	fp = fopen("userdetail.txt","r");
	if(fp==NULL)
		printf("\tFile not Found.\n");
	else
	{		
		while(fread(&c, sizeof(customer), 1, fp))		
		{
			printf("\tName : %s %s\tDOB : %s\tMOB : %s\tCity : %s\n\tUsername : %s\tPassword : %s\n",
			c.fname, c.lname, c.dob, c.mob, c.city, c.username, c.password);
			l++;
		}
		printf("\tTotal record = %d\n", l);
	}
	fclose(fp);
	l=0;	struct book b;
	fp = fopen("ticket.txt","r");
	if(fp==NULL)
		printf("\tFile not Found.\n");
	else
	{		
		while(fread(&b, sizeof(struct book), 1, fp))		
			l++;
		printf("\tTotal Booking record = %d\n", l);
	}
	fclose(fp);
}

void main()
{
	int ch;		
	printf("\n  ++++++++++++++++++++++++++++++  WELCOME  ++++++++++++++++++++++++++++++  \n\n");
	while(1)
	{
		printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
		printf("\t\t\t Movie Ticket Booking System ");
		printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n\tEnter >1< User Login for Booking.");
   		printf("\n\tEnter >2< Admin Login.");
		printf("\n\tEnter >3< Quit.\n");		
		printf("\n\tEnter Your Choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				system("cls");
				user();
				break;
			case 2:
				system("cls");
				admin();
				break;
			case 3:
				printf("\tSee you next time :)\n");				
				printf("\n\tPress any key to Quit...");
				getch();//holds the screen
				system("cls");
				exit(1);
			default :
				printf("\tPlease choose from (1-3)!\n");				
		}
	}
}

void registerAdmin()
{
	FILE *fp;
	adminAcc c;
	char cpas[20], pas[20];
	fp = fopen("admindetail.txt","a");
	printf("\n\n  ++++++++++++++++++++++++++++++  ADMIN REGISTRATION  ++++++++++++++++++++++++++++++  \n\n");
	printf("\n\tEnter First Name : ");	
	scanf("%s",c.fname);
	printf("\n\tEnter Last Name : ");	
	scanf("%s",c.lname);	
	printf("\n\tEnter Mobile Number : ");	
	scanf("%s",c.mob);
	printf("\n\tEnter Admin Username : ");	
	scanf("%s",c.adminname);
	printf("\tEnter Admin Password(min 8 and max 16 character) : ");
	scanf("%s",pas);
	printf("\tRe-enter your Password : ");
	scanf("%s",cpas);
	while(strcmp(pas, cpas)!=0)
	{
		printf("\tPassword does not match !!\n");
		printf("\tEnter your Password (min 8 and max 16 character) : ");
		scanf("%s",pas);
		printf("\tRe-enter your Password : ");
		scanf("%s",cpas);
	};
	strcpy(c.password, cpas);
	fwrite(&c, sizeof(adminAcc), 1, fp);
	printf("\n\tNew Admin Registered..!!\n");
	fclose(fp);
}

void admin()
{
	char user[20], pass[16];
	adminAcc a;
	printf("\n\n  ++++++++++++++++++++++++++++++  ADMIN LOGIN  ++++++++++++++++++++++++++++++  \n\n");
	int flag=0;
	printf(" \n\n                  ENTER USERNAME:- ");
	scanf("%s", user);
	printf(" \n                  ENTER PASSWORD:- ");
	scanf("%s", pass);
	FILE *fp;
	fp =fopen("admindetail.txt","r");
	if (fp==NULL)
 	{	
	    printf("\tFile not found!");
    }   
	else
	{	
		while(fread(&a, sizeof(adminAcc), 1, fp))
		{
			if (strcmp(user, a.adminname)==0)
    		{	  	
    			flag=1;
    			if(strcmp(pass, a.password)==0)
			  	{
			  		printf("\n\tAuthentication Successful.\n");
			  		printf("\n\tPress any key to continue...");
					getch();//holds the screen
			  		fclose(fp);
			  		system("cls");
			  		adminBook();
			  		break;
				}
				else
				{
					printf("\n\tAccess Denied.\n");
					printf("\n\tPress any key...");
					getch();//holds the screen
					fclose(fp);
					system("cls");
					main();
					break;
				}							  	
			}
  		}
  		if(!flag)
  		{		 
  			printf("\n\tYou are not authorised!!");
  			printf("\n\tPress any key...");
			getch();//holds the screen
			system("cls");
  		}
	}	
}

void adminBook()
{
	int ch;
	printf("\n  ++++++++++++++++++++++++++++++  ADMIN OPTION  ++++++++++++++++++++++++++++++  \n\n");
	while(1)
	{
		printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
		printf("\t\t\t Movie Ticket Booking System ");
		printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n\tEnter >1< Register New Admin");
	   	printf("\n\tEnter >2< Add New Movie Ticket Record(s)");
		printf("\n\tEnter >3< Add New Movie Record(s)");
		printf("\n\tEnter >4< Display All Movie Ticketing Records");
		printf("\n\tEnter >5< Search Movie Ticketing Record(s)");
		printf("\n\tEnter >6< Delete Movie Ticketing Record(s)");
	   	printf("\n\tEnter >7< Display All Movies");	   	
	   	printf("\n\tEnter >8< Logout & Exit\n");
		printf("\n\tEnter your Choice : ");
		scanf("%d", &ch);		
		switch(ch)
		{
			case 1:
				system("cls");
				registerAdmin(); // Add new admin
				break;
			case 2:				
				addMov(); /* Add New Movie Ticketing Records function go here*/
				break;
			case 3:
				addMovie(); // Adding New movie
				break;
			case 4:
				dispMov(); /* Display All Movie Ticketing Records function go here */
				printf("\n\tPress any key to go to Main Menu...");
				getch();//holds the screen
    			system("cls");
				break;			
			case 5:
				findMov(); /* Search Movie Ticketing Records function go here */
				break;
			case 6:
				delMov(); /* Delete Movie Ticketing Records function go here */				
				break;
			case 7:
				showmovie();
				printf("\n\tPress any key to go to Main Menu...");
				getch();//holds the screen
    			system("cls");				
				break;
			case 8:
				printf("\tYou have been logged out!!\n\tSee you next time :)\n");
				printf("\n\tPress any key to Exit...");
				getch();//holds the screen
				system("cls");
				return;
				break;
			default:
				printf("\tPlease select a correct number (1-7)!");
		}
	}
}

void addMov()
{
	struct book b;
	struct movie m;
	char code[10];
	char op;
	FILE *fp, *fpm;
	fpm = fopen("moviedetail.txt", "r");
	showmovie();
	printf("\n\tEnter movie Code : ");
	scanf("%s",code);	
	while(fread(&m, sizeof(struct movie), 1, fpm))
	{
		if(strcmp(code, m.mcode)==0)
		{			
			printf("\n\tName of Movie : %s\n", m.mname);
			printf("\tRelease Date : %s\n", m.reldate);
			printf("\tFee of Movie : %d\n", m.cost);
			break;
		}
	}
	fclose(fpm);
	printf("\n");
	b.mnum = rand();
	printf("\tMovie Booking Number : %d\n",b.mnum);
	printf("\tEnter Name of Customer: ");	
	gets(b.cname);
	gets(b.cname);
	strcpy(b.mname, m.mname);
	printf("\tEnter Movie Schedule (DD-MM-YYYY): ");	
	gets(b.mdate);
	printf("\tEnter Time (HHMM) (No Special Character): ");
	scanf("%d",&b.mtime);
	while(b.mtime<1000||b.mtime>2300)
	{
		printf("\tRe-enetr Time! It should be in 24-hour format and between 1000 to 2300!: ");	
		scanf("%d",&b.mtime);
	};
	printf("\tEnter Number of Guests: ");	
	scanf("%d",&b.guestsnum);
	printf("\tEnter Hall Number: ");
	scanf("%d",&b.housenum);
	printf("\tEnter Row & Seat No. (R1S12 R1S13) : ");
	gets(b.ttype);
	gets(b.ttype);	
	b.fee = b.guestsnum*m.cost;
	printf("\tYour Total Fee: %d\n",b.fee);	
	fp=fopen("ticket.txt","a+");
	if(fp == NULL)
	{
		printf("\tFile not found!");
	}
	else
	{		
		fwrite(&b,sizeof(struct book),1,fp);
		printf("\n\tRecord insert sucessful!");
	}
	printf("\n");
	fclose(fp);
	do
	{
		printf("\tAdd another record (y/n)?");
		scanf("%c",&op);
		switch(op)
		{
			case 'y':				
				addMov();
			case 'n':				
				system("cls");
				return;
			default:
				printf("\tPlease select (y) or (n)!\n");
		}
	} while(op!='n');
}

void addMovie()
{	
	FILE *fp;
	char op;
	struct movie b;
	printf("\tEnter movie Code : ");	
	scanf("%s",b.mcode);
	printf("\tEnter Movie Name : ");	
	scanf("%s",b.mname);
	printf("\tEnter Release Date: ");	
	scanf("%s",b.reldate);
	printf("\tEnetr Ticket Price: ");	
	scanf("%d",&b.cost);
	
	fp=fopen("moviedetail.txt","a+");

	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fwrite(&b, sizeof(struct movie), 1, fp);
		printf("\tRecorded Successfully");
	}
	printf("\n");
	fclose(fp);
	fflush(stdin);
	do
	{
		printf("\tAdd another record (y/n)?");
		scanf("%c",&op);
		switch(op)
		{
			case 'y':				
				addMovie();
			case 'n':				
				system("cls");
				return;
			default:
				printf("\tPlease select (y) or (n)!\n");
		}
	} while(op!='n');	
	
}

void dispMov()
{	
	struct book b;
	FILE *fp;	
	fp = fopen("ticket.txt","r");
	if(fp == NULL)
	{
		printf("\tFile not found!");		
	}
	else
	{	
		while(fread(&b, sizeof(struct book), 1, fp))
    	{
    		printf("\n\n\tBooking number: %d\n", b.mnum);
			printf("\tName of Customer: %s\n",b.cname);			
			printf("\tName of Movie: %s\n", b.mname);	
			printf("\tMovie Schedule: %s\n", b.mdate);	
			printf("\tShow Timing (MMHH): %d\n", b.mtime);
			printf("\tNumber of Guests: %d\n", b.guestsnum);
			printf("\tHall Number: %d\n", b.housenum);		
			printf("\tRow and Seat: %s\n", b.ttype);	
			printf("\tYour Total Fee: %d\n",b.fee);
		}
	}
	fclose(fp);		
}

void findMov()
{   
    char op;	
	struct book b;
	int flag=0;
	int bk;
	printf("\n\tEnter Booking number: ");
	scanf("%d",&bk);		
	FILE *fp;
	fp =fopen("ticket.txt","r");
	printf("\n");
	if (fp==NULL)
 	{	
	    printf("\tFile not found!");
    }
	else
	{	
		while(fread(&b, sizeof(struct book), 1, fp))
		{			
			if (bk==b.mnum)
    		{	  	
    			flag=1;
			  	printf("\tBooking Number : %d\n",b.mnum);
				printf("\tName of Customer: %s\n",b.cname);			
				printf("\tName of Movie: %s\n", b.mname);	
				printf("\tMovie Schedule: %s\n", b.mdate);	
				printf("\tShow Timing (MMHH): %d\n", b.mtime);
				printf("\tNumber of Guests: %d\n", b.guestsnum);	
				printf("\tHall Number: %d\n", b.housenum);		
				printf("\tRow and Seat: %s\n", b.ttype);	
				printf("\tYour Total Fee: %d\n",b.fee);
				printf("\n");
				break;
			}
  		}
  		if(!flag)  		
  			printf("\n\tRecord not found!");	
	}
	fclose(fp);
	do
	{
		printf("\n\tFind another record (y/n)?");
		scanf("%s",&op);
		switch(op)
		{
			case 'y':				
				findMov();
			case 'n':				
				system("cls");
				return;
			default:
				printf("\tPlease select (y) or (n)!\n");
		}
	} while(op!='n');	   	
}	

void delMov()
{
	FILE *fp, *ft;
    int n;    
    struct book b;    
    fp = fopen("ticket.txt","r");
    ft = fopen("Temp.txt","wb+");

    printf("\n\tEnter Booking Number to delete : ");
    scanf("%d",&n);
    rewind(fp);    
    if (fp==NULL)
 	{	
	    printf("\tFile not found!");
    }   
	else	
    while (fread(&b, sizeof(struct book), 1, fp))
	{		
		if(b.mnum==n)
			continue;
		fwrite(&b, sizeof(struct book), 1, ft);
	}
	printf("\tRecord deleted\n");	
    fclose(fp);
    fclose(ft);
    remove("ticket.txt");
    rename("Temp.txt","ticket.txt");
    printf("\n\tPress any key to continue...");
	getch();//holds the screen
    system("cls");
}

void showmovie()
{
	system("cls");	
	struct movie m;
	FILE *fp;
	fp = fopen("moviedetail.txt", "r");
		
	printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
	printf("\t\t\t Movie Ticket Booking System ");
	printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
	printf("\n\tCode \tMovie Name \tRelease Date \tCost\n\n");

	while(fread(&m, sizeof(struct movie), 1, fp))
	{
		if(strlen(m.mname)>6)
			printf("\t%s\t%s\t%s\t%d\n", m.mcode, m.mname, m.reldate, m.cost);
		else
			printf("\t%s\t%s\t\t%s\t%d\n", m.mcode, m.mname, m.reldate, m.cost);
	}
	
	fclose(fp);	
}

void user()
{
	int ch;	
	system("cls");
	while(1)
	{
		printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
		printf("\t\t\t Movie Ticket Booking System ");
		printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n\tEnter >1< New User?? Register Now!!");
		printf("\n\tEnter >2< Already a User?? Login!!");
		printf("\n\tEnter >3< Quit\n");		
		printf("\n\tEnter your Choice : ");		
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				system("cls");
				registerUser();	//To register the User Account
				break;
			case 2:
				system("cls");
				loginUser();	//To login to User Account
				break;
			case 3:
				printf("\tSee you next time :)");
				printf("\n\tPress any key to continue...");
				getch();//holds the screen
				system("cls");
				return;	//End of Program				
			default :
				printf("\tPlease select a correct number (1-3)!");
		}
	}
}

void registerUser()
{
	customer cm;	
	char pas[16], cpas[16];
	FILE *fp;
	printf("\n\n  ++++++++++++++++++++++++++++++  USER REGISTRATION  ++++++++++++++++++++++++++++++  \n\n");
	printf("\n\tEnter First Name : ");	
	scanf("%s",cm.fname);
	printf("\n\tEnter Last Name : ");	
	scanf("%s",cm.lname);	
	printf("\n\tEnter DoB (DD-MM-YYYY) : ");
	scanf("%s",cm.dob);
	printf("\n\tEnter Mobile Number : ");	
	scanf("%s",cm.mob);
	printf("\n\tEnter Your City : ");	
	scanf("%s",cm.city);
	printf("\n\tEnter Username : ");	
	scanf("%s",cm.username);
	printf("\tEnter your Password(min 8 and max 16 character) : ");
	scanf("%s",pas);
	printf("\tRe-enter your Password : ");
	scanf("%s",cpas);
	while(strcmp(pas, cpas)!=0)
	{
		printf("\tPassword does not match !!\n");
		printf("\tEnter your Password (min 8 and max 16 character) : ");
		scanf("%s",pas);
		printf("\tRe-enter your Password : ");
		scanf("%s",cpas);
	};
	strcpy(cm.password, cpas);
	fp=fopen("userdetail.txt","a");
	if(fp == NULL)
	{
		printf("\tFile not found!");
	}
	else
	{
		printf("\tName : %s %s\tDOB : %s\tMOB : %s\tCity : %s\n\tUsername : %s\tPassword : %s\n",
		cm.fname, cm.lname, cm.dob, cm.mob, cm.city, cm.username, cm.password);
		//fwrite(&cm, sizeof(customer), 1, fp);
		fprintf(fp,"%s\n%s\n\n", cm.username, cm.password);
		printf("\t------------ Chaning line ------------- \n");		
		printf("\n\tRegistered sucessful!");
	}
	printf("\n");
	fclose(fp);	
}

void loginUser()
{	
	char user[20], pass[16];
	char reguser[20], regpass[16];
	customer c;
	int flag=0;
	printf("\n\n  ++++++++++++++++++++++++++++++  USER LOGIN  ++++++++++++++++++++++++++++++  \n\n");
	printf(" \n\n                  ENTER USERNAME:- ");
	scanf("%s", user);
	printf(" \n                  ENTER PASSWORD:- ");
	scanf("%s", pass);		
	FILE *fp;
	fp =fopen("userdetail.txt","r");
	if (fp==NULL)
 	{	
	    printf("\tFile not found!");
    }   
	else
	{	
		while (fscanf(fp,"%s",reguser) != EOF)
		{
			if (strcmp(user, reguser)==0)
    		{	  	
    			flag=1;
    			fscanf(fp,"%s",regpass);
    			if(strcmp(pass, regpass)==0)
			  	{
			  		printf("\n\tYou are logged in!!\n");
			  		printf("\n\tPress any key to continue...");
					getch();//holds the screen
			  		fclose(fp);
			  		system("cls");
					userBook();
					break;
				}
				else
				{
					printf("\n\tWrong Password.\n");
					printf("\n\tPress any key to Try Again...");
					getch();//holds the screen
					fclose(fp);
					system("cls");
					loginUser();
				}							  	
			}
  		}
  		if(!flag)
  		{
  			printf("\n\tUsername not found!");
  			printf("\n\tPress any key to Go Back...");
			getch();//holds the screen
			system("cls");	
		}		
	}
	
	/*FILE *fp;
	fp = fopen("userdetail.txt","r");
	if (fp==NULL)
 	{	
	    printf("\tFile not found!");
    }   
	else
	{	
		while (fread(&c, sizeof(customer), 1, fp))
		{
			printf("\tuser : %s && c.username : %s\n", user, c.username);
			if (strcmp(user, c.username)==0)
    		{	  	
    			flag=1;    			
    			if(strcmp(pass, c.password)==0)
			  	{
			  		printf("\n\tYou are logged in!!\n");
			  		printf("\n\tPress any key to continue...");
					getch();//holds the screen
			  		fclose(fp);
			  		system("cls");
					userBook();
					break;
				}
				else
				{
					printf("\n\tWrong Password.\n");
					printf("\n\tPress any key to Try Again...");
					getch();//holds the screen
					fclose(fp);
					system("cls");
					loginUser();
				}							  	
			}
  		}
  		if(!flag)
  		{
  			printf("\n\tUsername not found!");
  			//printf("\n\tPress any key to continue...");
			//getch();//holds the screen
			//system("cls");		
		}
	}	*/
}

void userBook()
{
	int ch;	
	while(1)
	{
		printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");	
		printf("\t\t\t Movie Ticket Booking System ");
		printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n\tEnter >1< Book Your Movie Ticket(s)");
		printf("\n\tEnter >2< Search Your Movie Ticket(s)");
		printf("\n\tEnter >3< Cancel Your Movie Ticket(s)");
		printf("\n\tEnter >4< Dispay All Movies");
	   	printf("\n\tEnter >5< Logout & Exit\n");
		printf("\n\tEnter your Choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				addMov(); /* Add New Movie Ticketing Records function go here*/
				break;
			case 2:
				findMov(); /* Search Movie Ticketing Records function go here */
				break;
			case 3:
				delMov(); /* Delete Movie Ticketing Records function go here */
				break;
			case 4:
				showmovie();	//Display of all movies
				printf("\n\tPress any key to Go Back...");
				getch();//holds the screen
				system("cls");
				break;
			case 5:
				printf("\tYou have been Logged out!!\n\tSee you next time :)\n");
				printf("\n\tPress any key to Exit...");
				getch();//holds the screen
				system("cls");
				return;				
			default:
				printf("\tPlease select a correct number (1-7)!");
		}
	}
}


