#pragma once
#include "cFiguras.h"

class cRectangulo:public cFiguras
{
public:
	float base, altura;
	sf::RectangleShape Rectangulo;
public:
	cRectangulo();
	cRectangulo(Point p1, Point p2);
	~cRectangulo();

	virtual bool hitTest(Point mouseCoords);

	virtual void Guardar(ofstream &salida);
	virtual void Cargar(ifstream &entrada);
	virtual int GetClsId();
	virtual void Dibujar(sf::RenderWindow &Ventana);

	virtual void setPosicion(Point coordenadas);
	virtual void setColorLinea(Vector3f nuevoColor);
	virtual void setColorRelleno(Vector3f nuevoColor);
};