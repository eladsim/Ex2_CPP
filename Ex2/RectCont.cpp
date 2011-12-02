#include "RectCont.h"

//pushes a rectangle to the containers
RectCont::RectCont()
{
	m_counter = 0;
}

//returns a pointer to the rectangle that includes the point, if not found returns NULL
Rect* RectCont::findRectIncludesPoint(const Point& point)
{
	list<Rect*>::iterator it = m_list.begin();

	while (it != m_list.end())
	{
		if ((*it)->isPointInRect(point))
			return (*it);
		else
			it++;
	}
	return NULL;
}

//adds rectangle to the end of the containe, gets point, width and length for addition
void RectCont::addRect(const Point& point, int length, int width)
{
	Rect* rect = new Rect;

	rect->setRect(point, length, width);
	m_list.push_back(rect);
}

//adds rectangle to the end of the container gets rectangle for addition
void RectCont::addRect(Rect& rect)
{
	m_list.push_back(&rect);
}

//removes rectangle acording to a point, returns true if the rectangle was found and deleted
bool RectCont::removeRect(const Point& point)
{
	list<Rect*>::iterator it = m_list.begin();
	bool isFound = false;

	while (!isFound && it!=m_list.end())
	{
		if ((*it)->isPointInRect(point))
		{
			delete *it;
			m_list.remove(*it);
			isFound = true;
		}
		else
			it++;
	}
	return isFound;	
}

//returns a pointer to the rectangle with the point, if not found returns NULL 
Rect* RectCont::findRect(const Point& point)
{
	list<Rect*>::iterator it = m_list.begin();

	while (it!=m_list.end())
	{
		if ((*it)->isRect(point))
			return (*it);
		else
			it++;
	}
	return NULL;
}

//shifts rectangle, gets a point and increments values for x and y, if succeed returns true
bool RectCont::shiftRect(const Point& point, int incX, int incY)
{
	Rect* foundRect = findRect(point);

	if (foundRect != NULL)
	{
		foundRect->moveRectPoint(incX, incY);
		return true;
	}
	else
		return false;
}

//brings the rectangle to the front by moving it to the end of the container, returns true for success
bool RectCont::bringRectToFront(const Point& point)
{
	list<Rect*>::iterator it = m_list.begin();
	Rect* ptr = NULL;

	while (it != m_list.end())
	{
		if ((*it)->isPointInRect(point))
		{
			m_list.push_back(*it);	//push the item to the end of the list
			ptr = (*it);
			m_list.remove(*it);
			m_list.push_back(ptr);
			return true;
		}
		else
			it++;
	}
	return false;
}

//brings the rectangle to the back by moving it to the beginning of the container, returns true for success
bool RectCont::bringRectToBack(const Point& point)
{
	list<Rect*>::iterator it = m_list.begin();
	Rect* ptr = NULL;

	while (it != m_list.end())
	{
		if ((*it)->isPointInRect(point))
		{
			ptr = (*it);
			m_list.remove(*it);
			m_list.push_front(ptr);
			return true;
		}
		else
			it++;
	}
	return false;
}

//prints all the rectangles acording to ch
void RectCont::drawAll(char ch, bool isFullFilling)
{
	list<Rect*>::iterator it = m_list.begin();

	clrscr();
	while (it != m_list.end())
	{
		(*it)->drawRect(ch, isFullFilling);
		it++;
	}
}

//prints all the rectangles acording to ch and prints a special rectangle acording chSpec, returns true if if the spcial rectangle is found
bool RectCont::drawAllExecptOneSpecial(const Point& point, char chAll, char chSpec, bool isFullFilling)
{
	bool isFoundRect = false;
	list<Rect*>::reverse_iterator rit = m_list.rbegin();;
	list<Rect*>::iterator it = m_list.begin();

	while (it != m_list.end())
	{
		(*it)->drawRect(chAll, isFullFilling);
		it++;
	}
	while (!isFoundRect && rit != m_list.rend())
	{
		if (isFoundRect = (*rit)->isPointInRect(point))
		{
			(*rit)->drawRect(chSpec, isFullFilling);
			isFoundRect = true;
		}
		else
			rit++;
	}
	return isFoundRect;
}

//empty destructor 
RectCont::~RectCont()
{
	list<Rect*>::iterator it = m_list.begin();

	while (it != m_list.end())
	{
		delete *it;
		it++;
	}
}

