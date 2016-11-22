#pragma once
#include "cFiguras.h"
#define ClsId_CurvaBezier 6

class cCurvaBezier:cFiguras
{
public:
	Point pInicio, pFinal, pAnclaje1, pAnclaje2;
	int GetClsId();
	cCurvaBezier();
	~cCurvaBezier();
	void Guardar(ofstream & salida);
	void Cargar(ifstream & entrada);
};