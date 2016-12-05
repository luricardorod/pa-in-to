#pragma once
#include "cFiguras.h"
#include <vector>

class cTiraDeLinea:public cFiguras
{
public:
	vector<Point> listaDePuntos;
	sf::VertexArray lines;
	int sizeze = 0;
public:
	cTiraDeLinea();
	~cTiraDeLinea();

	void addPointu(Point nP);

	void setColorLinea(Vector3f nuevoColor);
	Vector3f getColorLinea();

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	virtual void Dibujar(sf::RenderWindow &Ventana);
	string info();

};