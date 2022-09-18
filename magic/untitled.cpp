#ifdef __BORLANDC__
  #pragma argsused
#endif

#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>

struct data {
  unsigned char name[1024];
  int score;
} score0;

struct player
{
  unsigned char plname[1024];
  int load;
  // сила
  int statmag;
  int maxpower;
  int power;
  // здоровье
  int maxhealth;
  int health;
  // деньги
  int money;
  // огонь
  int maxfire;
  int fire;
  // вода
  int maxwater;
  int water;
  // воздух
  int maxair;
  int air;
  //земля
  int maxground;
  int ground;
  // дух
  int maxspirit;
  int spirit;
  // удача
  int maxluck;
  int luck;
  // сила
  int maxstrength;
  int strength;
  // опыт
  int exp;
  // уровень
  int level;
  // убито
  int kill;
} iliya;

struct monster {
  char name[1024];
  int statmag;
  int nametd;
  int maxpower;
  int power;
  int maxhealth;
  int health;
  int damage;
  int defence;
  int fire;
  int water;
  int air;
  int ground;
  int spirit;
  int luck;
  int exp;
} firstmon[1024];
int monnum;

int gamenew()
{
  char buffer;
  cout << "\n\nTo create character enter you name: "; cin >> iliya.plname;
  cout << "\nEnter character type: (M)age, (W)arlock, (P)aladin";
  buffer=getch();
  if (buffer=='m')
  buffer='M';
  if (buffer=='p')
  buffer='P';
  if (buffer=='w')
  buffer='W';
  switch(buffer)
  {
    case 'M':
    iliya.load=0;
    iliya.kill=0;
    iliya.level=0;
    iliya.exp=0;
    iliya.maxpower = 100;
    iliya.power = 100;
    iliya.maxhealth = 25;
    iliya.health = 25;
    iliya.maxfire = 3;
    iliya.fire = 3;
    iliya.maxwater = 3;
    iliya.water = 3;
    iliya.maxair = 3;
    iliya.air = 3;
    iliya.maxground = 3;
    iliya.ground = 3;
    iliya.maxspirit = 2;
    iliya.spirit = 2;
    iliya.maxluck = 2;
    iliya.luck = 2;
    iliya.maxstrength = 1;
    iliya.strength = 1;
    iliya.money = 100;
    cout << "\nMage " << iliya.plname << " was created succesfully";
    /*
  Test for high levels
  iliya.kill=100;
  iliya.level=10;
  iliya.exp=2000;
  iliya.maxpower = 200;
  iliya.power = 200;
  iliya.maxhealth = 70;
  iliya.health = 70;
  iliya.maxfire = 5;
  iliya.fire = 5;
  iliya.maxwater = 5;
  iliya.water = 5;
  iliya.maxair = 5;
  iliya.air = 5;
  iliya.maxground = 5;
  iliya.ground = 5;
  iliya.maxspirit = 5;
  iliya.spirit = 5;
  iliya.maxluck = 5;
  iliya.luck = 5;
  iliya.maxstrength = 5;
  iliya.strength = 5;
  iliya.money = 100; */
    break;
    case 'W':
    iliya.load=0;
    iliya.maxpower = 75;
    iliya.power = 100;
    iliya.maxhealth = 25;
    iliya.health = 25;
    iliya.maxfire = 3;
    iliya.fire = 3;
    iliya.maxwater = 3;
    iliya.water = 3;
    iliya.maxair = 3;
    iliya.air = 3;
    iliya.maxground = 3;
    iliya.ground = 3;
    iliya.maxspirit = 3;
    iliya.spirit = 3;
    iliya.maxluck = 2;
    iliya.luck = 2;
    iliya.maxstrength = 1;
    iliya.strength = 1;
    iliya.money = 100;
    cout << "\nWarlock " << iliya.plname << " was created succesfully";
    break;
    case 'P':
    iliya.load=0;
    iliya.maxpower = 150;
    iliya.power = 150;
    iliya.maxhealth = 30;
    iliya.health = 30;
    iliya.maxfire = 2;
    iliya.fire = 2;
    iliya.maxwater = 2;
    iliya.water = 2;
    iliya.maxair = 2;
    iliya.air = 2;
    iliya.maxground = 2;
    iliya.ground = 2;
    iliya.maxspirit = 2;
    iliya.spirit = 2;
    iliya.maxluck = 2;
    iliya.luck = 2;
    iliya.maxstrength = 2;
    iliya.strength = 2;
    iliya.money = 100;
    cout << "\nPaladin " << iliya.plname << " was created succesfully";
    break;
    default:
    cout << "\nError creation character. Try again later.\n";
    break;
  }
  return 0;
}

monsteratt(int monsterdo,int montype, int magictype)
{
  randomize();
  int hit=0;
  int todo0;
if (firstmon[montype].nametd<11)
{
if (monsterdo == 0 && firstmon[montype].health>0)
{
// блок логики монстра
todo0 = random(firstmon[montype].luck+1);
if (todo0!=0 && firstmon[montype].power>10)
{
if (firstmon[montype].power>10)
{
hit=random(firstmon[montype].damage+1);
iliya.health-=hit;
iliya.power-=5;
firstmon[montype].power-=10;
cout << "\nDamage taken: " << hit << endl;
}
}
else firstmon[montype].power+=10;
}
else if (monsterdo == 1 && firstmon[montype].health>0)
{
firstmon[montype].power+=10;
}
}
else
{
  int iamdo;
  iamdo = random(5)+1;
  if (firstmon[montype].nametd==11 || firstmon[montype].nametd==17 || (firstmon[montype].nametd>23 && iamdo==3))
  {
    int magic=0;
    if (iliya.statmag!=21)
    magic=random(2);
    if (magic==0 && monsterdo==0)
    {
      hit=random(firstmon[montype].damage+1);
      iliya.health-=hit;
      iliya.power-=5;
    }
    else
    {
      if (magictype==52 || iliya.statmag==32)
      cout << "\nWater shield protect you\n";
      else {
      hit=random(firstmon[montype].damage*2+1);
      if (iliya.statmag!=35)
      iliya.health-=hit;
      else firstmon[montype].health-=hit;
      iliya.power-=5;
      cout << "\nEnemy use water magic!\n";
      }
    }
  }
  else if (firstmon[montype].nametd==12 || firstmon[montype].nametd==18 || (firstmon[montype].nametd>23 && iamdo==2))
  {
    int magic=0;
    if (iliya.statmag!=21)
    magic=random(2);
    if (magic==0 && monsterdo==0)
    {
      hit=random(firstmon[montype].damage+1);
      iliya.health-=hit;
      iliya.power-=5;
    }
    else
    {
      if (magictype==54 || iliya.statmag==34)
      cout << "\nGround shield protect you\n";
      else {
      hit=random(firstmon[montype].damage*2+1);
      if (iliya.statmag!=35)
      iliya.health-=hit;
      else firstmon[montype].health-=hit;
      iliya.power-=5;
      cout << "\nEnemy use ground magic!\n";
      }
    }
  }
  else if (firstmon[montype].nametd==13 || firstmon[montype].nametd==16 || (firstmon[montype].nametd>23 && iamdo==1))
  {
    int magic=0;
    if (iliya.statmag!=21)
    magic=random(2);
    if (magic==0 && monsterdo==0)
    {
      hit=random(firstmon[montype].damage+1);
      iliya.health-=hit;
      iliya.power-=5;
    }
    else
    {
      if (magictype==51 || iliya.statmag==31)
      cout << "\nFire shield protect you\n";
      else
      {
      hit=random(firstmon[montype].damage*2+1);
      if (iliya.statmag!=35)
      iliya.health-=hit;
      else firstmon[montype].health-=hit;
      iliya.power-=5;
      cout << "\nEnemy use fire magic!\n";
      }
    }
  }
  else if (firstmon[montype].nametd==14 || firstmon[montype].nametd==19 || (firstmon[montype].nametd>23 && iamdo==3))
  {
    int magic=0;
    if (iliya.statmag!=21)
    magic=random(2);
    if (magic==0 && monsterdo==0)
    {
      hit=random(firstmon[montype].damage+1);
      iliya.health-=hit;
      iliya.power-=5;
    }
    else
    {
      if (magictype==53 || iliya.statmag==33)
      cout << "\nAir shield protect you\n";
      else {
      hit=random(firstmon[montype].damage*2+1);
      if (iliya.statmag!=35)
      iliya.health-=hit;
      else firstmon[montype].health-=hit;
      iliya.power-=5;
      cout << "\nEnemy use air magic!\n";
      }

    }
  }
  else if (firstmon[montype].nametd==15 || firstmon[montype].nametd==20 || (firstmon[montype].nametd>23 && iamdo==5))
  {
    int magic=0;
    if (iliya.statmag!=21)
    magic=random(2);
    if (magic==0 && monsterdo==0)
    {
      hit=random(firstmon[montype].damage+1);
      iliya.health-=hit;
      iliya.power-=5;
    }
    else
    {
      hit=random(firstmon[montype].damage*3+1);
      if (iliya.statmag!=35)
      iliya.health-=hit;
      else firstmon[montype].health-=hit;
      iliya.power-=5;
      cout << "\nEnemy use deadly claw!\n";
//      monsteratt(monsterdo,montype,magictype);
    }
  }

}
if (iliya.statmag==40)
firstmon[montype].health-=hit/2;
return 0;
}

int water3(int m1, int m2,int montype)
{
  int magictype=0,hit=0;
  randomize();
  // Ничего
  if (m1 == m2 && m1!=0 && m2!=0)
  {
  cout << "\nNothing happens\n";
  return 0;
  }
  else if ((m1 == 1 && m2 == 2) || (m2 == 1 && m1 == 2) || (m1 == 3 && m2 == 4) || (m2 == 3 && m1 == 4))
  {
  cout << "\nEffect was unknown\n";
  iliya.fire-=random(3)-1;
  iliya.water-=random(3)-1;
  iliya.air-=random(3)-1;
  iliya.ground-=random(3)-1;
  iliya.spirit-=random(3)-1;
  iliya.power-=random(16);
  magictype = random(5);
  if (magictype == 4)
  iliya.health-= 5;
  else if (magictype == 3)
  iliya.health-= 10;
  else if (magictype == 2)
  iliya.health+= 5;
  else if (magictype == 1)
  magictype = 14;
  else
  magictype = 0;
  }
  // - - - Огонь - - -
  else if (m1 == 1 && m2 == 3 && iliya.power>=25)
  {
    iliya.water--;
    iliya.fire--;
    iliya.air--;
    iliya.power-=25;
    cout << "\nYou cast ease\n";
    iliya.power+=50;
    magictype = 2130;
  }
  else if (m1 == 1 && m2 == 4 && iliya.power>=30)
  {
    iliya.water--;
    iliya.fire--;
    iliya.ground--;
    iliya.power-=30;
    iliya.health=30;
    iliya.fire=1;
    iliya.water=1;
    iliya.air=1;
    iliya.ground=1;
    iliya.spirit=1;
    cout << "\nYou cast ressurection\n";
    magictype = 2140;
  }
  else if (m1 == 1 && m2 == 5 && iliya.power>=100)
  {
    iliya.fire=0;
    iliya.water=iliya.maxwater;
    iliya.air=iliya.maxair;
    iliya.ground=iliya.maxground;
    iliya.spirit=iliya.maxspirit;
    iliya.power-=100;
    cout << "\nYou cast sacrifice\n";
    magictype = 2150;
  }
  // - - - Вода - - -
  else if (m1 == 2 && m2 == 3 && iliya.power>=30)
  {
    iliya.water--;
    iliya.water--;
    iliya.air--;
    if (iliya.health<=iliya.maxhealth+20)
    iliya.health+=20;
    else iliya.health=iliya.maxhealth;
    iliya.power-=30;
    cout << "\nYou cast cure\n";
    magictype = 2230;
  }
  else if (m1 == 2 && m2 == 4 && iliya.power>=25)
  {
    iliya.water--;
    iliya.water--;
    iliya.ground--;
    iliya.power-=25;
    cout << "\nYou cast vampirism\n";
    int hits;
    hits=random(6+iliya.level);
    firstmon[montype].health-=hits;
    iliya.health+=hits;
    magictype = 2240;
  }
  else if (m1 == 2 && m2 == 5 && iliya.power>=100)
  {
    iliya.water=0;
    iliya.fire=iliya.maxfire;
    iliya.air=iliya.maxair;
    iliya.ground=iliya.maxground;
    iliya.spirit=iliya.maxspirit;
    iliya.power-=100;
    cout << "\nYou cast sacrifice\n";
    magictype = 2250;
  }
  // - - - Воздух - - -
  else if (m1 == 3 && m2 == 1  && iliya.power>=35)
  {
    iliya.water--;
    iliya.fire--;
    iliya.air--;
    iliya.power-=35;
    cout << "\nYou cast curse\n";
    if (firstmon[montype].luck-2>=0);
    firstmon[montype].luck-=2;
    magictype = 2310;
  }
  else if (m1 == 3 && m2 == 2 && iliya.power>=25)
  {
    iliya.water--;
    iliya.water--;
    iliya.air--;
    iliya.power-=25;
    iliya.luck+=2;
    cout << "\nYou cast bless\n";
    magictype = 1320;
  }
  else if (m1 == 3 && m2 == 5 && iliya.power>=100)
  {
    iliya.air=0;
    iliya.fire=iliya.maxfire;
    iliya.water=iliya.maxwater;
    iliya.ground=iliya.maxground;
    iliya.spirit=iliya.maxspirit;
    iliya.power-=100;
    cout << "\nYou cast sacrifice\n";
    magictype = 2350;
  }
  // - - - Земля - - -
  else if (m1 == 4 && m2 == 1 && iliya.power>=35 && firstmon[montype].nametd<21)
  {
    iliya.water--;
    iliya.fire--;
    iliya.ground--;
    iliya.power-=35;
    iliya.statmag=21;
    cout << "\nYou cast silence\n";
    magictype = 2430;
  }
  else if (m1 == 4 && m2 == 2 && iliya.power>=50)
  {
    iliya.water--;
    iliya.water--;
    iliya.ground--;
    iliya.power-=50;
    iliya.statmag=22;
    cout << "\nYou cast double\n";
    magictype = 2420;
  }
  else if (m1 == 4 && m2 == 5 && iliya.power>=50)
  {
    iliya.ground=0;
    iliya.fire=iliya.maxfire;
    iliya.water=iliya.maxwater;
    iliya.air=iliya.maxair;
    iliya.spirit=iliya.maxspirit;
    iliya.power-=100;
    cout << "\nYou cast sacrifice\n";
    magictype = 2450;
  }
  // - - - Дух - - -
  else if (m1 == 5 && m2 == 1 && iliya.power>=100)
  {
    iliya.water--;
    iliya.fire--;
    iliya.spirit--;
    iliya.power-=100;
    iliya.fire=iliya.maxfire*2;
    cout << "\nYou cast fire power\n";
    magictype = 2510;
  }
  else if (m1 == 5 && m2 == 2  && iliya.power>=100)
  {
    iliya.water--;
    iliya.water--;
    iliya.spirit--;
    iliya.power-=100;
    iliya.water=iliya.maxwater*2;
    cout << "\nYou cast water power\n";
    magictype = 2520;
  }
  else if (m1 == 5 && m2 == 3  && iliya.power>=100)
  {
    iliya.water--;
    iliya.air--;
    iliya.spirit--;
    iliya.power-=100;
    iliya.air=iliya.maxair*2;
    cout << "\nYou cast air power\n";
    magictype = 2530;
  }
  else if (m1 == 5 && m2 == 4  && iliya.power>=100)
  {
    iliya.water--;
    iliya.ground--;
    iliya.spirit--;
    iliya.power-=100;
    iliya.ground=iliya.maxground*2;
    cout << "\nYou cast ground power\n";
    magictype = 2540;
  }
  else if (m1 == 0 && m2 == 1 && iliya.fire<=iliya.maxfire)
  {
    iliya.fire++;
  }
  else if (m1 == 0 && m2 == 2 && iliya.water<=iliya.maxwater)
  {
    iliya.water++;
  }
  else if (m1 == 0 && m2 == 3 && iliya.air<=iliya.maxair)
  {
    iliya.air++;
  }
  else if (m1 == 0 && m2 == 4 && iliya.ground<=iliya.maxground)
  {
    iliya.ground++;
  }
  else if (m1 == 0 && m2 == 5 && iliya.spirit<=iliya.maxspirit)
  {
    iliya.spirit++;
  }
  else if (m1 ==0 && m2 == 0 && iliya.power+10<=iliya.maxpower)
  iliya.power+=10;
  if (iliya.statmag==22)
  {
  firstmon[montype].health-=hit;
  hit*=2;
  }
  if (hit!=0)
  firstmon[montype].power-=5;
  cout << "\nEnemy hit: " << hit;
  return magictype;
return 0;
}

int air3(int m1, int m2,int montype)
{
  int magictype=0,hit=0;
  randomize();
  // Ничего
  if (m1 == m2 && m1!=0 && m2!=0)
  {
  cout << "\nNothing happens\n";
  return 0;
  }
  else if ((m1 == 1 && m2 == 2) || (m2 == 1 && m1 == 2) || (m1 == 3 && m2 == 4) || (m2 == 3 && m1 == 4))
  {
  cout << "\nEffect was unknown\n";
  iliya.fire-=random(3)-1;
  iliya.water-=random(3)-1;
  iliya.air-=random(3)-1;
  iliya.ground-=random(3)-1;
  iliya.spirit-=random(3)-1;
  iliya.power-=random(16);
  magictype = random(5);
  if (magictype == 4)
  iliya.health-= 5;
  else if (magictype == 3)
  iliya.health-= 10;
  else if (magictype == 2)
  iliya.health+= 5;
  else if (magictype == 1)
  magictype = 14;
  else
  magictype = 0;
  }
  // - - - Огонь - - -
  else if (m1 == 1 && m2 == 3 && iliya.power>=50)
  {
    iliya.air--;
    iliya.fire--;
    iliya.air--;
    iliya.power-=50;
    iliya.luck=iliya.luck*2;
    cout << "\nYou cast haste\n";
    magictype = 3130;
  }
  else if (m1 == 1 && m2 == 4 && iliya.power>=50)
  {
    iliya.air--;
    iliya.fire--;
    iliya.ground--;
    iliya.power-=50;
    iliya.strength=iliya.strength*2;
    cout << "\nYou cast giant\n";
    magictype = 3140;
  }
  else if (m1 == 1 && m2 == 5 && iliya.power>=100)
  {
    iliya.air--;
    iliya.fire=0;
    iliya.spirit--;
    iliya.power-=100;
    iliya.statmag=31;
    cout << "\nYou cast fire shield\n";
    magictype = 3150;
  }
  // - - - Вода - - -
  else if (m1 == 2 && m2 == 3 && iliya.power>=50)
  {
    iliya.air--;
    iliya.water--;
    iliya.air--;
    iliya.power-=50;
    if (firstmon[montype].nametd!=30)
    firstmon[montype].defence=firstmon[montype].defence/2;
    cout << "\nYou cast weakness\n";
    magictype = 3230;
  }
  else if (m1 == 2 && m2 == 4 && iliya.power>=150)
  {
    iliya.air--;
    iliya.water--;
    iliya.ground--;
    iliya.power-=150;
    iliya.statmag=35;
    cout << "\nYou cast shift\n";
    magictype = 3240;
  }
  else if (m1 == 2 && m2 == 5 && iliya.power>=100)
  {
    iliya.water=0;
    iliya.air--;
    iliya.spirit--;
    iliya.power-=100;
    iliya.statmag=32;
    cout << "\nYou cast water shield\n";
    magictype = 3250;
  }
  // - - - Воздух - - -
  else if (m1 == 3 && m2 == 1  && iliya.power>=35 && firstmon[montype].nametd<26)
  {
    iliya.air--;
    iliya.fire--;
    iliya.air--;
    iliya.power-=150;
    cout << "\nYou cast reset\n";
    int bufd;
    bufd=iliya.health;
    iliya.health=firstmon[montype].health;
    firstmon[montype].health=bufd;

    magictype = 3310;
  }
  else if (m1 == 3 && m2 == 2 && iliya.power>=25)
  {
    iliya.air--;
    iliya.water--;
    iliya.air--;
    iliya.power-=25;
    int bufd;
    bufd=iliya.luck;
    iliya.luck=firstmon[montype].luck;
    firstmon[montype].luck=bufd;
    cout << "\nYou cast trick\n";
    magictype = 3320;
  }
  else if (m1 == 3 && m2 == 5 && iliya.power>=100)
  {
    iliya.air=0;
    iliya.spirit--;
    iliya.power-=100;
    iliya.statmag=33;
    cout << "\nYou cast air shield\n";
    magictype = 3350;
  }
  // - - - Земля - - -
  else if (m1 == 4 && m2 == 1 && iliya.power>=50 && firstmon[montype].nametd!=30)
  {
    iliya.air--;
    iliya.fire--;
    iliya.ground--;
    iliya.power-=50;
    if (firstmon[montype].damage/2>=5)
    firstmon[montype].damage/=2;
    cout << "\nYou cast blink\n";
    magictype = 3430;
  }
  else if (m1 == 4 && m2 == 2 && iliya.power>=50)
  {
    iliya.water=0;
    iliya.air=0;
    iliya.ground=0;
    iliya.fire=0;
    iliya.spirit=0;
    iliya.health=iliya.maxhealth;
    iliya.power=iliya.maxpower;
    firstmon[montype].power=-10;
    cout << "\nYou cast idiot's magic\n";
    magictype = 3420;
  }
  else if (m1 == 4 && m2 == 5 && iliya.power>=100)
  {
    iliya.ground=0;
    iliya.air--;
    iliya.spirit--;
    iliya.power-=100;
    iliya.statmag=34;
    cout << "\nYou cast ground shield\n";
    magictype = 3450;
  }
  // - - - Дух - - -
  else if (m1 == 5 && m2 == 1 && iliya.power>=50)
  {
    iliya.air--;
    iliya.fire+=3;
    iliya.spirit--;
    iliya.power-=50;
    cout << "\nYou cast knowledge of fire\n";
    magictype = 3510;
  }
  else if (m1 == 5 && m2 == 2  && iliya.power>=50)
  {
    iliya.water+=3;
    iliya.air--;
    iliya.spirit--;
    iliya.power-=50;
    cout << "\nYou cast knowledge of water\n";
    magictype = 3520;
  }
  else if (m1 == 5 && m2 == 3  && iliya.power>=50)
  {
    iliya.air+=3;
    iliya.spirit--;
    iliya.power-=50;
    cout << "\nYou cast knowledge of air\n";
    magictype = 3530;
  }
  else if (m1 == 5 && m2 == 4  && iliya.power>=50)
  {
    iliya.air--;
    iliya.ground+=3;
    iliya.spirit--;
    iliya.power-=100;
    cout << "\nYou cast knowledge of ground\n";
    magictype = 3540;
  }
  else if (m1 == 0 && m2 == 1 && iliya.fire<iliya.maxfire)
  {
    iliya.fire++;
  }
  else if (m1 == 0 && m2 == 2 && iliya.water<iliya.maxwater)
  {
    iliya.water++;
  }
  else if (m1 == 0 && m2 == 3 && iliya.air<iliya.maxair)
  {
    iliya.air++;
  }
  else if (m1 == 0 && m2 == 4 && iliya.ground<iliya.maxground)
  {
    iliya.ground++;
  }
  else if (m1 == 0 && m2 == 5 && iliya.spirit<iliya.maxspirit)
  {
    iliya.spirit++;
  }
  else if (m1 ==0 && m2 == 0 && iliya.power+10<=iliya.maxpower)
  iliya.power+=10;
  if (iliya.statmag==22)
{
firstmon[montype].health-=hit;
hit*=2;
}
if (hit!=0)
firstmon[montype].power-=5;
cout << "\nEnemy hit: " << hit;
  return magictype;
return 0;
}


int spirit3(int m1, int m2,int montype)
{
  int magictype=0;
  int hit=0;
  randomize();
  // Ничего
  if (m1!=0)
  {
  if (((m1==1 && m2==2) || (m1==2 && m2==1)) && iliya.power>=100)
  {
    iliya.spirit--;
    iliya.fire--;
    iliya.water--;
    iliya.power-=100;
    hit=random(iliya.level+50);
    cout << "\nYou cast anger of elements\n";
    firstmon[montype].health-=hit;
    magictype=666;
  }
  else if (((m1==4 && m2==3) || (m1==3 && m2==4)) && iliya.power>=100)
  {
    iliya.spirit--;
    iliya.air--;
    iliya.ground--;
    iliya.power-=100;
    hit=random(iliya.level+60);
    cout << "\nYou cast anger of elements\n";
    firstmon[montype].health-=hit;
  }
  else if (m1==1 && m2==1 && iliya.power>=15)
  {
  iliya.fire-=2;
  iliya.spirit--;
  if (firstmon[montype].fire<1)
  hit=random(iliya.level*random(2)+10*random(4));
  iliya.power-=15;
  cout << "\nEffect was unknown\n";
  }
  else if (m1==2 && m2==2 && iliya.power>=15)
  {
  iliya.water-=2;
  iliya.spirit--;
  if (firstmon[montype].water<1)
  hit=random(iliya.level*random(2)+10*random(4));
  iliya.power-=15;
  cout << "\nEffect was unknown\n";
  }
  else if (m1==3 && m2==3 && iliya.power>=15)
  {
  iliya.air-=2;
  iliya.spirit--;
  if (firstmon[montype].air<1)
  hit=random(iliya.level*random(2)+10*random(4));
  iliya.power-=15;
  cout << "\nEffect was unknown\n";
  }
  else if (m1==4 && m2==4 && iliya.power>=15)
  {
  iliya.ground-=2;
  iliya.spirit--;
  if (firstmon[montype].ground<1)
  hit=random(iliya.level*random(2)+10*random(4));
  iliya.power-=15;
  cout << "\nEffect was unknown\n";
  }
  else if (m1==5 && m2==5 && iliya.power>=250)
  {
  iliya.spirit-=3;
  int ok,selfdeath;
  ok=random(2);
  selfdeath=random(iliya.luck);
  iliya.power-=250;
  if (selfdeath!=0)
  {
    if (ok!=0)
    {
      cout << "\nYou cast finger of death\n";
      if (firstmon[montype].nametd<26 && firstmon[montype].nametd!=16)
      firstmon[montype].health=-1000;
      hit=999;
      //cout << "\nEnemy hit: 999\n";
    }
    else cout << "\nNothing happens\n";
  }
  else {
    cout << "\nHightest magic not a toy\n";
    iliya.health=-1000;
  }
  if (m1!=5 && m2!=5)
  cout << "\nEffect was unknown\n";
  }
  else {
  iliya.health=-1000;
  cout << "\nHightest magic not a toy.\n";
  }
  }
  else {
  if (m1 == 0 && m2 == 1 && iliya.fire<iliya.maxfire)
  {
    iliya.fire++;
  }
  else if (m1 == 0 && m2 == 2 && iliya.water<iliya.maxwater)
  {
    iliya.water++;
  }
  else if (m1 == 0 && m2 == 3 && iliya.air<iliya.maxair)
  {
    iliya.air++;
  }
  else if (m1 == 0 && m2 == 4 && iliya.ground<iliya.maxground)
  {
    iliya.ground++;
  }
  else if (m1 == 0 && m2 == 5 && iliya.spirit<iliya.maxspirit)
  {
    iliya.spirit++;
  }
  else if (m1 ==0 && m2 == 0 && iliya.power+10<=iliya.maxpower)
  iliya.power+=10;
  }
  if (iliya.statmag==22)
{
firstmon[montype].health-=hit;
hit*=2;
}
if (hit!=0)
firstmon[montype].power-=5;
cout << "\nEnemy hit: " << hit;
  return magictype;
return 0;
}

int ground3(int m1, int m2,int montype)
{
  int magictype=0,hit=0;
  randomize();
  // Ничего
  if (m1 == m2 && m1!=0 && m2!=0)
  {
  cout << "\nNothing happens\n";
  return 0;
  }
  else if ((m1 == 1 && m2 == 2) || (m2 == 1 && m1 == 2) || (m1 == 3 && m2 == 4) || (m2 == 3 && m1 == 4))
  {
  cout << "\nEffect was unknown\n";
  iliya.fire-=random(3)-1;
  iliya.water-=random(3)-1;
  iliya.air-=random(3)-1;
  iliya.ground-=random(3)-1;
  iliya.spirit-=random(3)-1;
  iliya.power-=random(16);
  magictype = random(5);
  if (magictype == 4)
  iliya.health-= 5;
  else if (magictype == 3)
  iliya.health-= 10;
  else if (magictype == 2)
  iliya.health+= 5;
  else if (magictype == 1)
  magictype = 14;
  else
  magictype = 0;
  }
  // - - - Огонь - - -
  else if (((m2 == 1 && m1 == 3) || (m1 == 1 && m2 == 3)) && iliya.power>=50)
  {
    iliya.ground--;
    iliya.fire--;
    iliya.air--;
    iliya.power-=50;
    if (firstmon[montype].damage/2>=5)
    firstmon[montype].damage-=5;
    cout << "\nYou cast shield\n";
    magictype = 4130;
  }
  else if (((m2 == 1 && m1 == 4) || (m1 == 1 && m2 == 4)) && iliya.power>=100)
  {
    iliya.ground--;
    iliya.fire--;
    iliya.ground--;
    iliya.power-=100;
    iliya.statmag=31;
    cout << "\nYou cast fire immunity\n";
    magictype = 4140;
  }
  else if (((m1 == 1 && m2 == 5) || (m2 == 1 && m1 == 5)) && iliya.power>=50)
  {
    iliya.ground--;
    iliya.fire--;
    iliya.spirit--;
    iliya.power-=50;
    firstmon[montype].power=0;
    cout << "\nYou cast stun\n";
    magictype = 4150;
  }
  // - - - Вода - - -
  else if (((m1 == 2 && m2 == 3) ||(m1 == 3 && m2 == 2)) && iliya.power>=50)
  {
    iliya.ground--;
    iliya.water--;
    iliya.air--;
    iliya.power-=50;
    iliya.statmag=40;
    cout << "\nYou cast spike\n";
    magictype = 3230;
  }
  else if (((m1 == 2 && m2 == 4) || (m1 == 4 && m2 == 2)) && iliya.power>=100)
  {
    iliya.ground--;
    iliya.water--;
    iliya.ground--;
    iliya.power-=100;
    iliya.statmag=32;
    cout << "\nYou cast water immunity\n";
    magictype = 4240;
  }
  else if (((m1 == 2 && m2 == 5) || (m1 == 5 && m2 == 2)) && iliya.power>=50)
  {
    iliya.ground--;
    iliya.air--;
    iliya.spirit--;
    iliya.power-=50;
    firstmon[montype].power=-30;
    cout << "\nYou cast slow time\n";
    magictype = 4250;
  }
  // - - - Воздух - - -
  else if (((m1 == 3 && m2 == 5) || (m1 == 5 && m2 == 3)) && iliya.power>=100)
  {
    iliya.ground--;
    iliya.air--;
    iliya.spirit--;
    iliya.power-=100;
    iliya.statmag=33;
    cout << "\nYou cast air immunity\n";
    magictype = 3350;
  }
  // - - - Земля - - -
  else if (((m1 == 4 && m2 == 5) || (m1 == 5 && m2 == 4)) && iliya.power>=100)
  {
    iliya.ground--;
    iliya.air--;
    iliya.spirit--;
    iliya.power-=100;
    iliya.statmag=34;
    cout << "\nYou cast ground immunity\n";
    magictype = 3450;
  }
  else if (m1 == 0 && m2 == 1 && iliya.fire<iliya.maxfire)
  {
    iliya.fire++;
  }
  else if (m1 == 0 && m2 == 2 && iliya.water<iliya.maxwater)
  {
    iliya.water++;
  }
  else if (m1 == 0 && m2 == 3 && iliya.air<iliya.maxair)
  {
    iliya.air++;
  }
  else if (m1 == 0 && m2 == 4 && iliya.ground<iliya.maxground)
  {
    iliya.ground++;
  }
  else if (m1 == 0 && m2 == 5 && iliya.spirit<iliya.maxspirit)
  {
    iliya.spirit++;
  }
  else if (m1 ==0 && m2 == 0 && iliya.power+10<=iliya.maxpower)
  iliya.power+=10;
  if (iliya.statmag==22)
{
firstmon[montype].health-=hit;
hit*=2;
}
if (hit!=0)
firstmon[montype].power-=5;
cout << "\nEnemy hit: " << hit;


  return magictype;
return 0;
}





int fire3(int m1, int m2,int montype)
{
  int magictype=0;
  int hit=0;
  randomize();
  // Ничего
  if (m1 == m2 && m1!=0 && m2!=0)
  {
  cout << "\nNothing happens\n";
  return 0;
  }
  else if ((m1 == 1 && m2 == 2) || (m2 == 1 && m1 == 2) || (m1 == 3 && m2 == 4) || (m2 == 3 && m1 == 4))
  {
  cout << "\nEffect was unknown\n";
  iliya.fire-=random(3)-1;
  iliya.water-=random(3)-1;
  iliya.air-=random(3)-1;
  iliya.ground-=random(3)-1;
  iliya.spirit-=random(3)-1;
  iliya.power-=random(16);
  magictype = random(5);
  if (magictype == 4)
  iliya.health-= 5;
  else if (magictype == 3)
  iliya.health-= 10;
  else if (magictype == 2)
  iliya.health+= 5;
  else if (magictype == 1)
  magictype = 14;
  else
  magictype = 0;
  }
  // - - - Огонь - - -
  else if (m1 == 1 && m2 == 3 && iliya.power>=25)
  {
    iliya.fire--;
    iliya.fire--;
    iliya.air--;
    iliya.power-=25;
    hit = random(6+5+iliya.level);
    if (firstmon[montype].fire<1)
    firstmon[montype].health-=hit-firstmon[montype].defence;
    cout << "\nYou cast fire storm\n";
    magictype = 1130;
  }
  else if (m1 == 1 && m2 == 4 && iliya.power>=30)
  {
    iliya.fire--;
    iliya.fire--;
    iliya.ground--;
    iliya.power-=30;
    firstmon[montype].power=0;
    hit = random(6+iliya.level);
    if (firstmon[montype].fire<1)
    firstmon[montype].health-=hit-firstmon[montype].defence;
    cout << "\nYou cast anger of fire\n";
    magictype = 1140;
  }
  else if (m1 == 1 && m2 == 5 && iliya.power>=50)
  {
    iliya.fire--;
    iliya.fire--;
    iliya.spirit--;
    iliya.power-=50;
    iliya.statmag=1;
    cout << "\nYou cast fire element\n";
    magictype = 1150;
  }
  // - - - Вода - - -
  else if (m1 == 2 && m2 == 3 && iliya.power>=25)
  {
    iliya.fire--;
    iliya.water--;
    iliya.air--;
    iliya.power-=25;
    hit = random(6+iliya.level)+5;
    if (firstmon[montype].fire<1 && firstmon[montype].water<1)
    firstmon[montype].health-=hit-firstmon[montype].defence;
    cout << "\nYou cast fire wave\n";
    magictype = 1230;
  }
  else if (m1 == 2 && m2 == 4 && iliya.power>=30)
  {
    iliya.fire--;
    iliya.water--;
    iliya.ground--;
    iliya.power-=30;
    cout << "\nYou cast poision\n";
    firstmon[montype].power=-20;
    magictype = 1240;
  }
  else if (m1 == 2 && m2 == 5 && iliya.power>=50)
  {
    iliya.fire--;
    iliya.water--;
    iliya.spirit--;
    iliya.power-=50;
    iliya.statmag=2;
    cout << "\nYou cast water element";
    magictype = 1250;
  }
  // - - - Воздух - - -
  else if (m1 == 3 && m2 == 1  && iliya.power>=20)
  {
    iliya.fire--;
    iliya.fire--;
    iliya.air--;
    iliya.power-=20;
    if (iliya.health<=iliya.maxhealth+10)
    iliya.health+=10;
    else iliya.health=iliya.maxhealth;
    cout << "\nYou cast holy soul\n";
    magictype = 1310;
  }
  else if (m1 == 3 && m2 == 2 && iliya.power>=25)
  {
    iliya.fire--;
    iliya.water--;
    iliya.air--;
    iliya.power-=25;
    hit = random(6+iliya.level)+5;
    if (firstmon[montype].fire<1 && firstmon[montype].air<1)
    firstmon[montype].health-=hit-firstmon[montype].defence;
    cout << "\nYou cast chain lightning\n";
    magictype = 1320;
  }
  else if (m1 == 3 && m2 == 5 && iliya.power>=50)
  {
    iliya.fire--;
    iliya.air--;
    iliya.spirit--;
    iliya.power-=50;
    iliya.statmag=3;
    cout << "\nYou cast air element\n";
    magictype = 1350;
  }
  // - - - Земля - - -
  else if (m1 == 4 && m2 == 1 && iliya.power>=25)
  {
    iliya.fire--;
    iliya.fire--;
    iliya.ground--;
    iliya.power-=25;
    hit = random(6+iliya.level)+5;
    if (firstmon[montype].fire<1 && firstmon[montype].ground<1)
    firstmon[montype].health-=hit-firstmon[montype].defence;
    cout << "\nYou cast falling stones\n";
    magictype = 1430;
  }
  else if (m1 == 4 && m2 == 2 && iliya.power>=15)
  {
    iliya.fire--;
    iliya.water--;
    iliya.ground--;
    iliya.power-=15;
    hit = random(6+iliya.level);
    if (firstmon[montype].ground<1)
    firstmon[montype].health-=hit-firstmon[montype].defence;
    cout << "\nYou cast landfall\n";
    magictype = 1420;
  }
  else if (m1 == 4 && m2 == 5 && iliya.power>=50)
  {
    iliya.fire--;
    iliya.ground--;
    iliya.spirit--;
    iliya.power-=50;
    iliya.statmag=4;
    cout << "\nYou cast ground element";
    magictype = 1450;
  }
  // - - - Дух - - -
  else if (m1 == 5 && m2 == 1 && iliya.power>=100)
  {
    iliya.fire-=2;
    iliya.spirit--;
    iliya.power-=100;
    int success;
    success=random(2);
    if (success==1)
    if (firstmon[montype].nametd==15 || firstmon[montype].nametd==20)
    firstmon[montype].health=0;
    cout << "\nYou cast ecsorcist\n";
    magictype = 1510;
  }
  else if (m1 == 5 && m2 == 2  && iliya.power>=100)
  {
    iliya.fire--;
    iliya.water--;
    iliya.spirit--;
    iliya.power-=100;
    int success;
    success=random(2);
    if (success==1)
    if (firstmon[montype].nametd==4 || firstmon[montype].nametd==12 || firstmon[montype].nametd==5)
    firstmon[montype].health=0;
    cout << "\nYou cast return to abyss\n";
    magictype = 1520;
  }
  else if (m1 == 5 && m2 == 3  && iliya.power>=100)
  {
    iliya.fire--;
    iliya.air--;
    iliya.spirit--;
    iliya.power-=100;
    int success;
    success=random(2);
    if (success==1)
    if (firstmon[montype].nametd==14 && firstmon[montype].nametd==16)
    firstmon[montype].health=0;
    cout << "\nYou cast deadly cloud\n";
    magictype = 1530;
  }
  else if (m1 == 5 && m2 == 4  && iliya.power>=100)
  {
    iliya.fire--;
    iliya.ground--;
    iliya.spirit--;
    iliya.power-=100;
    int success;
    success=random(2);
    if (success==1)
    if (firstmon[montype].nametd==1 || firstmon[montype].nametd==2 || firstmon[montype].nametd==3 || firstmon[montype].nametd==11)
    firstmon[montype].health=0;
    cout << "\nYou cast tomb\n";
    magictype = 1540;
  }
  else if (m1 == 0 && m2 == 1 && iliya.fire<iliya.maxfire)
  {
    iliya.fire++;
  }
  else if (m1 == 0 && m2 == 2 && iliya.water<iliya.maxwater)
  {
    iliya.water++;
  }
  else if (m1 == 0 && m2 == 3 && iliya.air<iliya.maxair)
  {
    iliya.air++;
  }
  else if (m1 == 0 && m2 == 4 && iliya.ground<iliya.maxground)
  {
    iliya.ground++;
  }
  else if (m1 == 0 && m2 == 5 && iliya.spirit<iliya.maxspirit)
  {
    iliya.spirit++;
  }
  else if (m1 ==0 && m2 == 0 && iliya.power+10<=iliya.maxpower)
  iliya.power+=10;
  if (iliya.statmag==22)
  {
  firstmon[montype].health-=hit;
  hit*=2;
  }
  if (hit!=0)
  firstmon[montype].power-=5;
  cout << "\nEnemy hit: " << hit;
  return magictype;
  return 0;
}

inline int magicmod(int m1, int m2, int m3, int montype)
{
  int t,success,magictype;
  success=random(iliya.luck);
  if (success!=0)
  {
  if (m1==1)
  {
  t=fire3(m2,m3,montype);
  return t;
  }
  else if (m1==2)
  {
  t=water3(m2,m3,montype);
  return t;
  }
  else if (m1==3)
  {
  t=air3(m2,m3,montype);
  return t;
  }
  else if (m1==4)
  {
  t=ground3(m2,m3,montype);
  return t;
  }
  else if (m1==5)
  {
  t=spirit3(m2,m3,montype);
  return t;
  }
  else if (m1==0)
  {
  if (m1 == 0 && m2 == 1 && iliya.fire<=iliya.maxfire)
{
  iliya.fire++;
}
else if (m1 == 0 && m2 == 2 && iliya.water<=iliya.maxwater)
{
  iliya.water++;
}
else if (m1 == 0 && m2 == 3 && iliya.air<=iliya.maxair)
{
  iliya.air++;
}
else if (m1 == 0 && m2 == 4 && iliya.ground<=iliya.maxground)
{
  iliya.ground++;
}
else if (m1 == 0 && m2 == 5 && iliya.spirit<=iliya.maxspirit)
{
  iliya.spirit++;
}
else if (m1 ==0 && m2 == 0 && iliya.power+10<=iliya.maxpower)
iliya.power+=10;
return magictype;
  }
  }
  else cout << "\nSpell interrupted\n";
  monsteratt(0,montype,t);
  return 0;
}

int magic(int m1, int m2, int m3, int montype)
{
  int hit=0;
  magicmod(m1,m2,m3,montype);
  if (iliya.statmag==1 && firstmon[montype].fire<1)
  {
  hit=random(6+iliya.level);
  firstmon[montype].health-=hit-firstmon[montype].defence;
  }
  else if (iliya.statmag==2 && firstmon[montype].water<1)
  {
  hit=random(6+iliya.level);
  firstmon[montype].health-=hit-firstmon[montype].defence;
  }
  if (iliya.statmag==3 && firstmon[montype].air<1)
  {
  hit=random(6+iliya.level);
  firstmon[montype].health-=hit-firstmon[montype].defence;
  }
  if (iliya.statmag==4 && firstmon[montype].ground<1)
  {
  hit=random(6+iliya.level);
  firstmon[montype].health-=hit-firstmon[montype].defence;
  }
  return 0;
}

inline int magicmod(int m1, int m2,int montype)
{
  int monsterdo=0;
  int magictype=0;
  randomize();
  // Ничего
  if (m1 == m2 && m1!=0 && m2!=0)
  {
  cout << "\nNothing happens\n";
  return 0;
  }
  else if ((m1 == 1 && m2 == 2) || (m2 == 1 && m1 == 2) || (m1 == 3 && m2 == 4) || (m2 == 3 && m1 == 4))
  {
  cout << "\nEffect was unknown\n";
  iliya.fire-=random(3)-1;
  iliya.water-=random(3)-1;
  iliya.air-=random(3)-1;
  iliya.ground-=random(3)-1;
  iliya.spirit-=random(3)-1;
  iliya.power-=random(16);
  magictype = random(5);
  if (magictype == 4)
  iliya.health-= 5;
  else if (magictype == 3)
  iliya.health-= 10;
  else if (magictype == 2)
  iliya.health+= 5;
  else if (magictype == 1)
  magictype = 14;
  else
  magictype = 0;
  }
  // - - - Огонь - - -
  else if (m1 == 1 && m2 == 3 && iliya.power>=5)
  {
    iliya.fire--;
    iliya.air--;
    iliya.power-=5;
    cout << "\nYou cast fire arrow\n";
    magictype = 13;
  }
  else if (m1 == 1 && m2 == 4 && iliya.power>=10)
  {
    iliya.fire--;
    iliya.ground--;
    iliya.power-=10;
    cout << "\nYou cast fire ball\n";
    magictype = 14;
  }
  else if (m1 == 1 && m2 == 5 && iliya.power>=15)
  {
    iliya.fire--;
    iliya.spirit--;
    iliya.power-=15;
    cout << "\nYou cast bravery";
    magictype = 15;
  }
  // - - - Вода - - -
  else if (m1 == 2 && m2 == 3 && iliya.power>=10)
  {
    iliya.water--;
    iliya.air--;
    iliya.power-=10;
    cout << "\nYou cast blizzard\n";
    magictype = 23;
  }
  else if (m1 == 2 && m2 == 4 && iliya.power>=5)
  {
    iliya.water--;
    iliya.ground--;
    iliya.power-=5;
    cout << "\nYou cast ice arrow\n";
    magictype = 24;
  }
  else if (m1 == 2 && m2 == 5 && iliya.power>=15)
  {
    iliya.water--;
    iliya.spirit--;
    iliya.power-=15;
    cout << "\nYou cast cure";
    magictype = 25;
  }
  // - - - Воздух - - -
  else if (m1 == 3 && m2 == 1  && iliya.power>=10)
  {
    iliya.fire--;
    iliya.air--;
    iliya.power-=10;
    firstmon[montype].power=-10;
    cout << "\nYou cast sleep\n";
    magictype = 31;
  }
  else if (m1 == 3 && m2 == 2 && iliya.power>=5)
  {
    iliya.water--;
    iliya.air--;
    iliya.power-=5;
    cout << "\nYou cast lightning\n";
    magictype = 32;
  }
  else if (m1 == 3 && m2 == 5 && iliya.power>=15)
  {
    iliya.air--;
    iliya.spirit--;
    iliya.power-=15;
    cout << "\nYou cast haste";
    magictype = 35;
  }
  // - - - Земля - - -
  else if (m1 == 4 && m2 == 1 && iliya.power>=10)
  {
    iliya.fire--;
    iliya.ground--;
    iliya.power-=10;
    cout << "\nYou cast meteor\n";
    magictype = 41;
  }
  else if (m1 == 4 && m2 == 2 && iliya.power>=5)
  {
    iliya.water--;
    iliya.ground--;
    iliya.power-=5;
    firstmon[montype].power=0;
    cout << "\nYou cast web\n";
    magictype = 42;
  }
  else if (m1 == 4 && m2 == 5 && iliya.power>=15)
  {
    iliya.ground--;
    iliya.spirit--;
    iliya.power-=15;
    cout << "\nYou cast fear";
    magictype = 45;
  }
  // - - - Дух - - -
  else if (m1 == 5 && m2 == 1 && iliya.power>=15)
  {
    iliya.fire--;
    iliya.spirit--;
    iliya.power-=15;
    cout << "\nYou cast protection from fire\n";
    magictype = 51;
  }
  else if (m1 == 5 && m2 == 2  && iliya.power>=15)
  {
    iliya.water--;
    iliya.spirit--;
    iliya.power-=15;
    cout << "\nYou cast protection from water\n";
    magictype = 52;
  }
  else if (m1 == 5 && m2 == 3  && iliya.power>=15)
  {
    iliya.air--;
    iliya.spirit--;
    iliya.power-=15;
    cout << "\nYou cast protection from air\n";
    magictype = 53;
  }
  else if (m1 == 5 && m2 == 4  && iliya.power>=15)
  {
    iliya.ground--;
    iliya.spirit--;
    iliya.power-=15;
    cout << "\nYou cast protection from ground\n";
    magictype = 54;
  }
  else if (m1 == 0 && m2 == 1 && iliya.fire<iliya.maxfire)
  {
    iliya.fire++;
  }
  else if (m1 == 0 && m2 == 2 && iliya.water<iliya.maxwater)
  {
    iliya.water++;
  }
  else if (m1 == 0 && m2 == 3 && iliya.air<iliya.maxair)
  {
    iliya.air++;
  }
  else if (m1 == 0 && m2 == 4 && iliya.ground<iliya.maxground)
  {
    iliya.ground++;
  }
  else if (m1 == 0 && m2 == 5 && iliya.spirit<iliya.maxspirit)
  {
    iliya.spirit++;
  }
  else if (m1 ==0 && m2 == 0 && iliya.power+10<=iliya.maxpower)
  iliya.power+=10;
  return magictype;
}

magic(int m1, int m2, int montype)
{
  randomize();
  int magictype;
  int monsterdo=0;
  int success=0;
  int hit=0;
  success=random(iliya.luck);
  if (success!=0 && (iliya.power>0 || m1==0))
  {
  // fire = 1
  // water = 2
  // air = 3
  // ground = 4
  // spirirt = 5
  // montype 0 = none, 1 = bear, 2 = wolf, 3 = pig, 4 = raptor;
  magictype=magicmod(m1,m2,montype);
  // fire
  if (m1==1)
  {
    if (firstmon[montype].fire<1)
    {
    if (magictype == 13)
    {
    hit=random(4+iliya.level)-firstmon[montype].defence;
    firstmon[montype].health-=hit;
    firstmon[montype].power-=5;
    }
    else if (magictype == 14)
    {
      hit = random(6+iliya.level)-firstmon[montype].defence;
      firstmon[montype].health-=hit;
    firstmon[montype].power-=5;
    }
    else if (magictype == 15)
    iliya.strength++; // static!!!
  }
  }
  //water
  else if (m1==2)
  {
    if (firstmon[montype].water<1)
    {
    if (magictype == 23)
    {
    hit = random(6+iliya.level)-firstmon[montype].defence;
    firstmon[montype].health-=hit;
    firstmon[montype].power-=5;
    }
    else if (magictype == 24)
    {
    hit = random(4+iliya.level)-firstmon[montype].defence;
    firstmon[montype].health-=hit;
    firstmon[montype].power-=5;
    }
    else if (magictype == 25)
    {
    if (iliya.health+10<iliya.maxhealth)
    iliya.health+=10;
    }
  }
  }
  //air
  else if (m1==3)
  {
    if (firstmon[montype].air<1)
    {
    if (magictype == 31)
    monsterdo=2;
    else if (magictype == 32)
    {
    hit = random(4+iliya.level)-firstmon[montype].defence;
    firstmon[montype].health-=hit;
    firstmon[montype].power-=5;
    }
    else if (magictype == 35)
    {
    iliya.luck++; //static!!!
    }
  }
  }
  //ground
  else if (m1==4)
  {
    if (firstmon[montype].ground<1)
    {
    if (magictype == 41)
    {
    hit = random(6+iliya.level)-firstmon[montype].defence;
    firstmon[montype].health-=hit;
    firstmon[montype].power-=5;
    }
    else if (magictype == 42)
    {
    monsterdo=1;
    }
    else if (magictype == 45)
    {
    if  (firstmon[montype].defence-1>=0)
    firstmon[montype].defence--; //static!!!
    }
  }
  }
  cout << "\nEnemy hit: " << hit;
  }
  else cout << "\nSpell was interrupted";
  //spirit NA
  monsteratt(monsterdo,montype,magictype);
return 0;
}

int attack(int nummon)
{
  int m1, m2, m3, modifier,bufz=0;
  m1=0;m2=0;m3=0;;
  cout << "\n" << iliya.plname << " with " << iliya.health << " health.\nPower: " << iliya.power << " Fire: " << iliya.fire << " Water: "<< iliya.water << " Air: " << iliya.air << " Ground: " << iliya.ground << " Spirit: " << iliya.spirit << "\nMelee attack - (6)\nYou can restore power by 0 - type\n";
  cout << "\n" << firstmon[nummon].name << " with " << firstmon[nummon].health << " health\nChoose yor magic 1-5 and 1-5: "; //monster
  if (iliya.level<7)
  cin >> m1 >> m2;
  else
  {
    cout << "\nChoose magic power: 1 - Simple or 2 - Full\n";
    for (;;)
    {
      cin >> bufz;
      if (bufz==1)
      {
      cout << "Enter magic: ";
      cin >> m1 >> m2;
      break;
      }
      else if (bufz==2)
      {
      cout << "Enter magic: ";
      cin >> m1 >> m2 >> m3;
      break;
      }
      else
      cout << bufz;
      }
    }

/*  if (iliya.level>19)
  {
    cout << "\n!!!\n"; //!!!
  }*/
  for (;;)
  {
  if (m1==0)
  break;
  int error=0;
  if ((iliya.fire<=0 && (m1==1 || m2==1)) || (iliya.fire<=1 && ((m3==1 && (m1==1 || m2==1)) || (m2==1 && (m1==1 || m3==1)))))
  error++;
  if  ((iliya.water<=0 && (m1==2 || m2==2)) || (iliya.water<=1 && ((m3==2 && (m1==2 || m2==2)) || (m2==2 && (m1==2 || m3==2)))))
  error++;
  if  ((iliya.air<=0 && (m1==3 || m2==3)) || (iliya.air<=1 && ((m3==3 && (m1==3 || m2==3)) || (m2==3 && (m1==3 || m3==3)))))
  error++;
  if ((iliya.ground<=0 && (m1==4 || m2==4)) || (iliya.ground<=1 && ((m3==4 && (m1==4 || m2==4)) || (m2==4 && (m1==4 || m3==4)))))
  error++;
  if ((iliya.spirit<=0 && (m1==5 || m2==5)) || (iliya.spirit<=1 && ((m3==5 && (m1==5 || m2==5)) || (m2==5 && (m1==5 || m3==5)))) || (iliya.spirit<=2 && (m1==5 && m2==5 && m3==5)))
  error++;
  if ((m1>6 || m2>6)  || (m1<0 || m2<0))
  error++;
 // cout << error; //debug!
  if (error>0)
  {
    cout << "\n" << iliya.plname << " with " << iliya.health << " health.\nPower: " << iliya.power << " Fire: " << iliya.fire << " Water: "<< iliya.water << " Air: " << iliya.air << " Ground: " << iliya.ground << " Spirit: " << iliya.spirit << "\nYou can restore power by 0 - type\n";
    cout << "\n" << firstmon[nummon].name << " with " << firstmon[nummon].health << " health\nChoose yor magic 1-5 and 1-5: "; //monster
    if (iliya.level<7)
    cin >> m1 >> m2;
    else
    {
      cout << "\nChoose magic power: 1 - Simple or 2 - Full\n";
      for (;;)
      {
        cin >> bufz;
        if (bufz==1)
        {
        cout << "Enter magic: ";
        cin >> m1 >> m2;
        break;
        }
        else if (bufz==2)
        {
        cout << "Enter magic: ";
        cin >> m1 >> m2 >> m3;
        break;
        }
        else
        cout << bufz;
        }
      }
/*    if (iliya.level>19)
    {
      cout << "\n!!!\n"; //!!!
    } */ // бонусы!
  }
  else break;
  }
  if (m1!=6)
  {
  if (bufz==2)
  magic(m1,m2,m3,nummon);
  else magic(m1,m2,nummon);
  }
  else
  {
 int hit = 0;
 hit = random(iliya.strength*(iliya.level+1)-iliya.level);
 if (nummon>24)
 hit/=4;
 else if (nummon>19)
 hit/=3;
 else if (nummon>14)
 hit/=2;
 if (hit-firstmon[nummon].defence>=0)
 firstmon[nummon].health-=hit-firstmon[nummon].defence;
 if (iliya.power>=25)
 iliya.power-=25;
 monsteratt(0,nummon,0);
  }
return 0;
}

int monsterin()
{
  unsigned char name[1024];
  int param;
  ofstream w;
  w.open("monster.txt",ios::app);
  while (!w)
  w.open("monster.txt");
  cout << "\nEnter the data of monster\n";
  cout << "\nName: "; cin >>  name;
  w << "\n" << name << " ";
  cout << "\nPower: "; cin >>  param;
  w << param << " ";   w << param << " ";
  cout << "\nDamage: "; cin >>  param;
  w << param << " ";
  cout << "\nDefence: "; cin >>  param;
  w << param << " ";
  cout << "\nHealth: "; cin >>  param;
  w << param << " ";   w << param << " ";
  cout << "\nFire: "; cin >>  param;
  w << param << " ";
  cout << "\nWater: "; cin >>  param;
  w << param << " ";
  cout << "\nAir: "; cin >>  param;
  w << param << " ";
  cout << "\nGround: "; cin >>  param;
  w << param << " ";
  cout << "\nSpirit: "; cin >>  param;
  w << param << " ";
  cout << "\nLuck: "; cin >>  param;
  w << param << " ";
  cout << "\nExp: "; cin >>  param;
  w << param << " ";
  w.close();
  return 0;
}

int monsterout()
{
int i=0;
ifstream r;
r.open("monster.dat");
while (!r)
r.open("monster.dat");
r >> firstmon[i].nametd >> firstmon[i].maxpower >> firstmon[i].power >> firstmon[i].damage >> firstmon[i].defence >> firstmon[i].maxhealth >> firstmon[i].health >> firstmon[i].fire >> firstmon[i].water >> firstmon[i].air >> firstmon[i].ground >> firstmon[i].spirit >> firstmon[i].luck >> firstmon[i].exp;
while (i<30)
{
  if (r.eof())
  break;
  if (firstmon[i].nametd==1)
  strcpy(firstmon[i].name,"Pig");
  else if (firstmon[i].nametd==2)
  strcpy(firstmon[i].name,"Wolf");
  else if (firstmon[i].nametd==3)
  strcpy(firstmon[i].name,"Bear");
  else if (firstmon[i].nametd==4)
  strcpy(firstmon[i].name,"Raptor");
  else if (firstmon[i].nametd==5)
  strcpy(firstmon[i].name,"Lizardmen");
  else if (firstmon[i].nametd==6)
  strcpy(firstmon[i].name,"Spider");
  else if (firstmon[i].nametd==7)
  strcpy(firstmon[i].name,"Goblin");
  else if (firstmon[i].nametd==8)
  strcpy(firstmon[i].name,"Ork");
  else if (firstmon[i].nametd==9)
  strcpy(firstmon[i].name,"Hobgoblin");
  else if (firstmon[i].nametd==10)
  strcpy(firstmon[i].name,"Troll");
  else if (firstmon[i].nametd==11)
  strcpy(firstmon[i].name,"Snow Wolf");
  else if (firstmon[i].nametd==12)
  strcpy(firstmon[i].name,"Vasilisk");
  else if (firstmon[i].nametd==13)
  strcpy(firstmon[i].name,"Manticore");
  else if (firstmon[i].nametd==14)
  strcpy(firstmon[i].name,"Thunderbird");
  else if (firstmon[i].nametd==15)
  strcpy(firstmon[i].name,"Spirit");
  else if (firstmon[i].nametd==16)
  strcpy(firstmon[i].name,"Phoenix");
  else if (firstmon[i].nametd==17)
  strcpy(firstmon[i].name,"Frost Giant");
  else if (firstmon[i].nametd==18)
  strcpy(firstmon[i].name,"Mud Devil");
  else if (firstmon[i].nametd==19)
  strcpy(firstmon[i].name,"Genie");
  else if (firstmon[i].nametd==20)
  strcpy(firstmon[i].name,"Horror");
  else if (firstmon[i].nametd==21)
  strcpy(firstmon[i].name,"Iron Golem");
  else if (firstmon[i].nametd==22)
  strcpy(firstmon[i].name,"Black Knight");
  else if (firstmon[i].nametd==23)
  strcpy(firstmon[i].name,"Wisp");
  else if (firstmon[i].nametd==24)
  strcpy(firstmon[i].name,"Succubus");
  else if (firstmon[i].nametd==25)
  strcpy(firstmon[i].name,"Shade of Mage");
  else if (firstmon[i].nametd==26)
  strcpy(firstmon[i].name,"Hard Drinker");
  else if (firstmon[i].nametd==27)
  strcpy(firstmon[i].name,"Soul Reaper");
  else if (firstmon[i].nametd==28)
  strcpy(firstmon[i].name,"Blotig Racher");
  else if (firstmon[i].nametd==29)
  strcpy(firstmon[i].name,"Reclaim Death");
  else if (firstmon[i].nametd==30)
  strcpy(firstmon[i].name,"Azure Dragon");
  i++;
  r >> firstmon[i].nametd >> firstmon[i].maxpower >> firstmon[i].power >> firstmon[i].damage >> firstmon[i].defence >> firstmon[i].maxhealth >> firstmon[i].health >> firstmon[i].fire >> firstmon[i].water >> firstmon[i].air >> firstmon[i].ground >> firstmon[i].spirit >> firstmon[i].luck >> firstmon[i].exp;
}
r.close();
monnum=i;
//return 0;
}

int restart()
{
  iliya.statmag=0;
  iliya.health=iliya.maxhealth;
  iliya.power=iliya.maxpower;
  iliya.fire=iliya.maxfire;
  iliya.water=iliya.maxwater;
  iliya.air=iliya.maxair;
  iliya.ground=iliya.maxground;
  iliya.spirit=iliya.maxspirit;
  iliya.luck=iliya.maxluck;
  iliya.strength=iliya.maxstrength;
  return 0;
}

void statistic()
{
  cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
  cout << "Name: " << iliya.plname << " " << iliya.health << "\/" << iliya.maxhealth << endl;
  cout << "Fire: " << iliya.fire << "\/" << iliya.maxfire << " Water: " << iliya.water << "\/" << iliya.maxwater << " Air: " << iliya.air << "\/" << iliya.air << " Ground: " << iliya.ground << "\/" << iliya.ground << " Spirit: " << iliya.spirit << "\/" << iliya.maxspirit << endl;
  cout << "Level: " << iliya.level << " Experience: " << iliya.exp << " Killed: " << iliya.kill << endl;
  cout << "Power: " << iliya.power << "\/" << iliya.maxpower << " Strength: " << iliya.strength << "\/" << iliya.maxstrength << " Luck: " << iliya.luck << "\/" << iliya.maxluck << endl << endl;
}

void newlevel()
{
  char buf;
  if (iliya.exp>(iliya.level+1)*10*(iliya.level+1)-1)
  {
    iliya.maxhealth+=5;
    iliya.level++;
  for(int j=0;j<1;j++)
  {
  cout << "\nNew level reached! Choose promote: Magic (1-5), (P)ower, (S)trength or (L)uck";
  buf=getch();
  switch(buf)
  {
  case '1':
  iliya.maxfire++;
  break;
  case '2':
  iliya.maxwater++;
  break;
  case '3':
  iliya.maxair++;
  break;
  case '4':
  iliya.maxground++;
  break;
  case '5':
  iliya.maxspirit++;
  break;
  case 'P':
  iliya.maxpower+=25;
  break;
  case 'p':
  iliya.maxpower+=25;
  break;
  case 'S':
  iliya.maxstrength++;
  break;
  case 's':
  iliya.maxstrength++;
  break;
  case 'L':
  iliya.maxluck++;
  break;
  case 'l':
  iliya.maxluck++;
  break;
  default:
  continue;
  break;
  }
  }
  }
}

int save0(void)
{
  char filename[1024];
  ofstream w;
  strcpy(filename,iliya.plname);
  int i=0;
  while(filename[i]!='\0')
  i++;
  filename[i]='.'; filename[i+1]='s'; filename[i+2]='a';filename[i+3]='v';filename[i+4]='\0';
  w.open(filename,ios::binary);
  if (!w)
  return 1;
  w.write((char*)&iliya,sizeof(iliya));
  w.close();
  return 0;
}

int load0(void)
{
  ifstream r;
  char filename[1024];
  cout << "\nEnter your name: "; cin >> iliya.plname;
  strcpy(filename,iliya.plname);
  int i=0;
  while(filename[i]!='\0')
  i++;
  filename[i]='.'; filename[i+1]='s'; filename[i+2]='a';filename[i+3]='v';filename[i+4]='\0';
  r.open(filename,ios::binary);
  if (!r)
  return 1;
  r.read((char*)&iliya,sizeof(iliya));
  r.close();
  iliya.load++;
  return 0;
}

int viewscore()
{
  char filename[]="score.dat";
  strcpy(score0.name,iliya.plname);
  score0.score=(iliya.exp/iliya.kill)/iliya.load;
  ifstream w;
  w.open(filename,ios::binary);
  w.read((char*)&score0,sizeof(score0));
  while (!w.eof())
  {
      cout << endl << "Name: "<< score0.name << "\t" << score0.score;
      w.read((char*)&score0,sizeof(score0));
  }
  w.close();
}

int score()
{
  char filename[]="score.dat";
  strcpy(score0.name,iliya.plname);
  if (iliya.load==0)
  iliya.load++;
  if (iliya.kill==0)
  iliya.kill++;
  score0.score=(iliya.exp/(iliya.kill+iliya.load));
  ofstream w;
  w.open(filename,(ios::binary,ios::app));
  w.write((char*)&score0,sizeof(score0));
  w.close();

}

int main( int argc, char * argv[] )
{
/*  monsterin();
    monsterin();
      monsterin();
        monsterin();
          monsterin(); */
  cout << "\t\tWelcome to Magic: Return of the Mages!\n\tBy The Design Studio Vereshchagin 2001-2005 (C)\n\n\tStart (N)ew game or (L)oad preveus saved game?";
  char bufd; int t;
  bufd=getch();
  if (bufd=='N' || bufd=='n')
  gamenew();
  else if (bufd=='L' || bufd=='l')
  {
  t=load0();
  if (t!=0)
  {
  cout << "\nSavegame not loaded\nStarting new game\n";
  getch();
  gamenew();
  }
  }
  //score();//debug!!
  randomize();
  int nummon;
  for(;;)
  {
  monsterout();
  newlevel();
  restart();
  if (iliya.level+1<=monnum)
  nummon=random(iliya.level+2);
  else nummon=random(monnum);
  cout << "\n\nYou enemy is " << firstmon[nummon].name << "\n(A)ttack or (R)etry, view (J)ournal, or (S)ave game\n";
  char bufs;
  bufs=getch();
  if (bufs=='R' || bufs == 'r')
  {
    if (random(iliya.luck)==1)
    {
    while (iliya.luck>5)
    iliya.luck/=2;
    iliya.exp-=random(11)+5-iliya.luck;
    firstmon[nummon].health=0;
    cout << "\nYou've retired and loose experience points\n";
    }
    else if (random(iliya.luck!=0))
    {
    firstmon[nummon].health=0;
    cout << "\nYou've retired\n";
    }
    else   {
  while (firstmon[nummon].health>0)
  {
    if (iliya.fire<0) iliya.fire=0;
    if (iliya.water<0) iliya.water=0;
    if (iliya.ground<0) iliya.ground=0;
    if (iliya.air<0) iliya.air=0;
    if (iliya.spirit<0) iliya.spirit=0;
    if (iliya.health<=0)
    { score(); cout << "\nYou're dead\n"; getch();
  cout << "\n\t\t\tGame over\n";
  cout << "\nView score? (y/n)";
  bufd=getch();
  if (bufd=='y' || bufd=='Y')
  viewscore();
  getch();
  exit(0);
}
    if (firstmon[nummon].health<=0) { break; }
    attack(nummon);
  }
  }
  }
  else if (bufs=='~')
  exit(0);
  else if (bufs=='J' || bufs =='j')
  {
  statistic();
  while (firstmon[nummon].health>0)
{
  if (iliya.fire<0) iliya.fire=0;
  if (iliya.water<0) iliya.water=0;
  if (iliya.ground<0) iliya.ground=0;
  if (iliya.air<0) iliya.air=0;
  if (iliya.spirit<0) iliya.spirit=0;
  if (iliya.health<=0)
  { score(); cout << "\nYou're dead\n"; getch();
cout << "\n\t\t\tGame over\n";
cout << "\nView score? (y/n)";
bufd=getch();
if (bufd=='y' || bufd=='Y')
viewscore();
getch();
exit(0);
}
  attack(nummon);
    if (firstmon[nummon].health<=0) { cout << "\nMonster is dead\n"; iliya.exp+=firstmon[nummon].exp; iliya.kill++; break;}
}
  }
  else if (bufs=='S' || bufs =='s')
  {
  save0();
  while (firstmon[nummon].health>0)
{
  if (iliya.fire<0) iliya.fire=0;
  if (iliya.water<0) iliya.water=0;
  if (iliya.ground<0) iliya.ground=0;
  if (iliya.air<0) iliya.air=0;
  if (iliya.spirit<0) iliya.spirit=0;
  if (iliya.health<=0)
  { score(); cout << "\nYou're dead\n"; getch();
cout << "\n\t\t\tGame over\n";
cout << "\nView score? (y/n)";
bufd=getch();
if (bufd=='y' || bufd=='Y')
viewscore();
getch();
exit(0);
}
  attack(nummon);
     if (firstmon[nummon].health<=0) { cout << "\nMonster is dead\n"; iliya.exp+=firstmon[nummon].exp; iliya.kill++; break;}
}

  }
  else if (bufs!='A' || bufs!='a')
  {
  while (firstmon[nummon].health>0)
  {
    if (iliya.health<=0)
    { score(); cout << "\nYou're dead\n"; getch();
  cout << "\n\t\t\tGame over\n";
  cout << "\nView score? (y/n)";
  bufd=getch();
  if (bufd=='y' || bufd=='Y')
  viewscore();
  getch();
  exit(0);
}

    attack(nummon);
     if (firstmon[nummon].health<=0) { cout << "\nMonster is dead\n"; iliya.exp+=firstmon[nummon].exp; iliya.kill++; break;}
  }
  }
  }
  cout << "\n\t\t\tGame over\n";
  cout << "\nView score? (y/n)";
  bufd=getch();
  if (bufd=='y' || bufd=='Y')
  viewscore();
  getch();
  return 0;
}
