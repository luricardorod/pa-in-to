#pragma once
#include "cFiguras.h"
#include <vector>

class cPoligonos :public cFiguras
{
public:
	vector<Point> listaPuntos;
public:
	cPoligonos();
	~cPoligonos();

	void setColorLinea(Vector3f nuevoColor);
	Vector3f getColorLinea();

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	void Dibujar();
};