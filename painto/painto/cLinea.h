#pragma once
#include "cFiguras.h"
#include "cLineType.h"

class cLinea:public cFiguras, public cLineType
{
public:
	cLinea();
	cLinea(Point p1, Point p2);
	~cLinea();
	
	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	virtual void Dibujar(sf::RenderWindow &Ventana);
	string info();
	virtual void setMove(float x, float y);
	virtual void setColor(sf::Color newColor);
};