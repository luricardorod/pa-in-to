#pragma once
#include "cFiguras.h"
#include <vector>

class cPoligonos :public cFiguras
{
public:
	vector<Point> listaPuntos;
	sf::ConvexShape Poligono;
public:
	cPoligonos();
	~cPoligonos();

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	virtual void Dibujar(sf::RenderWindow &Ventana);
	string info();

};