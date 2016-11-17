#pragma once
#include "cFiguras.h"
#include "CDibujable.h"
#define ClsId_Rectangulo 1

class cRectangulo:public cFiguras
{
public:
	Point p1, p2, p3, p4;
	int GetClsId();
	cRectangulo();
	~cRectangulo();
};

