//Menu.h - Class Menu

#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <string>
#include "Gotoxy.h"

using namespace std;

class Menu
{
private:
	unsigned int m_numOptions;	//number of menu options
	string* m_optionsText;	//pointer for strings array of options
public:
	Menu();
	void init(unsigned int numOptions);
	void set(unsigned int optionNum, const string &optionText);
	unsigned int getNumOfOptions();
	unsigned int getChoice();
	void printTooManyRects();
	void printMenu();
	Menu(const Menu& menu);
	~Menu();
};


#endif