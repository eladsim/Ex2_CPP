/***************************************
  Credit for finding this code goes to:
          Yoav  Aharoni
      [yoav_ah@netvision.net.il]
***************************************/

#include "Gotoxy.h"

// function definition -- requires windows.h
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

// function definition -- requires process.h
void clrscr()
{
	system("cls");
}