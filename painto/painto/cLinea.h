#pragma once
#include "cFiguras.h"
#define ClsId_Linea 7

class cLinea:cFiguras
{
public:
	Point p1, p2;
	int GetClsId();
	cLinea();
	~cLinea();
};

