#pragma once
#include "cRectangulo.h"

class cRectanguloRedondeado:public cRectangulo
{
public:
	float radio;
	sf::ConvexShape RectRedondeado;
public:
	cRectanguloRedondeado();
	~cRectanguloRedondeado();

	virtual void setColorLinea(Vector3f nuevoColor);
	virtual void setColorRelleno(Vector3f nuevoColor);

	Vector3f getColorLinea();


	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	void Dibujar();
	string info();

};