#pragma once
#include "cFiguras.h"
#include <vector>

class cTiraDeLinea:public cFiguras
{
public:
	vector<Point> listaDePuntos;
public:
	cTiraDeLinea();
	~cTiraDeLinea();

	void setColorLinea(Vector3f nuevoColor);
	Vector3f getColorLinea();

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	void Dibujar();
};