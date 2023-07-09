#include<iostream>
#include<string>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <regex>
#include<iomanip>

#define COST 100

using namespace std;

int login();
void admin();
void user();
void insert_details();
void old_record();
void viewAll();
void search_movie();
void book_ticket();
bool isValid(string s);

struct book
{
    char code[20];
    char name[20];
    char date[20];
    int cost;
} b;

int main()
{
    int l;

    l=login();
    if(l==1)
    {
        admin();
    }
    else if(l==0)
    {
        user();
    }
    else if(l==2)
    {
        exit(0);
    }


    return 0;
}


int login()
{
    int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    char admin[10]="user";
    char password[10]="password";
    do
    {

        printf("\n  ++++++++++++++++++++++++++++++  LOGIN FIRST  ++++++++++++++++++++++++++++++  ");
        printf(" \n\n                  ENTER USERNAME:-");
        scanf("%s", &uname);
        printf(" \n\n                  ENTER PASSWORD:-");
        while(i<10)
        {
            pword[i]=getch();
            c=pword[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        pword[i]='\0';
        //char code=pword;
        i=0;
        //scanf("%s",&pword);
        if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
        {
            printf("  \n\n\n       WELCOME \"USER\" TO OUR BOOKING SYSTEM !!!! LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch();//holds the screen
            return 0;
        }
        else if(strcmp(uname,"admin")==0 && strcmp(pword,"password")==0)
        {
            printf("  \n\n\n       WELCOME \"ADMIN\" TO OUR BOOKING SYSTEM !!!! LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch();//holds the screen
            return 1;
        }
        else
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;

            getch();//holds the screen

        }
    }
    while(a<=2);
    if (a>2)
    {
        printf("\nSorry you have entered the wrong username and password for Thrice times!!!");


        getch();

    }
    system("cls");
    return 2;

}


void admin()
{
    int ch;
    do
    {
        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        printf("\n");
        printf("\t Moive Ticket booking ");
        printf("\n");
        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

        printf("\nEnter >1< To Insert Movie");
        printf("\nEnter >2< To View All Transactions");
        printf("\nEnter >3< To Re Login");
        printf("\nEnter >0< To Exit ");

        printf("\nEnter your Choice ::");
        scanf("%d",&ch);
        system("cls");

        switch (ch)
        {
        case 1:
            insert_details();
            break;

        case 2:
            old_record();
            break;

        case 3:
            main();
            break;

        case 0:
            exit(0);
            break;

        default:
            printf("Wrong choice !!!! (Make choice between 0 to 2)");
            break;
        }
    }
    while(ch!=0);
}

void insert_details()
{
    FILE *fp;
    struct book b;
    printf("Enter movie code :- ");
    scanf("%s",b.code);
    printf("Enter  name :- ");
    scanf("%s",b.name);
    printf("Enter Release Date:- ");
    scanf("%s",b.date);
    printf("Enetr Ticket Price:- ");
    scanf("%d",&b.cost);

    fp=fopen("data.txt","a");

    if(fp == NULL)
    {
        printf("FIle not Found");
    }
    else
    {
        fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
        printf("Recorded Successfully");
    }
    printf("\n");
    fclose(fp);
    system("cls");
}


void old_record()
{
    char ch;
    FILE *fp;

    //system("clear");

    fp = fopen("oldTransection.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);

    }
    else
    {
        system("cls");
        while( ( ch = fgetc(fp) ) != EOF )
            printf("%c",ch);

    }
    fclose(fp);
}

void user()
{
    int ch;
    do
    {
        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        printf("\n");
        printf("\t Moive Ticket booking ");
        printf("\n");
        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

        printf("\nEnter >1< To View All Movie");
        //printf("\nEnter >2< To Find Movie ");
        printf("\nEnter >2< To Book Tickets");
        printf("\nEnter >3< To Re Login");
        printf("\nEnter >0< To Exit ");

        printf("\nEnter your Choice ::");
        scanf("%d",&ch);
        system("cls");

        switch (ch)
        {
        case 1:
            viewAll();
            break;

        // case 2:
        //   search_movie();
        // break;

        case 2:
            book_ticket();
            break;

        case 3:
            main();
            break;

        case 0:
            exit(0);
            break;

        default:
            printf("Wrong choice !!!! (Make choice between 0 to 3 )");
            break;
        }
    }
    while(ch!=0);

}

void viewAll()
{
    char ch;
    FILE *fp;

    fp = fopen("data.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);

    }
    else
    {
        system("cls");
        while( ( ch = fgetc(fp) ) != EOF )
            printf("%c",ch);

    }

    fclose(fp);
}


void search_movie()
{
    struct book b;
    FILE *fp;

    char ch[50];
    printf("Enter movie name :");
    scanf("%[^\n]s",ch);

    fp = fopen("data.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);

    }
    else
    {
        while(getc(fp) != EOF)
        {
            fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
            if(strcmp(b.name,ch) == 0)
            {
                //printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
                printf("\n Record Found\n");
                printf("\n\t\tCode ::%s",b.code);
                printf("\n\t\tmovie name ::%s",b.name);
                printf("\n\t\tmovie date ::%s",b.date);
                printf("\n\t\tprice of ticket ::%d",b.cost);
            }
        }

    }

    fclose(fp);
    system("cls");
}


void book_ticket()
{
    viewAll();
    struct book b;
    FILE *fp;

    FILE *ufp;

    int total_seat,total_amount,a;
    char number[11];
    char name[20],clss[5]="Club",clss1[10]="Executive",clss2[7]="Royale";
    string cls;


    char ch; //used in display all movies
    char movie_code[20]; //for searching

    // disply all moives by default for movie code
    fp = fopen("data.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);

    }
    else
    {
        system("cls");
        while( ( ch = fgetc(fp) ) != EOF )
            printf("%c",ch);

    }
    fclose(fp);

    //display ends

inpt :
    printf("\n For Book ticket Choice Movie(Enter Movie Code First Latter Of Movie)\n");
    printf("\n Enter movie code :");
    scanf("%s",movie_code);
    //system("clear");
    fp = fopen("data.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);

    }
    else
    {
        bool tr=!true;
        while(getc(fp) != EOF)
        {
            fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
            if(strcmp(b.code,movie_code) == 0)
            {
                //printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
                printf("\n Record Found\n");
                /*   printf("\n\t\tCode ::%s",b.code);
                   printf("\n\t\tMovie name ::%s",b.name);
                   printf("\n\t\tdate name ::%s",b.date);
                   printf("\n\t\tPrice of ticket::%d",b.cost); */

                cout
                        << left
                        << setw(20)
                        << "Movie Code"
                        << left
                        << setw(20)
                        << "Movie Name"
                        << left
                        << setw(20)
                        << "Date Time"
                        << left
                        << setw(10)
                        << "Price of Ticket "
                        << endl;

                cout
                        << left
                        << setw(20)
                        << b.code
                        << left
                        << setw(20)
                        << b.name
                        << left
                        << setw(20)
                        << b.date
                        << left
                        << setw(10)
                        << b.cost
                        << endl;

                tr=true;
            }
        }

        if(tr==true)
        {
            goto cnt;
        }
        else
        {
            goto inpt;
        }

    }

cnt:
    printf("\n* Fill Deatails  *");
    printf("\n your name :");
    scanf("%s",name);
no:
    printf("\n Enter mobile number :");
    cin>>number;
    if(isValid(number))
    {
        goto cont;
    }
    else
    {
        cout<<"\nReEnter your mobile number "<<endl;
        goto no;
    }
cont:
    printf("\n1:Club \n2:Executive \n3:Royale ");
    scanf("%d",&a);
    printf("\n Total number of tickets :");
    scanf("%d",&total_seat);
    switch(a)
    {
    case 1 :
        cls="Club";
        total_amount = (b.cost+(COST)) * total_seat;
        break;
    case 2:
        cls="Executive";
        total_amount = (b.cost+(COST+40)) * total_seat;
        break;
    case 3:
        cls="Royale";
        total_amount = (b.cost+(COST+80)) * total_seat;
        break;

    }


    // total_amount = b.cost * total_seat;

    printf("\n ENJOY MOVIE \n");
    /*printf("\n\t\tname : %s",name);
    cout<<"\n\t\tmobile Number : "<<number;
    printf("\n\t\tmovie name : %s",b.name);
    printf("\n\t\tTotal seats : %d",total_seat);
    printf("\n\t\tcost per ticket : %d",b.cost);
    printf("\n\t\tTotal Amount : %d",total_amount);*/

    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    cout
            << left
            << setw(20)
            << "Name"
            << left
            << setw(20)
            << "Mobile Number"
            << left
            << setw(20)
            << "Movie Name"
            << left
            << setw(20)
            << "Class of Tickets"
            << left
            << setw(20)
            << "Total Seats"
            << left
            << setw(20)
            << "Cost Per Ticket"
            << left
            << setw(20)
            << "Total Amount"
            << endl;

    cout
            << left
            << setw(20)
            << name
            << left
            << setw(20)
            << number
            << left
            << setw(20)
            << b.name
            << left
            << setw(20)
            << cls
            << left
            << setw(20)
            << total_seat
            << left
            << setw(20)
            << b.cost
            << left
            << setw(20)
            << total_amount
            << endl;

    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");

    cout<<"\n\n\n\n";


    ufp=fopen("oldTransection.txt","a");
    if(ufp == NULL)
    {
        printf("FIle not Found");
    }
    else
    {
        if(a==1)
        {
            fprintf(ufp,"%s %s %d %s %d %s %d \n",name,number,total_seat,clss,total_amount,b.name,b.cost);
            printf("\n Record insert Sucessfull to the old record file");
        }
        else if(a==2)
        {
            fprintf(ufp,"%s %s %d %s %d %s %d \n",name,number,total_seat,clss1,total_amount,b.name,b.cost);
            printf("\n Record insert Sucessfull to the old record file");
        }
        else
        {
            fprintf(ufp,"%s %s %d %s %d %s %d \n",name,number,total_seat,clss2,total_amount,b.name,b.cost);
            printf("\n Record insert Sucessfull to the old record file");
        }

    }
    printf("\n");
    fclose(ufp);
    fclose(fp);
}

bool isValid(string s)
{
    // The given argument to pattern()
    // is regular expression. With the help of
    // regular expression we can validate mobile
    // number.
    // 1) Begins with 0 or 91
    // 2) Then contains 7 or 8 or 9.
    // 3) Then contains 9 digits
    const regex pattern("(0|91)?[7-9][0-9]{9}");

// regex_match() is used to
// to find match between given number
// and regular expression
    if(regex_match(s, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}
