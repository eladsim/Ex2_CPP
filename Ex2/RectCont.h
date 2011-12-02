//RectCont.h - Class RectCont

#ifndef _RECTCONT_H_
#define _RECTCONT_H_

#include "Point.h"
#include "Rect.h"
#include <list>

using namespace std;

class RectCont
{
private:
	list<Rect*> m_list;	//list of pointer to rectangles
	int m_counter;
public:
	RectCont();
	Rect* findRectIncludesPoint(const Point& point);
	Rect* findRect(const Point& point);
	bool removeRect(const Point& point);
	void addRect(const Point& point, int length, int width);
	void addRect(Rect& rect);
	bool shiftRect(const Point& point, int incX, int incY);
	bool bringRectToFront(const Point& point);
	bool bringRectToBack(const Point& point);
	void drawAll(char ch, bool isFull);
	bool drawAllExecptOneSpecial(const Point& point, char chAll, char chSpec, bool isFullFilling);
	RectCont(RectCont& rect);
	~RectCont();
};

#endif

