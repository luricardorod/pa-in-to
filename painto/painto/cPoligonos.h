#pragma once
#include "cFiguras.h"
#define ClsId_Polignos 5
#include <vector>

class cPoligonos:cFiguras
{
public:
	std::vector<Point> listaPuntos;
	int GetClsId();
	cPoligonos();
	~cPoligonos();
};

