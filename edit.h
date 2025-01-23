#include <windows.h>
#include <stdlib.h>

void gotoxy(int x, int y)
{
HANDLE hConsoleOutput;
COORD coord;
hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
coord.X = x; coord.Y = y;
SetConsoleCursorPosition (hConsoleOutput, coord);
}

void clrscr(void)
{system("cls");}

void textbackground(int c)
{SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),c*16);}

void textcolor(int t, int c)
{SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),(c*16)+t);}


void setcursortype(int x){
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO info;
switch(x)
{
case 0:info.bVisible = 0; break;
case 1:info.dwSize = 10; info.bVisible = 1; break;
case 2:info.dwSize = 100;info.bVisible = 1; break;
}

SetConsoleCursorInfo(consoleHandle, &info);}
