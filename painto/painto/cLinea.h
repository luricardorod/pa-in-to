#pragma once
#include "cFiguras.h"

class cLinea:public cFiguras
{
public:
	Point p1, p2;
	sf::VertexArray lines;
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

};