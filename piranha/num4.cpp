//-------------Тестовая версия программы-аналога "Пиранья"-------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/* обявления глобальных констант и переменных */

const char filename[]="users.lib"; //главный файл Базы Данных
const char tempfile[]="old.lib";   //временный свап-файл Базы Данных
int errstat=0;                     //переменная для сообщения ошибок исполнения
int temphone;                      //переменная для регистрации в системе (логин)
int tempweight=0;                  //переменная для вывода главного значения (параметра веса лидера)
char tempchat[61];                 //свап-переменная для хранения сообщения игрока
char temptalk[21];                 //свап-переменная для индентификации игрока для отправки сообщения
char tempname[21];                 //переменная для вывода имени значения (параметра имени лидера)

struct unit {     //инициализация структура Базы Данных
int phone;        //переменная номера телефона ---!!!---пока только 7 цифр---!!!---
int weight;       //переменная главного значения (веса)
int status;       //переменная статуса (для обработки событий сервером)
int answer;       //переменная статуса отклика (для обработки событий игроком)
char name[21];    //имя игрока
char enemy[21];   //имя противника/собеседника
char chat[61];    //текущее состояния сообщения
} user;

rewrite() //функция записи в БД (обновление)
{
int k1, k2;                          //параметр, сличающий правильность данных
ifstream r;                     //чтение файла
ofstream w;                     //запись в файл (методом добавления)
r.open(filename);               //чтение из основного файла БД
if(!r)
{
cout << "Error open file";
getch();
exit(1);
}
w.open(tempfile, ios::app);     //запись во временный файл
if(!w)
{
cout << "Error open file";
getch();
exit(1);
}
w << "0 0 0 0 0 0 0\n";         //нулевая строчка (начало БД)
w << user.phone << " " << user.weight << " " << user.status << " " << user.answer << " " << user.name << " " << user.enemy << " " << user.chat << " " <<endl;
while (!r.eof())
{
strcpy(tempname, user.name);   //копируется в свап последнее используемое имя
r >> user.phone >> user.weight >> user.status >> user.answer >> user.name >> user.enemy >> user.chat;
k1=strcmp(temptalk, user.name);
k2=strcmp(tempname, user.name); //сверяется, существует ли это имя
if (user.phone==0) k1=0;        //проверка на нули (на начало файла или ошибку исполнения)
if (k1!=0 && k2!=0)                      //проверка параметра
w << user.phone << " " << user.weight << " " << user.status << " " << user.answer << " " << user.name << " " << user.enemy << " " << user.chat << " " <<endl;
}
r.close();
w.close();
ofstream f;                     //удаление содержимого файла
f.open(filename,ios::trunc);    //удаление исходной БД
if(!f)
{
cout << "Error open file";
getch();
exit(1);
}
f.close();
r.open(tempfile);               //чтение из временного файла
if(!r)
{
cout << "Error open file";
getch();
exit(1);
}
w.open(filename, ios::app);     //запись в основной файл БД
if(!w)
{
cout << "Error open file";
getch();
exit(1);
}
w << "0 0 0 0 0 0 0\n";         //нулевая строчка (начало БД)
while (!r.eof())
{
strcpy(tempname, user.name);
r >> user.phone >> user.weight >> user.status >> user.answer >> user.name >> user.enemy >> user.chat;
k2=strcmp(tempname, user.name); //сверяется, существует ли это имя
if (user.phone==0) k2=0;
if (k2!=0)
w << user.phone << " " << user.weight << " " << user.status << " " << user.answer << " " << user.name << " " << user.enemy << " " << user.chat << " " <<endl;
}
r.close();
w.close();
f.open(tempfile,ios::trunc);     //удаление содержимого временного файла
if(!f)
{
cout << "Error open file";
getch();
exit(1);
}
f.close();
return 0;
}

sentmes()  //отправка сообщению другому игроку
{
strcpy(tempname, user.name);    //имя текущего игрока копируется в свап
int k=0;                        //параметр, сличающий правильность данных
errstat=0;                      //обнуление переменной для сообщения ошибок исполнения
cout << "Choose companion: "; cin >> temptalk;   //запрос имени игрока, которому посылается сообщение
cout << "\nWhat do you want to say to " << temptalk << "? Max 60 simbols\n"; cin >> tempchat; //запрос самого сообщения (ограничено 60 символами)
/* в нашем случае используются два разных потока
   в общем случае, предпологается обрабатывать поток за один раз
   ---!!!---ВНИМАНИЕ---!!!---
   все слова следует писать без пробела, заменяя его "_"
   скоро это проблема будет решена для удобства пользователей
   ---!!!---ВНИМАНИЕ---!!!--- */
ifstream r;                     //поток чтения из БД
r.open(filename);               //чтение из БД
if(!r)
{
cout << "Error open file. Programm terminated.";
getch();
exit(1);
}
while (!r.eof() || errstat!=0) //До конца БД или до обнаружения записи
{
k = 0;
r >> user.phone >> user.weight >> user.status >> user.answer >> user.name >> user.enemy >> user.chat;
k=strcmp(temptalk, user.name); //сравнение текущей переменной и свап-значения
if (k==0)
{
errstat++;                     //если обнаружено, то вызывается параметр, завершающий цикл
break;
}
}
if (k!=0) exit(1);
r.close();
user.answer=9;                //вызывается код отклика для нового игрока
strcpy(user.enemy, tempname); //в поля сообщения вызываемого игрока копируются данные,
strcpy(user.chat, tempchat);  //сообщенные текущим игроком
return 0;
}

readbase() //чтение из БД и установка значений для текущего игрока
{
errstat = 0;
ifstream r;                     //поток чтения БД
r.open(filename);
if(!r)
{
cout << "Error open file. Programm terminated.";
getch();
exit(1);
}
while (!r.eof() || errstat!=0)
{
r >> user.phone >> user.weight >> user.status >> user.answer >> user.name >> user.enemy >> user.chat;
//cout << "User phone: "<< user.phone << "\nUser weight: " << user.weight << "\nUser status: " << user.status << "\nUser answer: " << user.answer << "\nUser name: " << user.name << "\n";
if (temphone==user.phone)       //сравнение записей в БД с уникальным кодом (телефоном) игрока
{
errstat++;
break;
}
}
r.close();
return 0;
}

newbase() //создание записи в БД о новом игроке
{
ofstream w;
w.open(filename, ios::app); //добавление записи в конец БД
if(!w)
{
cout << "Error open file. Programm terminated.";
getch();
exit(1);
}
user.phone=temphone; //
user.weight=10;      // параметры
user.status=0;       //  по
user.answer=0;       //   умолчанию
user.enemy[0]='\0';  //
user.chat[0]='\0';   //
cout << "\nUser name: "; cin >> user.name; //задание игроку нового имени
/* ---!!!---ВНИМАНИЕ---!!!---
пока в программе не предусмотрено сличение по
именам и присваивании каждому игроку уникального имени
---!!!---ВНИМАНИЕ---!!!--- */
w << user.phone << " " << user.weight << " " << user.status << " " << user.answer << " " << user.name <<  " " << user.enemy << " " << user.chat <<"\n";
w.close();
exit(1);
return 0;
}

auth() //регистрация игрока в системе
{
readbase();     //вызов просмотра БД
if (errstat==0) //если не найдено
newbase();      //вызывается регистрация
return 0;
}

viewself()     //просмотр татистики текущего игрока !!!---С системными значениями---!!!
{
cout << "\n\nUser phone: "<< user.phone << "\nUser weight: " << user.weight << "\nUser status: " << user.status << "\nUser answer: " << user.answer << "\nUser name: " << user.name << "\nUser enemy: " << user.enemy << "\nUser chat: " << user.chat <<"\n";
getch();
return 0;
}


viewlider()  //просмотр лидера ---!!!---пока только первый---!!!---
{
ifstream r;        //чтение из БД
r.open(filename);
if(!r)
{
cout << "Error open file. Programm terminated.";
getch();
exit(1);
}
while (!r.eof()) //просматривается все до конца
{
r >> user.phone >> user.weight >> user.status >> user.answer >> user.name >> user.enemy >> user.chat;
if (tempweight<user.weight)
{
tempweight=user.weight;         //свап-значениям
strcpy(tempname, user.name);    //присваиваются значения лидера
}
}
r.close();
cout << "\n\nCurrent lider " << tempname << " with " << tempweight << " weight\n"; //вывод статистики
getch();
exit(1);
return 0;
}

menu() //главное меню управления операциями
{
char buf;
cout << "\n\nEnter operation:\nS: Sleep\nH: Hunt\nD: Defend\nR: Rating\nV: View self\nC: Chat\n";
cin >> buf;
switch(buf)
{
case 'S':          //устанавливается режим, в котором сервер в течение времени прибавляет вес (рост)
user.status=0;
break;
case 'H':          //устанавливается режим, в котором идет обращение к серверу на запрос охоты
user.status=3;
break;
case 'D':         //устанавливается режим защиты (без роста но с коэффицентом защиты)
user.status=2;
break;
case 'R':         //просмотр лидера
viewlider();
break;
case 'V':         //просмотр собственной статистики
viewself();
break;
case 'C':         //отправка сообщения другому игроку
sentmes();
break;
}
rewrite();
return 0;
}

revstat() //функция обработки событий игроком
{
if (user.answer==3)
 {
 cout << "You have been attacked " << user.enemy << ".\nResult: you defeated";
 user.answer=0;
 }
if (user.answer==2)
 {
 cout << "You have been attacked " << user.enemy << ".\nResult: you win";
 user.answer=0;
 }
if (user.answer==1)
 {
 cout << "You have been attacked " << user.enemy << ".\nResult: draw";
 user.answer=0;
 }
if (user.answer==6)
 {
 cout << "You attack " << user.enemy << ".\nResult: you defeated";
 user.answer=0;
 }
if (user.answer==5)
 {
 cout << "You attack " << user.enemy << ".\nResult: you win";
 user.answer=0;
 }
if (user.answer==4)
 {
 cout << "You attack " << user.enemy << ".\nResult: draw";
 user.answer=0;
 }
if (user.answer==9)
 {
 cout << endl << user.enemy << " said: \"" << user.chat << "\"";
 user.answer=0;
 rewrite();
 getch();
 exit(1);
 }
return 0;
}

main() //главная программа с вызовом регистрации, обработки событий и меню
{
cout << "Enter your phone number: "; cin >> temphone;
auth();
revstat();
menu();
return 0;
}

