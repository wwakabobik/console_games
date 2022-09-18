//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream.h>
#include <stdio.h>
#include <conio.h>

//---------------------------------------------------------------------------

struct param
{
int str;
int agi;
int vit;
int dex;
int luck;
int hp;
int hpNOW;
int weapon;
int exp;
int level;
int points;
} user, monster;


void calcHPuser(void)
{
user.hp=(2*user.vit+user.level*2)-2;
}

void calcHPmonster(void)
{
monster.hp=(2*monster.vit+monster.level*2)-2;
monster.hpNOW=monster.hp;
}

void InitMonster(void)
{
monster.str=user.str+random(random(user.luck/5+2)-user.luck/5+1)-2;
monster.agi=user.agi+random(random(user.luck/5+2)-user.luck/5+1)-2;
monster.dex=user.dex+random(random(user.luck/5+2)-user.luck/5+1)-2;
monster.vit=user.vit+random(random(user.luck/5+2)-user.luck/5+1)-2;
monster.luck=user.luck+random(random(user.luck/5+2)-user.luck/5+1)-2;
monster.level=user.level;
calcHPmonster();
}

void InitPers(void)
{
user.str=5;
user.agi=5;
user.vit=5;
user.dex=5;
user.luck=5;
user.weapon=0;
user.exp=0;
user.level=1;
user.points=50;
calcHPuser();
user.hpNOW=user.hp;
}

void AddStat(void)
{
cout << "\nFree Points: "<< user.points <<
"\n1. Str: " << user.str << "\\" << user.str/5+1 <<
"\n2. Agi: " << user.agi << "\\" << user.agi/5+1 <<
"\n3. Dex: " << user.dex << "\\" << user.dex/5+1 <<
"\n4. Vit: " << user.vit << "\\" << user.vit/5+1 <<
"\n5. Luck: " << user.luck << "\\" << user.luck/5+1 << endl;
char value='0';
value=getch();
switch(value)
{
	case '1':
	if (user.points>=(user.str/5+1)) {
	user.points-=user.str/5+1;
	user.str++;
	}
	break;
	case '2':
	if (user.points>=(user.agi/5+1)) {
	user.points-=user.agi/5+1;
	user.agi++;
	}
	break;
	case '3':
	if (user.points>=(user.dex/5+1)) {
	user.points-=user.dex/5+1;
	user.dex++;
	}
	break;
	case '4':
	if (user.points>=(user.vit/5+1)) {
	user.points-=user.vit/5+1;
	user.vit++;
	}
	break;
	case '5':
	if (user.points>=(user.luck/5+1)) {
	user.points-=user.luck/5+1;
	user.luck++;
	}
	break;
}
}

void ShowStatUser(void)
{
cout << "\nStr: " << user.str << "\nAgi: " << user.agi << "\nDex: " << user.dex << "\nVit: " << user.vit << "\nLuck: " << user.luck << "\n HP:" << user.hpNOW << "\\" << user.hp << "\n Exp: " << user.exp << "\n FreePoints: " << user.points << "\n Level: " << user.level;
}

void ShowStatMonster(void)
{
cout << "\nStr: " << monster.str << "\nAgi: " << monster.agi << "\nDex: " << monster.dex << "\nVit: " << monster.vit << "\nLuck: " << monster.luck << "\n HP:" << monster.hpNOW << "\\" << monster.hp << "\n Exp: " << monster.exp << "\n FreePoints: " << monster.points << "\n Level: " << monster.level;
}

void battle(void)
{
int damage;
InitMonster();
cout << "\n\nMonster's Stat: \n";
ShowStatMonster();
//getch();
randomize();
while (user.hpNOW>0 && monster.hpNOW>0)
	{
		damage=monster.str*user.level-random(user.weapon+1)+random(user.weapon+1);
//cout << "\n\n" << user.agi/2-monster.dex*random(user.luck/5+1) << "\n\n";
		if ((user.agi/2-monster.dex*random(user.luck/5+1))<=0)
		{
		user.hpNOW+=user.vit/2-damage;
		cout << "\nMonster: " << damage-user.vit/2;
		}
		else cout << "\nMonster: miss";
		damage=user.str*monster.level-random(monster.weapon+1)+random(monster.weapon+1);
		if ((monster.agi/2-user.dex*random(monster.luck/5+1))<=0)
		{
		monster.hpNOW+=monster.vit/2-damage;
		cout << "\nUser: " << damage-monster.vit/2;
		}
		else cout << "\nUser: miss";
	}
	if (user.hpNOW<=0) {
	cout << "You die!";
	}
	else "You win!";
}

#pragma argsused
int main(int argc, char* argv[])
{
randomize();
InitPers();
ShowStatUser();
char control='0';
while (control!='~')
{
cout << "\n\nContinue to set points?\n";
AddStat();
control=getch();
}
cout << endl;
ShowStatUser();
battle();
ShowStatUser();
getch();
	return 0;
}
//---------------------------------------------------------------------------
