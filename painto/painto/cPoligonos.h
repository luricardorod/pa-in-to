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

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	void Dibujar();
};