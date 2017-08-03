#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<dirent.h>
#include<sys/types.h>


FILE *fp,*ft,*fs;

void menu();
void pass();
void login();
void sender();
void receiver();
void ip();
void browse();
void rece();
void browser();
void hfs();
/*void gotoxy(int x, int y)
{
    COORD coord; //what does this do?
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
*/
char password[10]={"pass"};

void menu()
{
	system("cls");
	char c,ch,h;
	printf("Secured file transfer");
	Sleep(1000);
	printf("Enter the Operation to be performed:\n");
	printf("1. SEND\n");
	printf("2. RECEIVE\n");
	printf("3. EXIT\n");
	c=getch();
	switch(c)
	{
		case '1': 	sender();
					break;
		case '2': 	receiver();
					break;
		case '3': 	printf("Thank you, Asha ma'am, for your unexplainable guidance, (we do like you, of course!) so....balaalalaa balaalalaa"); 
					Sleep(5000);
					exit(0);		
		default: 	printf("\n\tInvalid choice, enter again\n");
					Sleep(1000);
					system("cls");
					menu();				
	}
}

void sender()
{
	system("cls");
	char c,h;
	char ch[20];
	printf("Please select the file you want to send:\n");
	int a=0,b;
	long d[50];
	DIR *dir;
	struct dirent *ent;
	char *file_name[50];
	if ((dir = opendir ("c:")) != NULL) 
	{
	while ((ent = readdir (dir)) != NULL) 
  	{ 
    	printf ("%d. %s\n",a+1,ent->d_name);
    	d[a]=ent->d_ino;
    	file_name[a]=ent->d_name;
    	a++;
  	}
  	closedir (dir);
	}	 	
	else 
	{
	  /* could not open directory */
  		perror ("");
  		return ;
  	}	
  	printf("Is your file present in you directory?\n");
  	printf("1. YES\n 2.NO\n");
  	h=getch();
  	switch(h)
  	{
  		case '1': 	//printf("please write down the ip address\n");
  					//printf("192.168.43.232\n");
  					printf("the file will be tranfered through http server\n");
  					Sleep(1000);
  					system ("hfs.exe");
				    //return;
					system ("pause");
					
				    //return 0;
  					fp=fopen("ip.txt","w");
  					printf("enter the ip address of the system you are using\n");
  				 	scanf("%s",&ch);
  				 	fprintf(fp,"%s",ch);
                    /*fflush(stdin);
                    fwrite(&ch,sizeof(ch),10,fp);*/
                    fclose(fp);
                    hfs();
                    break;
  		case '2':	printf("Copy the file you want to send to the Folder C:\\Users\\Prajwal\\Desktop\\OS_sindhu\n ");
  					system ("pause");
  					char a;
  					printf("Press enter once the file is placed in the directory\n");
  					scanf("%s",&a);
					if(a==13)
					{
						sender();
					}
					else
					{
						printf("Please try again later\n");
						Sleep(1000);
						menu();
					}
		  			break;
		default:	printf("\n\tInvalid choice, enter again\n");
					Sleep(1000);
					system("cls");
					sender(); 			  			
	}
	Sleep(1000);
	//browse();	
}

void receiver()
{	
 	char ch,passwd[10];
	int i=0;
	system("cls");
	//gotoxy(40,5);
   	printf("***Password Protected***");
   	//gotoxy(40,7);
   	printf("Enter Password:");

   while(ch!=13)
   {
	ch=getch();
	putch('*');
	if(ch!=13)
	{
	passwd[i]=ch;
	i++;
	}
   }
   passwd[i] = '\0';
   if(strcmp(passwd,password)==0)
   {	//gotoxy(40,8);
	printf("Password match");
	//gotoxy(40,10);
	printf("Press any key to countinue.....");
	getch();
	rece();
	}
   else
   {
	 //gotoxy(15,16);

	 printf("\aWarning!! Incorrect Password");
	 getch();
	 receiver();
   }
}

void rece()
{  
	system("cls");
	FILE *fptr;
    char filename[100];
	char c[20];
    printf("\nEnter the filename to open \n");
    scanf("%s", filename);
 
    // Open file
    fptr = fopen(filename,"r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        rece();
    }
 
    // Read contents from file
    while(fgets(c,100,fptr))
    /*c[20]=fgetc(fptr);
    while(c[20]!=EOF)*/
    {
        printf ("%s", c);
        c[20]=fgetc(fptr);
        printf("\n");
        Sleep(1000);
        //system("explorer http://192.168.43.232");
        //system("explorer http:///%s");
		browser();
    }
    fclose(fptr);
    //return;
}

void browser()
{
	system("explorer http://192.168.43.113");
	system("pause");
	printf("the received file will be present in\n");
	system("explorer C:\\Users\\Prajwal\\Downloads");
	system("pause");
	printf("receive complete");
    //return 0;
}

void hfs()
{
	system ("hfs.exe");
    system ("pause");
    //return 0;
}
/*printf("enter the number associated file to be sent\n");
   scanf("%d",&b);

       printf("SENDING FILE WITH FILE NAME %s ...",file_name[b]);
}*/

int main()
{
	menu();
}
