#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{ char prs[40],fp[10],ps;
int fs,i,j,k=0,flg1,flg2,x=5,y,pfc=0;
clrscr();
printf("\n enter page reference string:");
gets(prs);
printf("\n enter the frame size:");
scanf("%d",&fs);
for(i=0;i<fs;i++)
fp[i]='x';
clrscr();
printf("\n page replacement technique :: FIFO algorithm:");
printf("\n ���������������");
printf("\n F-Page Fault \t H- Page Hit \n");
for(i=0;i<strlen(prs);i++,x+=2)
{
flg1=0;
ps='F';
for(j=0;j<fs;j++)
if(fp[j]==prs[i]){
ps='H';
flg1=1;
break;
}
if(flg1==0)
{
flg2=0;
for(j=0;j<fs;j++)
if(fp[j]=='x')
{
fp[j]=prs[i];
pfc++;
flg2=1;
break;
}
if(flg2==0)
{
pfc++;
fp[k]=prs[i];
k++;
if(k==fs)
k=0; } }
y=5;
gotoxy(x,y);
printf("%c",prs[i]);
y++;
gotoxy(x,y);
printf("�");
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
printf("\n \n\n\n\n Total page Faults=%d",pfc);
getch();
}
