#pragma once
#include "cRectangulo.h"

class cRectanguloRedondeado:public cRectangulo
{
public:
	float radio;
	sf::ConvexShape rectanguloC;
public:
	cRectanguloRedondeado();
	cRectanguloRedondeado(Point p1, Point p2);
	~cRectanguloRedondeado();

	virtual void setColorLinea(Vector3f nuevoColor);
	virtual void setColorRelleno(Vector3f nuevoColor);

	Vector3f getColorLinea();


	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	string info();

	virtual void Dibujar(sf::RenderWindow &Ventana);
};