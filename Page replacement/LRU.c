#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{ char prs[40],fp[10],ps;
int fs,i,j,k,flg1,flg2,x=5,y,pfc=0,ru[10],min;

printf("enter the page reference string:");

printf("enter the frame size:");
scanf("%d",&fs);
for(i=0;i<fs;i++)
{
fp[i]='x';
ru[i]=0;
}

printf("PAGE REPLACEMENT TECHNIQUE::LRU algorithm\n");
printf("������������\n");
printf("F-Page fault\tH-Page Hit\n");
for(i=0;i<strlen(prs);i++,x+=2)
{
flg1=0;
ps='F';
for(j=0;j<fs;j++)
{
if(fp[j]==prs[i])
{
ps='H';
ru[j]=i;
flg1=1;
break;
} }
if(flg1==0)
{
pfc++;
flg2=0;
for(j=0;j<fs;j++)
{
if(fp[j]=='X')
{
fp[j]=prs[i];
ru[j]=i;
flg2=1;
break;
} }
if(flg2==0)
{
min=0;
for(j=1;j<fs;j++)
{
if(ru[min]>ru[j])
min=j;
}
fp[min]=prs[i];
ru[min]=i;
} }
y=5;
gotoxy(x,y);
printf("%c",prs[i]);
y++;
gotoxy(x,y);
printf("- -");
y++;
for(j=0;j<fs;y++,j++)
{
gotoxy(x,y);
printf("%c",fp[j]);
}
y++;
gotoxy(x,y);
printf("�");
y++;
gotoxy(x,y);
printf("%c",ps);
}
printf("\n\n\n\n\n\n total page faults=%d",pfc);
getch();
}
