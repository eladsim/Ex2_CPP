//Point.h - Class point

#ifndef _POINT_H_
#define _POINT_H_

#define LAST_ROW 24
#define LAST_CLUMN 79

#include <iostream>
#include "Gotoxy.h"

using namespace std;

class Point
{
private:
	int m_x, m_y;	//x,y - coordinates for a point
public:
	Point();
	void setPoint(int x, int y);
	int getX();
	int getY();
	void drawPoint(char ch, int incX, int incY);
	void drawPoint(char ch);
	void movePoint(int incX, int incY);
	Point(const Point& point);
	~Point();
};

#endif

