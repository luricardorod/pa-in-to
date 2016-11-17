#pragma once
#include "cFiguras.h"
#define ClsId_TiraDeLinea 8
#include <vector>

class cTiraDeLinea:cFiguras
{
public:
	std::vector<Point> listaDePuntos;
	int GetClsId();
	cTiraDeLinea();
	~cTiraDeLinea();
};

