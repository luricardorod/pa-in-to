#pragma once
#include "cFiguras.h"

class cCurvaBezier:public cFiguras
{
public:
	Point pInicio, pFinal, pAnclaje1, pAnclaje2;
public:
	cCurvaBezier();
	~cCurvaBezier();

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	virtual void Dibujar(sf::RenderWindow &Ventana);
};