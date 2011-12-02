#include "Point.h"

//constructor zeros the x,y values
Point::Point()
{
	m_x = 0;
	m_y = 0;
}

//sets x.y values
void Point::setPoint(int x, int y)
{
	m_x = x;
	m_y = y;
}

//draws a point to the screen according to the input char
void Point::drawPoint(char ch)
{
	if ((m_x >= 0 && m_x <= LAST_CLUMN) && (m_y >=0 && m_y <= LAST_ROW))
	{
		gotoxy(m_x, m_y);
		cout << ch;
		cout.flush();
	}
}

//draws a point acording to the right character
void Point::drawPoint(char ch, int incX, int incY)
{
	if ((m_x + incX >= 0 && m_x + incX <= LAST_CLUMN) && (m_y + incY >=0 && m_y + incY <= LAST_ROW))
	{
		gotoxy(m_x + incX, m_y + incY);
		cout << ch;
		cout.flush();
	}
}

// Function returns the value of x
int Point::getX()
{
	return m_x;
}

// Function returns the value of y
int Point::getY()
{
	return m_y;
}

//moves a point acording to an increment values for x and y
void Point::movePoint(int incX, int incY)
{
	m_x += incX;
	m_y += incY;
}

//copy constructor for point
Point::Point(const Point& point)
{
	m_x = point.m_x;
	m_y = point.m_y;
}

//destruSctor - empty
Point::~Point()
{
}