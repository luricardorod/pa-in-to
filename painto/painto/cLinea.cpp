#include "stdafx.h"
#include "cLinea.h"
#include <string>


int cLinea::GetClsId()
{
	return ClsId_Linea;
}

cLinea::cLinea()
{
}

cLinea::cLinea(Point p1, Point p2)
{
	lines.setPrimitiveType(sf::Lines);
	lines.clear();
	lines.resize(2);

	lines[0].position = sf::Vector2f(p1.x, p1.y);
	lines[1].position = sf::Vector2f(p2.x, p2.y);
	lines[0].color = sf::Color::Black;
	lines[1].color = sf::Color::Black;
}

cLinea::~cLinea()
{
}

void cLinea::Dibujar(sf::RenderWindow &Ventana)
{
	Ventana.draw(lines);
}

bool cLinea::hitTest(Point mouseCoords)
{
	return false;
}

void cLinea::Guardar(ofstream &salida)
{
	salida << p1.x << endl;
	salida << p1.y << endl;

	salida << p2.x << endl;
	salida << p2.y << endl;
}

void cLinea::Cargar(ifstream &entrada)
{
	/*
	entrada >> p1.x;
	entrada >> p1.y;

	entrada >> p2.x;
	entrada >> p2.y;
	*/
	string str;
	getline(entrada, str);
	p1.x = stof(str);
	getline(entrada, str);
	p1.y = stof(str);

	getline(entrada, str);
	p2.x = stof(str);
	getline(entrada, str);
	p2.y = stof(str);
}

string cLinea::info() {
	return "lu";
}