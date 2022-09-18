#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string.h>

int curlev=0;
int mas1[10];
int mas2[10];
int mashit[10]={3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
int mashith[10]={3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
int count0;
int hith=3;
int hit=0;
char input[21];


void calc_c() //подсчет выстрелов, доступных человеку
{
hith = 0;
for (int k=0; k<10; k++)
if (mas1[k]!=0)
hith++;
}

void calc_h() //подсчет выстрелов, доступных компьютеру
{
hit = 0;
for (int k=0; k<10; k++)
if (mas2[k]!=0)
hit++;
}

void set_c() //установка пушек компьютером
{
int cntr=0;
int swap=0;
randomize();
while (cntr!=3)
 {
 for (int k=0; k<10; k++)
 mas2[k]=0;
 for (k=0; k<10; k++)
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



void set_h() //установка пушек человеком
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

void attack_c0() //глупый противник
{
int swap=0;
int ctrl=0;
int kill=0;
int status=0;
int prew=0;
randomize();
prew=mas1[swap];
for (int g=0; g<hit; g++)
 {
 status++;
 swap=random(10);
 if (mas1[swap]!=0)
 {
 mas1[swap]-=1;
 cout << "\nPlace " << swap << " hit";
 }
 }
if (prew==status && prew!=0)
kill++;
cout << "\n\nCOMPUTER: " << hit << "/" << swap << swap << swap <<"/" << ctrl << "/" << kill << endl;
}

void attack_c1() //по три раза без добивания
{
int swap=0;
int ctrl=0;
int kill=0;
int status=0;
int prew=0;
randomize();
swap=random(10);
while (mashit[swap]==0)
swap=random(10);
prew=mas1[swap];
for (int g=0; g<hit; g++)
 {
 if (mas1[swap]!=0)
 {
 status++;
 mas1[swap]-=1;
 if (mas1[swap]!=0)
 mashit[swap]-=1;
 else
 mashit[swap]=0;
 }
 }
if (prew==status && prew!=0)
kill++;
cout << "\n\nCOMPUTER: " << hit << "/" << swap << swap << swap <<"/" << ctrl << "/" << kill << endl;
}

void attack_c2() //по три раза с добиванием
{
int swap=0;
int ok=11;
int ctrl=0;
int kill=0;
int status=0;
int prew=0;
for (int s=0; s<10; s++)
 {
 if (mashit[s]<3 && mashit[s]!=0)
 ok = s;
 }
if (ok==11)
{
randomize();
swap=random(10);
while (mashit[swap]!=3)
swap=random(10);
}
else swap=ok;
//cout << "\nSWAP:" << swap << endl << "MASHIT:" << mashit[swap] <<endl << "MAS1:"<<mas1[swap] << endl;
prew=mas1[swap];
for (int g=0; g<hit; g++)
 {
 if (mas1[swap]!=0)
 {
 status++;
 mas1[swap]-=1;
 }
 if (mas1[swap]==0)
 mashit[swap]=0;
 else
 mashit[swap]-=1;
 }
if (prew==status && prew!=0)
kill++;
cout << "\n\nCOMPUTER: " << hit << "/" << swap << swap << swap <<"/" << ctrl << "/" << kill << endl;
}

void attack_c3() //умный по три раза с добиванием
{
int swap=0;
int ok=11;
int curatt;
int ctrl=0;
int status=0;
int prew=0;
int kill=0;
curatt=hit;
for (int s=0; s<10; s++)
 {
 if (mashit[s]<3 && mashit[s]!=0)
 ok = s;
 }
if (ok==11)
{
randomize();
swap=random(10);
while (mashit[swap]!=3)
swap=random(10);
}
else
{
swap=ok;
curatt=mas1[swap];
if (curatt>hit) curatt=hit;
}
//cout << "\nSWAP:" << swap << endl << "MASHIT:" << mashit[swap] <<endl << "MAS1:"<<mas1[swap] << endl;
prew=mas1[swap];
cout << "\n\nCOMPUTER: " << hit << "/";
for (int g=0; g<hit; g++)
 {
 if (curatt==0)
 {
 int may=0;
 for (int y=0; y<10; y++)
  {
  if (mashit[10]!=0)
  may++;
  }
 if (may!=0)
 {
 swap=random(10);
 while (mashit[swap]==0)
 swap=random(10);
 }
 }
 if (mas1[swap]!=0)
 {
 status++;
 ctrl++;
 mas1[swap]-=1;
 }
 if (mas1[swap]==0)
 mashit[swap]=0;
 else
 mashit[swap]-=1;
 if (curatt!=0)
 curatt--;
cout << swap;
 }
if (prew==status && prew!=0)
kill++;
cout << "/" << ctrl << "/" << kill << endl;
}


void attack_c4() //умный тактика 2-1
{
randomize();
int swap=0;
int ok=11;
int curatt;
int ctrl=0;
int status=0;
int prew=0;
int kill=0;
curatt=hit;
int may=0;
cout << "\n\nCOMPUTER: " << hit << "/";
for (int y=0; y<10; y++)
{
if (mashit[10]!=0)
may++;
}
swap=random(10);
if (may!=0)
{
while (mashit[swap]==0)
swap=random(10);
}
for (int s=0; s<10; s++)
 {
 if (mashit[s]==2 && mashit[s]!=0)
 ok = s;
 }
 if (ok!=11)
 swap=ok;
prew=mas1[swap];
for (int v=0; v<2; v++)
{
 if (mas1[swap]!=0)
 {
 status++;
 ctrl++;
 mas1[swap]-=1;
 }
if (mas1[swap]==0)
mashit[swap]=0;
else
mashit[swap]-=1;
cout << swap;
}
if (prew==status && prew!=0)
kill++;
curatt=swap;
for (y=0; y<10; y++)
{
if (mashit[10]!=0)
may++;
}
swap=random(10);
if (may!=0)
{
while (mashit[swap]==0)
{
swap=random(10);
while (swap==curatt)
swap=random(10);
}
}
ok=11;
for (s=0; s<10; s++)
 {
 if (mashit[s]==1 && mashit[s]!=0)
 ok = s;
 }
if (ok!=11)
swap=ok;
prew=mas1[swap];
status=0;
 if (mas1[swap]!=0)
 {
 status++;
 ctrl++;
 mas1[swap]-=1;
 }
if (mas1[swap]==0)
mashit[swap]=0;
else
mashit[swap]-=1;
cout << swap;
if (prew==status && prew!=0)
kill++;
cout << "/" << ctrl << "/" << kill << endl;
}



void attack_h(int i) //атака человека
{
if (mas2[i]!=0)
 {
 mas2[i]-=1;
 mashith[i]-=1;
 count0++;
 }
}

void lexem()     //выдирание лексемы с вызовом атаки
{
int temp=0;
count0 = 0;
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
cout << "\n\nEnemy hit: " << count0;
calc_h();
}

void main()  //главная
{
cout << "Choose level 0-4: ";
curlev=getch();
getchar();
getchar();
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
  switch(curlev)
  {
  case '0':
  attack_c0();
  break;
  case '1':
  attack_c1();
  break;
  case '2':
  attack_c2();
  break;
  case '3':
  attack_c3();
  break;
  case '4':
  if (hit==3)
  attack_c4();
  else attack_c3();
  break;
  default:
  cout << "\nUnresolved error\n";
  getch();
  exit(1);
  break;
  }
  calc_c();
  cout << "\nShoots avalible: " << hith << endl;
  cout << "\t";
  for (int q=1; q<10; q++)
  {
  if ((q-1)%3==0)
  cout << endl << "\t";
  if (mashith[q]==0)
  cout << "X ";
  else cout << "- ";
  }
  cout << "\n\t  ";
  if (mashith[0]==0)
  cout << "X ";
  else cout << "- ";
 }
 else if (hit==0)
 {
  cout << "\n\nYou win";
  break;
 }
 else if (hith==0)
 {
  cout << "\n\nYou lose";
  break;
 }
else
 {
 cout << "\n\nUnresolved error!";
 break;
 }
 }
getch();
}