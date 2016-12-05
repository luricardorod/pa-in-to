#pragma once
#include "cFiguras.h"
#include "cLineType.h"
#include <vector>

class cTiraDeLinea:public cFiguras, public cLineType
{
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
	
	void setMove(float x, float y);
	void setColor(sf::Color newColor);
	virtual sf::Color getColor();
};