#pragma once
#include "cFiguras.h"
#include <vector>
#define Pi 3.14159285

class cPoligonos :public cFiguras
{
public:
	vector<Point> listaPuntos;
	sf::ConvexShape figura;
public:
	cPoligonos();
	cPoligonos(int lados);
	~cPoligonos();

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	virtual void Dibujar(sf::RenderWindow &Ventana);

	virtual void setPosicion(Point coordenadas);
	virtual void setColorLinea(Vector3f nuevoColor);
	virtual void setColorRelleno(Vector3f nuevoColor);

	string info();
};