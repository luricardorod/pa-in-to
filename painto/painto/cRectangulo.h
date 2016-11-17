#pragma once
#include "cFiguras.h"
#include "CDibujable.h"
#define ClsId_Rectangulo 1

class cRectangulo:public cFiguras
{
public:
	int GetClsId();
	cRectangulo();
	~cRectangulo();
};

