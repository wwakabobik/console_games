#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string.h>

int mas1[10];
int mas2[10];
int count=0;
int hith=3;
int hit=0;
char input[21];


void calc_c()
{
hith = 0;
for (int k=0; k<10; k++)
if (mas1[k]!=0)
hith++;
}

void calc_h()
{
hit = 0;
for (int k=0; k<10; k++)
if (mas2[k]!=0)
hit++;
}

void set_c()
{
int cntr=0;
int swap=0;
randomize();
while (cntr!=3)
 {
 for (int k=0; k<10; k++)
 mas2[k]=0;
 for (int k=0; k<10; k++)
  {
  swap=random(2);
  if (swap==1)
  mas2[k]=3;
  }
calc_h();
if (hit==3)
cntr=3;
 }
}



void set_h()
{
int temp=0;
int count2=0;
while (count2<3)
{
count2=0;
for (int k=0; k<10; k++)
mas1[k]=0;
cout << "Set place! Example \"1 5 6\" or\"478\"\n";
gets(input);
int j=0;
while (input[j]!='\0')
 {
 if (input[j]=='0' || input[j]=='8' || input[j]=='7' || input[j]=='6' || input[j]=='5' || input[j]=='4' || input[j]=='3' || input[j]=='2' || input[j]=='1' || input[j]=='9')
  {
  temp=input[j]-48;
  mas1[temp]=3;
  count2++;
  j++;
  }
 else j++;
 }
calc_c();
if (hith!=3)
count2=0;
}
}

void attack_c()
{
int swap=0;
randomize();
for (int g=0; g<hit; g++)
 {
 swap=random(10);
 if (mas1[swap]!=0)
 {
 mas1[swap]-=1;
 cout << "\nPlace " << swap << " hit";
 }
 }
}

void attack_h(int i)
{
if (mas2[i]!=0)
 {
 mas2[i]-=1;
 count++;
 }
}

void lexem()
{
int temp=0;
count = 0;
int count2=0;
int j=0;
while (input[j]!='\0')
 {
 if ((input[j]=='0' || input[j]=='8' || input[j]=='7' || input[j]=='6' || input[j]=='5' || input[j]=='4' || input[j]=='3' || input[j]=='2' || input[j]=='1' || input[j]=='9') && count2<hith)
  {
  temp=input[j]-48;
  attack_h(temp);
  count2++;
  j++;
  }
 else j++;
 }
cout << "\n\nEnemy hit: " << count;
calc_h();
}

void main()
{
set_c();
set_h();
calc_h();
while (input[0]!='~')
 {
 if (hit!=0 && hith!=0)
 {
  cout << "\n\nChoose target! Example: \"145\" or \"2 8 0\"\n";
  gets(input);
  lexem();
  attack_c();
  calc_c();
  cout << "\nShoots avalible: " << hith << endl;
 }
 else
 {
  cout << "\n\nYou're win";
  break;
 }
 }
getch();
}
