#pragma once
#include "cFiguras.h"

class cElipse :public cFiguras
{
public:
	float radio1, radio2;
	sf::ConvexShape Elipse;
public:
	cElipse();
	~cElipse();
	
	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	virtual void Dibujar(sf::RenderWindow &Ventana);
	string info();

};