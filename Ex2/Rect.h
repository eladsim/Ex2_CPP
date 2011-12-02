//Rect.h - Class Rectanlge

#ifndef _RECT_H_
#define _RECT_H_

#include <iostream>
#include "Point.h"

using namespace std;

class Rect
{
	Point m_point;	//point for a rectangle
	int m_length, m_width;	//length and width of a rectangle
	void drawRectFrame(char ch);
	void drawRectFill(char ch);
public:
	Rect();
	void setRect(int x, int y, unsigned int length, unsigned int width);
	void setRect(const Point point, unsigned int length, unsigned int width);
	void drawRect(char ch, bool isFullFilling);
	bool isPointInRect(const Point& point);
	bool isRect(const Point& point);
	void moveRectPoint(int incX, int incY);
	Rect(const Rect& rect);
	~Rect();
};

#endif

