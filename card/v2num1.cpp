#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string.h>


int res=0; //ğåçóëüòàò áîÿ

//-----ÑÒĞÓÊÒÓĞÀ ÈÃĞÎÊÀ----------------------------------
struct player
 {
 long phone;        //òåëåôîí èãğîêà
 char name[11];     //èìÿ èãğîêà
 long exp;          //îïûò èãğîêà
 int level;         //óğîâåíü èãğîêà
 struct monsters    //êàğòû ìîíñòğîâ
  {
  char code;     //êîä ìîíñòğà
  } m0[4];
 struct magic       //ìîäèôèêàòîğû çàêëèíàíèÿ
  {
  char code;        //êîä ìàãèè
  int power;     //ìîäèôèêàòîğ ñèëû
  } mag[3];
 } p0, prot;

//--------------------------------------------------------

//----------!!!Çàäàíèå ïàğàìåòğîâ ïğîòèâíèêà!!!-----------

fprot()
{
return 0;
}

//--------------------------------------------------------


//----------ÁÎÉ ÌÎÍÑÒĞÀ-----------------------------------

mbattle(int i)
{
int result;
if (p0.m0[i].code=='E')
 {
 if (prot.m0[i].code='C')
 result = 0;
 else if (prot.m0[i].code='G')
 result = 1;
 else if (prot.m0[i].code='T')
 result = 0;
 else if (prot.m0[i].code='E')
 result = 1;
 }
else if (p0.m0[i].code=='T')
 {
 if (prot.m0[i].code='C')
 result = 1;
 else if (prot.m0[i].code='G')
 result = 0;
 else if (prot.m0[i].code='T')
 result = 1;
 else if (prot.m0[i].code='E')
 result = 0;
 }
else if (p0.m0[i].code=='G')
 {
 if (prot.m0[i].code='C')
 result = 0;
 else if (prot.m0[i].code='G')
 result = 1;
 else if (prot.m0[i].code='T')
 result = 1;
 else if (prot.m0[i].code='E')
 result = 0;
 }
else if (p0.m0[i].code=='C')
 {
 if (prot.m0[i].code='C')
 result = 1;
 else if (prot.m0[i].code='G')
 result = 0;
 else if (prot.m0[i].code='T')
 result = 0;
 else if (prot.m0[i].code='E')
 result = 1;
 }
res=+result;
return 0;
}

//--------------------------------------------------------

//-----------ÁÎÉ ÊÀĞÒ-------------------------------------

usbattle()
{
int i;
int exp0;
res=0;
for (i=0; i<=3; i++)
{
mbattle(i);
}
if (res>=2)
{
exp0=prot.exp/2;
p0.exp+=exp0;
prot.exp-=exp0;
cout << "\nYou're win\n";
}
else
{
exp0=p0.exp/4;
prot.exp+=exp0;
p0.exp-=exp0;
cout << "\nYou have been defeated\n";
}
return 0;
}

//----------------------------------------------------------


//-----------ÎÁÍÓËÅÍÈÅ ÌÎÄÈÔÈÊÀÒÎĞÀ ÌÀÃÈÈ-------------------

magic_null()
{
int i;
for (i = 0; i <= 3; i++)
{
p0.mag[i].code='0';
p0.mag[i].strength=0;
p0.mag[i].defence=0;
p0.mag[i].range=0;
p0.mag[i].speed=0;
p0.mag[i].magic=0;
prot.mag[i].code='0';
prot.mag[i].strength=0;
prot.mag[i].defence=0;
prot.mag[i].range=0;
prot.mag[i].speed=0;
prot.mag[i].magic=0;
}
return 0;
}

//----------------------------------------------------------------


//------ÎÁÍÎÂËÅÍÈÅ ÌÀÍÛ-----------------------------------

setmana()
{
p0.mana=p0.level-p0.m0[0].cost-p0.m0[1].cost-p0.m0[2].cost-p0.m0[3].cost;
return 0;
}

//--------------------------------------------------------


//--------ÏÎÄÑ×ÅÒ ÒÅÊÓÙÅÃÎ ÓĞÎÂÍß ÈÃĞÎÊÀ---------------------------

setlevel()
{
char message[200]=" ";
int curlev;
if (p0.exp>=8192000)
curlev = 20;
else if (p0.exp>=4096000)
curlev = 19;
else if (p0.exp>=2048000)
curlev = 18;
else if (p0.exp>=1024000)
curlev = 17;
else if (p0.exp>=512000)
curlev = 16;
else if (p0.exp>=256000)
curlev = 15;
else if (p0.exp>=128000)
curlev = 14;
else if (p0.exp>=64000)
curlev = 13;
else if (p0.exp>=32000)
curlev = 12;
else if (p0.exp>=16000)
curlev = 11;
else if (p0.exp>=8000)
curlev = 10;
else if (p0.exp>=4000)
curlev = 9;
else if (p0.exp>=2000)
curlev = 8;
else if (p0.exp>=1000)
curlev = 7;
else if (p0.exp>=500)
{
curlev = 6;
strcpy(message,"New spell Double and Break avalible");
}
else if (p0.exp>=250)
{
curlev = 5;
strcpy(message,"New spell Fireball and Lightning avalible");
}
else if (p0.exp>=125)
{
curlev = 4;
strcpy(message,"New spell Fireball and Lightning avalible");
}
else if (p0.exp>=50)
{
curlev = 3;
strcpy(message,"New unit Berserk & new spell Aid and Poision avalible");
}
else if (p0.exp>=10)
{
curlev = 2;
strcpy(message,"New unit Troll & new spell Grow and Weak avalible");
}
else curlev = 1;
if (p0.level!=curlev)
{
p0.level=curlev;
cout << "\nYour new level is " << curlev << endl << message;
setmana();
}
return 0;
}

//--------------------------------------------------------


//-------ÂÛÂÎÄ ÑÂÅÄÅÍÈÉ ÎÁ ÈÃĞÎÊÅ-------------------------

viewme()
{
cout << "\n\nName: " << p0.name << "\nLevel: " << p0.level << "\nMana: " << p0.mana << "\nExperience: " << p0.exp << "\nMonsters: ";
cout << p0.m0[0].code << " ";
cout << p0.m0[1].code << " ";
cout << p0.m0[2].code << " ";
cout << p0.m0[3].code << endl;
return 0;
}

//--------------------------------------------------------



//--------ÓÑÒÀÍÎÂÊÀ ÌÎÍÑÒĞÀ-------------------------------

setmonster(int i, char cod)
{
  char code;
  int cost;
  int strength;
  int defence;
  int range;
  int speed;
  int magic;
  int exp;
  int curlev;
if (cod=='G')
{
code='G';
cost=0;
strength=2;
defence=2;
range=0;
speed=3;
magic=1;
exp=1;
curlev=1;
}
else if (cod=='A')
{
code='A';
cost=0;
strength=0;
defence=1;
range=4;
speed=2;
magic=0;
exp=1;
curlev=1;
}
else if (cod=='T')
{
code='T';
cost=1;
strength=4;
defence=4;
range=0;
speed=0;
magic=0;
exp=3;
curlev=2;
}
else if (cod=='B')
{
code='B';
cost=2;
strength=5;
defence=0;
range=0;
speed=3;
magic=0;
exp=3;
curlev=3;
}
else
{
cout << "\nError requested operation. Try again.\n";
return 0;
}
if (((p0.mana-cost)>=0) && (p0.level>=curlev))
 {
 p0.m0[i].code=code;
 p0.m0[i].cost=cost;
 p0.m0[i].strength=strength;
 p0.m0[i].defence=defence;
 p0.m0[i].range=range;
 p0.m0[i].speed=speed;
 p0.m0[i].magic=magic;
 p0.m0[i].exp=exp;
 }
else if (((p0.mana-cost)<0) && (p0.level>=curlev))
 {
 cout << "\nNot enough mana.\n";
 return 0;
 }
else if (((p0.mana-cost)>=0) && (p0.level<curlev))
 {
 cout << "\nLevel too low. Not avalible.\n";
 return 0;
 }
else if (((p0.mana-cost)<0) && ((p0.level)<curlev))
{
cout << "\nLevel too low.  Not avalible. Not enough mana.\n";
return 0;
}
else if (((p0.mana-cost)<0) && ((p0.level)<curlev))
{
cout << "\nUnresolved error. Try again.\n";
return 0;
}
return 0;
}

//-------ÓÑÒÀÍÎÂÊÀ ÂÑÅÕ ÌÎÍÑÒĞÎÂ------------------------------------------------

setallmon()
{
int i;
char cod0;
for (i = 0; i<=3; i++)
{
cin >> cod0;
setmonster(i, cod0);
setmana();
}
return 0;
}

//------------------------------------------------------------------------------

//------ÓÑÒÀÍÎÂÊÀ ÇÀÊËÈÍÀÍÈß----------------------------------------------------

setmagic(int i, char cod)
{
char code;
int cost;
int strength;
int defence;
int range;
int speed;
int magic;
if (cod=='H')
 {
 code=cod;
 cost=1;
 strength=0;
 defence=0;
 range=1;
 speed=1;
 magic=0;
 }
else if (cod=='S')
 {
 code=cod;
 cost=1;
 strength=0;
 defence=0;
 range=-1;
 speed=-1;
 magic=0;
 }
else if (cod=='G')
 {
 code=cod;
 cost=2;
 strength=1;
 defence=1;
 range=0;
 speed=0;
 magic=0;
 }
else if (cod=='W')
 {
 code=cod;
 cost=2;
 strength=-1;
 defence=-1;
 range=0;
 speed=0;
 magic=0;
 }
else if (cod=='A')
 {
 code=cod;
 cost=3;
 strength=1;
 defence=1;
 range=1;
 speed=1;
 magic=0;
 }
else if (cod=='P')
 {
 code=cod;
 cost=3;
 strength=-1;
 defence=-1;
 range=-1;
 speed=-1;
 magic=0;
 }
else if (cod=='L')
 {
 code=cod;
 cost=4;
 strength=0;
 defence=0;
 range=-2;
 speed=-2;
 magic=0;
 }
else if (cod=='F')
 {
 code=cod;
 cost=4;
 strength=0;
 defence=0;
 range=-1;
 speed=-1;
 magic=0;
 }
else if (cod=='D')
 {
 cost=5;
 code=cod;
 strength+=strength;
 defence+=defence;
 range+=range;
 speed+=speed;
 }
else if (cod=='B')
 {
 code=cod;
 cost=5;
 strength-=strength;
 defence-=defence;
 range-=range;
 speed-=speed;
 magic-=magic;
 }
else
{
cout << "Error requested operation. Try again.";
return 0;
}

if (i <= 4)
{
if (((p0.mana-cost)>=0) && (p0.level>=cost))
 {
 p0.mag[i].code=code;
 p0.mag[i].strength=strength;
 p0.mag[i].defence=defence;
 p0.mag[i].range=range;
 p0.mag[i].speed=speed;
 p0.mag[i].magic=magic;
 p0.mana-=cost;
 }
else if (((p0.mana-cost)<0) && (p0.level>=cost))
 {
 cout << "\nNot enought mana.\n";
 return 0;
 }
else if (((p0.mana-cost)>=0) && (p0.level<cost))
 {
 cout << "\nLevel too low. Not avalible.\n";
 return 0;
 }
else if (((p0.mana-cost)<0) && ((p0.level)<cost))
{
cout << "\nLevel too low. Not avalible. Not enough mana.\n";
return 0;
}
else if (((p0.mana-cost)<0) && ((p0.level)<cost))
{
cout << "\nUnresolved error. Try again.\n";
return 0;
}
}
else if (i >= -4)
{
if ((p0.mana-cost)>=0 && (p0.level>=cost))
 {
 prot.mag[i].code=code;
 prot.mag[i].strength=strength;
 prot.mag[i].defence=defence;
 prot.mag[i].range=range;
 prot.mag[i].speed=speed;
 prot.mag[i].magic=magic;
 p0.mana-=cost;
 }
else if (((p0.mana-cost)<0) && (p0.level>=cost))
 {
 cout << "\nNot enought mana.\n";
 return 0;
 }
else if (((p0.mana-cost)>=0) && (p0.level<cost))
 {
 cout << "\nLevel too low. Not avalible.\n";
 return 0;
 }
else if (((p0.mana-cost)<0) && ((p0.level)<cost))
{
cout << "\nLevel too low. Not avalible. Not enough mana.\n";
return 0;
}
else if (((p0.mana-cost)<0) && ((p0.level)<cost))
{
cout << "\nUnresolved error. Try again.\n";
return 0;
}
}
else
{
return 0;
}
return 0;
}

//------------------------------------------------------------------------------


//----------ÇÀÄÀÍÈÅ ÌÀÃÈÈ ÈÃĞÎÊÎÌ-----------------------------------------------

setallmagic()
{
int j=0, i1, i2;
char cod1, cod2;
cin >> cod1 >> i1;
cin >> cod2 >> i2;
if (i1 == 4 || i1 == 3 || i1 == 2 || i1 ==1)
i1--;
else if (i1 == (-4) || i1 == (-3) || i1 == (-2) || i1 == (-1))
i2++;
else j = 1;
if (i2 == 4 || i2 == 3 || i2 == 2 || i2 ==1)
i2--;
else if (i2 == (-4) || i2 == (-3) || i2 == (-2) || i2 == (-1))
i1++;
else j = 1;
if (j == 1)
return 0;
setmagic(i1, cod1);
setmagic(i2, cod2);
return 0;
}

//------------------------------------------------------------------------------


//--------HELP------------------------------------------------------------------

help(char code[8])
{
char swp='0';
char help[8]="?";
char monst[8]="?monst";
char magic[8]="?magic";
char param[8]="?param";
char menu[8]="?menu";
char batt[8]="?batt";
char MAG[8]="?MAG";
char MON[8]="?MON";
if (strcmp(code,help)==0)
 {
 cout << "\nUse: ?monst, ?magic, ?param, ?menu, ?batt, ?MAG [magic], ?MON [monster]\n";
 }
else if (strcmp(code,monst)==0)
 {
 cout << "\nG, A, T, B\n";
 }
else if (strcmp(code,magic)==0)
 {
 cout << "\nH, S, G, W, A, P, L, F, D, B\n";
 }
else if (strcmp(code,param)==0)
 {
cout << "\nStrength - close battle attack parametr\nDefense - close battle defence parametr\nRange - distance battle attack parametr\nSpeed - distance battle defence parametr\n";
 }
else if (strcmp(code,menu)==0)
 {
 cout << "\nA - to attack, D - to defend, L - to learn, M - set monsters, V - view self, R - ranking, F - fortify (temporally switch-off from game)\n";
 }
else if (strcmp(code,batt)==0)
 {
 cout << "\nFor attacker: A [magic] [monster_num] - to attack, R - to abort battle\nFor defender: D [magic] [monster_num] - to defend, R - to flee battle\n";
 }
else if (strcmp(code,MAG)==0)
 {
 cin >> swp;
 if (swp=='H')
  {
  cout << "\nHaste: Cost=1, Range+1, Speed+1\n";
  }
 else if (swp=='S')
  {
  cout << "\nSlow: Cost=1, Range-1, Speed-1\n";
  }
 else if (swp=='G')
  {
  cout << "\nGrow: Cost=2, Strength+1, Defence+1\n";
  }
 else if (swp=='W')
  {
  cout << "\nWeak: Cost=2, Strength-1, Defence-1\n";
  }
 else if (swp=='A')
  {
  cout << "\nAid: Cost=3, Strength+1, Defence+1, Range+1, Speed+1\n";
  }
 else if (swp=='P')
  {
  cout << "\nPoision: Cost=3, Strenght-1, Defence-1, Range-1, Speed-1\n";
  }
 else if (swp=='L')
  {
  cout << "\nLightning: Cost=4, Range-2, Speed-2\n";
  }
 else if (swp=='F')
  {
  cout << "\nFireball: Cost=4, Strenght-2, Defence-2\n";
  }
 else if (swp=='D')
  {
  cout << "\nDouble: Cost=5, All parametrs *2 (USE THIS MAGIC LAST)\n";
  }
 else if (swp=='B')
  {
  cout << "\nBreak: Cost=5, All magic effects despiel\n";
  }
 else
  {
  cout << "\nSyntax error\n";
  return 0;
  }
 }
else if (strcmp(code,MON)==0)
 {
 cin >> swp;
 if (swp=='G')
  {
  cout << "\nGoblin: Lv = 1, Cost=0, Str=2, Def=2, Rng=0, Spd=3, Exp = 1, Magic immunity\n";
  return 0;
  }
  else if (swp=='A')
  {
  cout << "\nArcher: Lv = 1, Cost=0, Str=0, Def=1, Rng=4, Spd=2, Exp = 1\n";
  return 0;
  }
 else if (swp=='T')
  {
  cout << "\nTroll: Lv = 2, Cost=1, Str=4, Def=4, Rng=0, Spd=0, Exp = 3\n";
  return 0;
  }
 else if (swp=='B')
  {
  cout << "\nBerserk: Lv = 3, Cost=2, Str=5, Def=0, Rng=0, Spd=3, Exp = 3\n";
  return 0;
  }
 else
  {
  cout << "\nSyntax error\n";
  return 0;
  }
 }
else
  {
  cout << "\nSyntax error\n";
  return 0;
  }
return 0;
}

//------------------------------------------------------------------------------


//--------CÎÇÄÀÍÈÅ ÍÎÂÎÃÎ ÈÃĞÎÊÀ------------------------------------------------

create()
{
char name[11];
cout << "\nWelcome to game!\nEnter name, and 4 monsters thorough space (G (goblin) or A (ARCHER))\nExample: HERO G G A G\n";
cin >> name;
strcpy(p0.name,name);
p0.exp=0;
setlevel();
setmana();
setallmon();
viewme();
return 0;
}

test()
{
for (int i = 0; i <=3; i++)
{
cout << endl << "PROT:" << prot.m0[i].code << prot.m0[i].strength << prot.m0[i].defence << prot.m0[i].range << prot.m0[i].speed << prot.m0[i].magic;
cout << endl << "P0: "<< p0.m0[i].code << p0.m0[i].strength << p0.m0[i].defence << p0.m0[i].range << p0.m0[i].speed << p0.m0[i].magic;
}
cout << "!!!";
getch();
}

//--------ĞÅÀËÈÇÀÖÈß ÀÒÀÊÈ------------------------------------------------------

attack()
{
int i;
char last;
last = p0.m0[3].code;
char swt;
//ïîèñê èãğîêà â ÁÄ
cout << "Your enemy is " << prot.name << " with " << prot.m0[0].code << " " << prot.m0[1].code << " " << prot.m0[2].code << " " << prot.m0[3].code << "\n\"R\" to retreat, \"A\" to attack and\nChoose magic (2 times): H - haste, S - slow \nand number monster (1-4 yours and (-1)-(-4) enemy monsters)\nExample: A H 1 S -3\n";
cin >> swt;
if (swt=='A')
{
magic_null();
setallmagic();
usbattle();
cout << res;
for (i = 0; i <= 3; i++)
{
if (prot.mag[i].code!='0')
cout << "\nEnemy cast on " << i+1 << " monster " << prot.mag[i].code << endl;
}
setmana();
setlevel();
p0.m0[3].code = last;
return 0;
}
else return 0;
}

//------------------------------------------------------------------------------


//--------ÃËÀÂÍÎÅ ÌÅÍŞ----------------------------------------------------------

main()
{
fprot();
int go=0;
char buffer[8];
while (go==0)
{
cout << endl;
cin>>buffer;
switch(buffer[0])
{
case '?':
help(buffer);
break;
case 'N':
create();
break;
case 'V':
viewme();
break;
case 'M':
setallmon();
break;
case 'A':
attack();
break;
}
}
}

//------------------------------------------------------------------------------
