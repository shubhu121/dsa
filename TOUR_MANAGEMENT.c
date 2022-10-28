#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int d,m,y;
int d1,m1,y1;

void destination();
void italy();
void france();
void london();
void sydney();
void newyork();
void tokyo();
void shimla();
void print_details();
void print_ticket(int [],int);
void input(int,int );
int check(int);
void flights(int );

int hotels();

int menu();

struct info
{
 int age;
 int cost;
 int days;
 char hname[30];
 char destination[15];
 char name[30];
 char gender;
 float time;
 char fname[30];
 char shift[2];
} i;


void print_details()
{
 system("cls");
 int id,no,flag=0;
 printf("\n\t travellers details :\n");
 printf(" \nenter id of the person you are searching for :  ");
 scanf("%d", &id);
  file *f;
   f=fopen("info.txt", "r");
 while (!feof(f))
 {
   fscanf(f,"%d %s %d %c %d %s %s %f %s  %d %d %d %d %d %d %s", &no, &i.name,&i.age,&i.gender,&i.cost,&i.destination,&i.fname,&i.time,&i.shift,&d,&m,&y,&d1,&m1,&y1,&i.hname);

  if(id==no)
  {
  printf("\n\n\tid : %d",no);
  printf("\n\tname : %s\t\t hotel name : %s ", i.name,i.hname);
  printf("\n\tage : \t%d\t\t checkin : %d/%d/%d ",i.age,d,m,y);
  printf("\n\tgender : %c\t \t checkout : %d/%d/%d", i.gender,d1,m1,y1);
        printf("\n\tdestination : %s",i.destination);
        printf("\n\tflight name : %s",i.fname);
        printf("\n\tdeparture time : %f %s",i.time,i.shift);
        printf("\npress enter to continue .....");
 flag=1;
  }
     if(flag==1)
     break;
           }
 fclose(f);
 if(flag==0)
 {
  printf("\nno bill exists.");
  printf("\npress enter to continue .....");

 }
}


void print_ticket(int a[],int cnt)
{
 system("cls");
 int z,no,flag;
 int guide_charges;

  file *f;
    printf("\n\n\t your ticket:");
  for(z=0;z<cnt;++z)
  {   flag=0;
  f=fopen("info.txt", "r");
 while (!feof(f))
 {
  fscanf(f,"%d %s %d %c %d %s %s %f %s  %d %d %d %d %d %d %s",&no,&i.name,&i.age,&i.gender,&i.cost,&i.destination,&i.fname,&i.time,&i.shift,&d,&m,&y,&d1,&m1,&y1,&i.hname);
   if(a[z]==no)
  {
  printf("\n\n\tid : %d",no);
  printf("\n\tname : %s\t\t hotel name : %s ", i.name,i.hname);
  printf("\n\tage : \t%d\t\t checkin : %d/%d/%d ",i.age,d,m,y);
  printf("\n\tgender : %c\t \t checkout : %d/%d/%d", i.gender,d1,m1,y1);
        printf("\n\tdestination : %s",i.destination);
        printf("\n\tflight name : %s",i.fname);
        printf("\n\tdeparture time : %f %s",i.time,i.shift);
       flag=1;
   }
     if(flag==1)
     break;
           }
  fclose(f);
  }


   printf("\n\n\t\ttotal cost : %ld",i.cost);
printf("\n\n\t\tbooking successfull");
   printf("\n\n\t\t   press enter to go to main menu .....");
     getchar();
menu();
}




int check(int id)
{
   int fi;
  file *f1;

        f1=fopen("checkid.txt","w");

fclose(f1);

 file *f;
 f=fopen("checkid.txt","r+");
   while(!feof(f))
{
 fscanf(f,"%d",&fi);
 if(fi==id)
 {
 printf("\n\t id aldready exists!) !\n\t choose another id :\n");
 return 1;
 }
}
fclose(f);
return 0;
}


void input(int cnt,int cno)
{
 int a[cnt];
 int pos=0,res;
 int days;

 switch(cno)
 {
  case 1:strcpy(i.destination,     "italy");break;
  case 2:strcpy(i.destination,     "france");break;
  case 3:strcpy(i.destination,     "london");break;
  case 4:strcpy(i.destination,    "sydney" );break;
  case 5:strcpy(i.destination,     "new_york");break;
  case 6:strcpy(i.destination,     "tokyo");break;
  case 7:strcpy(i.destination,    "shimla" );break;
 }
 int x=0,id;
 while(x<cnt)
  {
  system("cls");
   printf("\n\t\t enter %d person details",x+1);
  a:
  printf("\n\n\t     choose your travel id (1-100) : ");
 scanf("%d",&id);
 res=check(id);
 if(res==1)
 goto a;
 printf("\n\t    enter  name , age , gender (m/f)  :\n\n");
 file *f;
 f=fopen("info.txt","a+");
 printf("\t    ");
 scanf("%s", &i.name);
 printf("\t    ");
 scanf("%d",&i.age);
 printf("\t    ");
 getchar();
    i.gender=getchar();
    printf("\n\n\t\t   press enter to continue .....");
     getchar();
 getchar();
 flights(id);
 days = hotels();


//   if(determine_if_indian(i.destination))
//        guide_charges = 2000 * days;
//   else
//        ...
//
//   i.cost += guide_charges
//
//
//   if (days < 8) {
//        i.cost *= (1 - 0.2);
//        //printf("You are eligible ")
//   } else if ...


 fprintf(f,"%d %s %d %c %d %s %s %f %s ",id,i.name,i.age,i.gender,i.cost,i.destination,i.fname,i.time,i.shift);
 fprintf(f," %d %d %d %d %d %d %s\n",d,m,y,d1,m1,y1,i.hname);
      fclose(f);
      a[x]=id;
      ++x;
  }
 print_ticket(a,cnt);
}

int determine_if_indian(char *s)
{
    return !strcmp(s, "Shimla") || !strcmp(s, "Agra");
}

int hotels()
{
 int n;

  system("cls");
 printf("\n\t\t hotels :");
 printf("\n\n\t1. emirates palace\t price : 20,000 per day");
 printf("\n\n\t2. burj al arab\t       price : 19,500 per day");
 printf("\n\n\t3. town house galleria\t price : 17,000 per day");
 printf("\n\n\t4. royal malwane\t price : 20,500 per day");
 printf("\n\n\t5. amanzoe\t    price : 18,000 per day");
 printf("\n\n\t enter choice :  ");
 scanf("%d", &n);

 printf("\n\n\t enter no of days : ");
 scanf("%d",&i.days);
  switch (n)
 {
case 1: i.cost+=i.days*20000;
strcpy(i.hname,"emirates");break;
case 2: i.cost+=i.days*19500;
strcpy(i.hname,"burj_al_arab");break;
case 3: i.cost+=i.days*17000;
strcpy(i.hname,"town_house_galleria");break;
case 4: i.cost+=i.days*20500;
strcpy(i.hname,"royal_malwane");break;
case 5: i.cost+=i.days*18000;
strcpy(i.hname,"amanzoe");break;
 }
 printf("\n\t enter date of checkin : ");
 scanf("%d",&d);
 printf("\n\t enter month of checkin : ");
 scanf("%d",&m);
 printf("\n\t enter year of checkin : ");
 scanf("%d",&y);

 d1=d+i.days;
 m1=m;
 y1=y;
 if(d1>31)
 {
  d1=d1-31;
  m1+=1;
  if(m1>12)
  {
   m1=m1-12;
   y1+=1;
  }
 }
printf("\n\n\t\t   press enter to continue .....");
 getchar();
 getchar();

 return i.days;
}



void flights(int id)
 {
  int choice;
 printf("\n\n\t\t flights available : ");
 printf("\n\n    1. lufthansa:       departure : 6.00 am  price : 68,000 rs");
 printf("\n    2. jet airways:     departure : 9.00 am  price : 40,000 rs");
   printf("\n    3. qatar airways :  departure : 1.00 pm  price : 55,000 rs");
  printf("\n    4. emirates:        departure : 5.00 pm  price : 75,000 rs");
  printf("\n    5. air asia :       departure : 9.00 pm  price : 42,000 rs");
  printf("\n\n\t enter choice :  ");
  scanf("%d",&choice);
  switch(choice)
  {
case 1: i.cost+=68000;
i.time=6.00;
strcpy(i.shift,"am");
strcpy(i.fname,"lufthansa");break;
case 2: i.cost+=40000;
i.time=9.00;
strcpy(i.shift,"am");
strcpy(i.fname,"jet_airways");break;
case 3: i.cost+=55000;
i.time=1.00;
strcpy(i.shift,"pm");
strcpy(i.fname,"qatar_airways");break;
case 4: i.cost+=75000;
i.time=5.00;
strcpy(i.shift,"pm");
strcpy(i.fname,"emirates");break;
case 5: i.cost+=42000;
i.time=9.00;
strcpy(i.shift,"pm");
strcpy(i.fname,"air_asia");break;
}
   file *p;
       p=fopen("checkid.txt","a+");      fprintf(p,"%d \n",id);
        fclose(p);
        printf("\n\n\t\t   press enter to continue .....");
 getchar();
 getchar();

}


void destination()
{
 system("cls");
 int n;
 printf("\n\t destination :");
 printf("\n\n\t 1. italy");
 printf("\n\n\t 2. france");
 printf("\n\n\t 3. london");
    printf("\n\n\t 4. sydney");
 printf("\n\n\t 5. new york");
 printf("\n\n\t 6. tokyo");
 printf("\n\n\t 7. shimla");
 printf("\n\n\t enter choice :  ");
 scanf("%d", &n);
 switch (n)
 {
 case 1:italy();break;
 case 2:france();break;
 case 3:london();break;
 case 4:sydney();break;
 case 5:newyork();break;
 case 6:tokyo();break;
 case 7:shimla();break;
 }
}


void italy()
{
 int cnt;
 system("cls");
 printf("\n\t\twelcome to italy tourism  !!!\n");
printf("\n\t\t    enter no. of people ");
    scanf("%d",&cnt);
 input(cnt,1);
}

void france()
{
 int  cnt;
 system("cls");
 printf("\n\t\twelcome to france tourism  !!!\n");
printf("\n\t\t    enter no. of people ");
    scanf("%d",&cnt);
 input(cnt,2);
}

void london()
{
 int  cnt;
 system("cls");
 printf("\n\t\twelcome to london tourism  !!!\n");
printf("\n\t\t    enter no. of people ");
    scanf("%d",&cnt);
 input(cnt,3);
}

void sydney()
{
 int  cnt;
 system("cls");
 printf("\n\t\twelcome to sydney tourism  !!!\n");
printf("\n\t\t    enter no. of people ");
    scanf("%d",&cnt);
 input(cnt,4);
}

void newyork()
{
 int  cnt;
 system("cls");
 printf("\n\t\twelcome to new york tourism  !!!\n");
printf("\n\t\t    enter no. of people ");
    scanf("%d",&cnt);
 input(cnt,5);
}

void tokyo()
{
 int  cnt;
system("cls");
 printf("\n\t\twelcome to toky0 tourism  !!!\n");
printf("\n\t\t    enter no. of people ");
    scanf("%d",&cnt);
 input(cnt,6);
}

void shimla()
{
 int  cnt;
 system("cls");
 printf("\n\t\twelcome to shimla tourism  !!!\n");
printf("\n\t\t    enter no. of people ");
    scanf("%d",&cnt);
 input(cnt,7);
}


int menu()
{
 int n;
 system("cls");
 printf("\n\tmenu :");
 printf("\n\n\t1. choose destination \n\n\t2. generate bill\n\n\t3. exit\n\n\tenter choice :  ");
 scanf("\n%d", &n);
 switch (n)
 {
 case 1:destination();break;
 case 2:print_details();break;
 case 3: return 0;
}
getch();
menu();
return 0;
}


int main()
{
  system("cls");
 printf("\n\n\n\n\n\n\t\t\t   Welcome \n\n\t\t      Positron travel agency");
 printf("\n\n\t\t   press enter to continue .....");
 getchar();
 menu();
 return 0;
}
