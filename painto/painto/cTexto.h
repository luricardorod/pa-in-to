#pragma once
#include "cFiguras.h"

class cTexto:public cFiguras
{
public:
	string texto;
	Point p1, p2, p3, p4;
public:
	cTexto();
	cTexto(Point position, string tex);
	~cTexto();
	sf::Text cajaTexto;
	sf::Font fuente;

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	void Dibujar(sf::RenderWindow &Ventana);
	string info();

	virtual void setMove(float x, float y);
	virtual void setColor(sf::Color newColor);
	virtual sf::Color getColor();
};