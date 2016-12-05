#pragma once
#include "cFiguras.h"

class cTriangulo:public cFiguras
{
public:
	Point p1, p2, p3;
	sf::ConvexShape Triangulo;
public:
	cTriangulo();
	cTriangulo(Point p1, Point p2);
	~cTriangulo();

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	virtual void Dibujar(sf::RenderWindow &Ventana);
	string info();

};