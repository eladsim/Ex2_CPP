#include "Rect.h"

//constructor for rectangle
Rect::Rect()
{
	m_length = 0;	//zeroing length
	m_width = 0;	//zeroing width
}

//draws the frame of a rectangle
void Rect::drawRectFrame(char ch)
{
	for (int i=0; i<m_width; i++)	//drawing first row of the frame
		m_point.drawPoint(ch, i, 0);
	for (int i=1; i<m_length; i++)	//drawing the middle rows of the frame
	{
		m_point.drawPoint(ch, 0, i);
		m_point.drawPoint(ch, m_width-1, i);
	}
	for (int i=0; i<m_width; i++)	//drawing last row of the frame
		m_point.drawPoint(ch, i, m_length-1);
}

//fills the rectangle frame
void Rect::drawRectFill(char ch)
{
	for (int i=1; i<m_length-1; i++)	//drawing the middle rows of the fill
		for (int j=1; j<m_width-1; j++)
			m_point.drawPoint(ch, j, i);
}

//draws a recangle: empty or full
void Rect::drawRect(char ch, bool isFullFilling)
{
	drawRectFrame(ch);
	if (isFullFilling)
		drawRectFill(' ');
}

//checks if a point is in the point of a rectangle
bool Rect::isPointInRect(const Point& point)
{
	Point l_point = point;
	if (((l_point.getX() >= m_point.getX()) && (l_point.getX() <= (m_point.getX() + (m_width - 1)))) &&
		((l_point.getY() >= m_point.getY()) && (l_point.getY() <= (m_point.getY() + (m_length - 1)))))
		return true; 
	else
		return false;
}

//sets rectangle values by x, y, length, width
void Rect::setRect(int x, int y, unsigned int length, unsigned int width)
{
	m_point.setPoint(x, y);
	m_length = length;
	m_width = width;
}

//sets rectangle values by point, length, width
void Rect::setRect(Point point, unsigned int length, unsigned int width)
{
	m_point.setPoint(point.getX(), point.getY());
	m_length = length;
	m_width = width;
}

//moves rectangle accoring increments values for x and y
void Rect::moveRectPoint(int incX, int incY)
{
	m_point.movePoint(incX, incY);
}

//checks if the rectangle defineds by the point, returns true if the rectangle is defined by the point
bool Rect::isRect(const Point& point)
{
	Point l_point = point;

	if ((m_point.getX() == l_point.getX()) && (m_point.getY() == l_point.getY()))
		return true;
	else
		return false;
}

//copy constaructor for rectangle
Rect::Rect(const Rect& rect)
{
	m_point = rect.m_point;
	m_length = rect.m_length;
	m_width = rect.m_width;
}

//empty desecrator for rectangle
Rect::~Rect()
{
}

