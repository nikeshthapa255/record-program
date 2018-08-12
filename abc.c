#include<stdlib.h>
#include <stdio.h>
#include <string.h>
struct rec
{
char name[50];
char roll[50];
char add[200];
int index;
struct rec *f,*b;
};
void insert(struct rec a)
{fflush(stdin);
printf("Enter name,roll number and address");
scanf("%s",a.name);
fflush(stdin);
scanf("%s",a.roll);
fflush(stdin);
scanf("%s",a.add);
fflush(stdin);
}
int main()
{
FILE *fp;
fp=fopen("records.txt","w+");
struct rec num[1000];
num[0].f=&num[1];
num[0].b=NULL;
strcpy(num[0].name,"default");
int i=1;
while(1)
{fflush(stdin);
int ch=0;
printf("enter choice 1)insert 2)remove 3)update 4)end\n");
scanf("%d",&ch);
fflush(stdin);
if(ch==4)
break;
switch(ch)
{
case 1:
insert(num[i]);
num[i].index=i;

num[i].b=&num[i-1];
num[i].f=&num[i+1];
i++;
break;
case 2:
printf("Entries till now select index position");
int j=0;
struct rec *god;
god=&num[0];
while((*god).f!=NULL)
{
printf("%d ) %s \n",(*((*god).f)).index,(*((*god).f)).name);
god=(*god).f;
}
int ch1;
scanf("%d",&ch1);
fflush(stdin);
if(num[ch1].name!="\0")
{
if(ch1==1)
{
num[0].f=&num[2];
num[1].f=num[1].b=NULL;
}
else{
num[ch1-1].f=num[ch1].f;
num[ch1].f=num[ch1].b=NULL;
}
}
else
printf("invalid choice");
break;
}
}
struct rec *g;
g=&num[0];
while((*g).f!=NULL)
{

fwrite((*g).f,sizeof((*((*g).f))),1,fp);
g=(*g).f;
}
return 0;
}
