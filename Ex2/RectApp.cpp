#include "RectApp.h"
#include <conio.h>

//constructor
RectApp::RectApp()
{
	m_isDefaultFull = true; //default value - full rectangles
	init();
}

//initializes the menus for the rectangle application
void RectApp::init()
{
	//main menu initialize
	m_menu.init(9);
	m_menu.set(0, "Add a rectangle");
	if (m_isDefaultFull)
	{
		m_menu.set(1, "Draw full rectangles");
		m_menu.set(2, "Change default to drawing empty rectangles");
	}
	else
	{
		m_menu.set(1, "Draw empty rectangles");
		m_menu.set(2, "Change default to drawing full rectangles");
	}
	m_menu.set(3, "Choose a rectangle");
	m_menu.set(4, "Display animation with flowing across the screen sides");
	m_menu.set(5, "Display animation with collisions");
	m_menu.set(6, "For future use");
	m_menu.set(7, "For future use");
	m_menu.set(8, "Exit");
	//sub menu initialize
	m_subMenu.init(6);
	m_subMenu.set(0, "Return to main menu");
	m_subMenu.set(1, "Delete selected rectangle");
	m_subMenu.set(2, "Send selected rectangle to front");
	m_subMenu.set(3, "Send selected rectangle to background");
	m_subMenu.set(4, "Shift selected rectangle");
	m_subMenu.set(5, "Add animation");
}

//adds rectangle to the container (includes the input of the values and output message)
void RectApp::addRect()
{
	Point point;
	int x, y, length, width;

	cout << "Please enter a rectangle point - X Y: " << endl;
	cin >> x;
	cin >> y;
	cout << "Please enter the rectangle length and width - must be natural numbers: " << endl;
	cin >> length;
	cin >> width;
	while (length < 0 && width < 0)
	{
		cout << endl << "Invalid values! please enter only natural numbers for length and width" << endl << endl;
		clearReadBuffer();
		cout << "Please enter a rectangle point - X Y: " << endl;
		cin >> x;
		cin >> y;
		cout << "Please enter the rectangle length and width - must be natural numbers: " << endl;
		cin >> length;
		cin >> width;
	}
	point.setPoint(x, y);
	m_rectCont.addRect(point, length,  width);
}

//changes the default type of rectangles: full<->empty
void RectApp::changeRectType()
{
	m_isDefaultFull = !m_isDefaultFull;
	if (m_isDefaultFull)
	{
		m_menu.set(1, "Draw full rectangles");
		m_menu.set(2, "Change default to drawing empty rectangles");
	}
	else
	{
		m_menu.set(1, "Draw empty rectangles");
		m_menu.set(2, "Change default to drawing full rectangles");
	}
}

//prints and manage the sub menu for selected rectnagle
void RectApp::subMenu(Point& point)
{
	bool shouldExit = false;
	unsigned int choice = NULL;
	int incX, incY;

	cout << endl;
	while (!shouldExit)
	{
		clrscr();
		m_subMenu.printMenu();
		clearReadBuffer();
		choice = m_subMenu.getChoice();
		switch(choice)
		{
			case 1: //returns to main menu
				shouldExit = true;
				break;
			case 2: //delete the retangle
				m_rectCont.removeRect(point);
				shouldExit = true;
				break;
			case 3:	//brings the selected rectangle to front
				m_rectCont.bringRectToFront(point);
				shouldExit = true;
				break;
			case 4:	//brings the selected rectangle to back
				m_rectCont.bringRectToBack(point);
				shouldExit = true;
				break;
			case 5:
				cout << "Please enter the increment values for the selected rectangle - X Y" << endl;
				cin >> incX;
				cin >> incY;
				m_rectCont.shiftRect(point, incX, incY);
				shouldExit = true;
				break;
			default:
				cout << endl << "Please enter a valid option!" << endl;
				gotoxy(0, 24);  //go to the last line of the screen
				cout << "press any key to continue";
				_getch();
				break;
		}
	}
	if (choice != 1)
	{
		gotoxy(0, 24);  //go to the last line of the screen
		cout << "press any key to continue";
		_getch();
		
	}
}

//gets the point for marking a rectangle and draws the rectangles acoridng to the selected rectnagle
void RectApp::markRect()
{
	int x, y;
	Point point;
	Rect* foundRect = NULL;

	cout << "Please enter a rectangle point for selection - X Y: " << endl;
	cin >> x;
	cin >> y;
	point.setPoint(x,y);
	clrscr();
	if (foundRect = m_rectCont.findRectIncludesPoint(point))
	{
		m_rectCont.drawAllExecptOneSpecial(point, '*', '+', m_isDefaultFull);
	}
	else
	{
		gotoxy(0, 1); //go to the last line of the screen
		cout << "There was no rectangle that includes the point: " << x << " , " << y << "!" << endl
			<< "press any key to continue" << endl;
		m_rectCont.drawAll('@', m_isDefaultFull);
	}
	point.drawPoint('@');
	_getch();
	if (foundRect != NULL)
		subMenu(point);
}

//clrears the buffer of cin in stdio
void RectApp::clearReadBuffer()
{
	if (!cin)	//in a case of junk in cin buffer
	{
		cin.clear();	//clears cin buffer
		string ignoreLine; //read the invalid input into it
		getline(cin, ignoreLine); //read the line till next space
	}
}

//runs the application
void RectApp::runRectApp()
{
	bool shouldExit = false;
	unsigned int choice = NULL;

	while (!shouldExit)
	{
		clrscr();
		m_menu.printMenu();	//prints the main menu
		clearReadBuffer();
		choice = m_menu.getChoice();
		cout << endl;
		switch (choice)
		{
			case 1: // add Rectangle
				addRect();
				m_rectCont.drawAll('*', m_isDefaultFull);
				break;
			case 2: // draw all Rectangles
				m_rectCont.drawAll('*', m_isDefaultFull);
				break;
			case 3: // change Default Type
				changeRectType();
				break;
			case 4: // enter Sub - Menu
				markRect();
				break;
			case 9: //exit
				shouldExit = true;
				break;
			default:	
				if (choice > 4 && choice <9)	//for the futue options: 5-8
					cout << "This option is for future use, please choose another option!" << endl;
				else
				{
					cout << endl << "Please enter a valid option!" << endl;
				}
				gotoxy(0, 24);  //go to the last line of the screen
				cout << "press any key to continue";
				_getch();
				break;
		}
		if (choice > 0 &&choice < 3)
		{
			gotoxy(0, 24);  //go to the last line of the screen
			cout << "press any key to return the main menu";
			clearReadBuffer();
			_getch();
		}
	}
	cout << endl << endl;
}

//empty copy constructor
RectApp::RectApp(const RectApp& rectApp)
{
}

//empty destructor
RectApp::~RectApp()
{
}


