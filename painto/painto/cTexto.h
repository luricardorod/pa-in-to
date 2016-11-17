#pragma once
#include "cFiguras.h"
#define ClsId_Texto 9

class cTexto:cFiguras
{
public:
	Point p1, p2, p3, p4;
	int GetClsId();
	cTexto();
	~cTexto();
};

