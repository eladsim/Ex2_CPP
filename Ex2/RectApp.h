//RectApp.h - Class RectangleApplication

#ifndef _RECTAPP_H_
#define _RECTAPP_H_

#include "Menu.h"
#include "Gotoxy.h"
#include "Point.h"
#include "RectCont.h"
#include <iostream>

using namespace std;

class RectApp
{
private:
	RectCont m_rectCont;
	Menu m_menu;	//main menu
	Menu m_subMenu;	//sub menu
	bool m_isDefaultFull;	//default type of the rectanlges
	void init();
	void addRect();
	void changeRectType();
	void subMenu(Point& point);
	void markRect();
	void clearReadBuffer();
public:
	RectApp();
	void runRectApp();
	RectApp(const RectApp& rectApp);
	~RectApp();
};

#endif

