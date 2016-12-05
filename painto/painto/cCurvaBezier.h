#pragma once
#include "cFiguras.h"

class cCurvaBezier:public cFiguras
{
public:
	sf::Vector2f pInicio, pFinal, pAnclaje1, pAnclaje2;
public:
	cCurvaBezier();
	~cCurvaBezier();

	bool adCosa(Point nP);

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	virtual void Dibujar(sf::RenderWindow &Ventana);
	string info();
};