#include "Menu.h"
#include <conio.h>

//prints the menu options
void Menu::printMenu()
{
	for (unsigned int i=0; i<m_numOptions; i++)
		cout << i+1 << "> " << m_optionsText[i] << endl;
	cout << "Please enter your choice: ";
}

//prints message for too many rectangles
void Menu::printTooManyRects()
{
	cout << "Too many rectangles! Please delete rectangles to continue adding new rectangles." << endl ;
}

//allocates the strings array for options
void Menu::init(unsigned int numOptions)
{
	m_numOptions = numOptions;
	m_optionsText = new string [numOptions];
}

//sets an option text to the right place in the menu array
void Menu::set(unsigned int optionNum, const string &optionText)
{
	if(optionNum > m_numOptions)
		cout << "Invalid entry, number entered too high";
	else
		m_optionsText[optionNum] = optionText;
}

//returns the num of options
unsigned int Menu::getNumOfOptions()
{
	return m_numOptions;
}

//calls printMenu and get the choice from the user
unsigned int Menu::getChoice()
{
	unsigned int choice = NULL;

	cin >> choice;
	while (choice > m_numOptions || choice < 0) // while choice is out of range
	{
		cout << endl << "Invalid option! Please choose an option between 1 and " << m_numOptions << endl;
		cout << "press any key to return the main menu" << endl;
		_getch();
		clrscr();
		printMenu();
		cin >> choice;
	}
	return choice;
}

//menu constructor zeros all the attributes
Menu::Menu()
{
	m_numOptions = NULL;
	m_optionsText = NULL;
}

//menu destructor frees the strings array
Menu::~Menu()
{
	delete []m_optionsText;	//delete the strings of the string array
}



